using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private bool sum = false, mult = false, power = false, dif = false, div = false;

        private void equals()
        {
            if (prevNumber.Text == "")
            {
                prevNumber.Text = textBox1.Text;
            }
            else
            {
                
                if (sum)
                {
                    prevNumber.Text = (double.Parse(textBox1.Text) + double.Parse(prevNumber.Text)).ToString();
                }
                if (dif)
                {
                    prevNumber.Text = (double.Parse(prevNumber.Text) - double.Parse(textBox1.Text)).ToString();
                }
                if (mult)
                {
                    prevNumber.Text = (double.Parse(textBox1.Text) * double.Parse(prevNumber.Text)).ToString();
                }

                if (div)
                {
                    try
                    {
                        if (double.Parse(textBox1.Text) == 0)
                        {
                            throw new DivideByZeroException(); //опа, на 0 делим; 1111111111111111111
                        }
                        prevNumber.Text = (double.Parse(prevNumber.Text) / double.Parse(textBox1.Text)).ToString();
                    }
                    catch (DivideByZeroException e)
                    {
                        MessageBox.Show(e.Message);
                    }

                }

                if (power)
                {
                    try
                    {
                        double t = Math.Pow(double.Parse(prevNumber.Text), double.Parse(textBox1.Text));
                        prevNumber.Text = t.ToString();
                    }
                    catch (OverflowException e)//мало ли переполнится (нет, это же дабл) 2222222222222222222222222222222222
                    {
                        MessageBox.Show(e.Message);
                    }
                    
                }
                sum = dif = div = mult = power = false;
            }
        }

        private bool check()
        {
            double value;
            if (double.TryParse(textBox1.Text, out value))//число ли?
            {
                return true;
            }
            MessageBox.Show("Not a number!");
            return false;
        }

        private void fill(int x)
        {

            if (textBox1.Text == "0")
            {
                textBox1.Text = Convert.ToString(x);
            }
            else
            {
                try
                {
                    if (textBox1.Text.Length > 19)//ограничим размер вводимых чисел
                    {
                        throw new ArgumentOutOfRangeException("Длина строки больше 19 символов. NINADA TAK");
                    }
                    textBox1.Text += x;
                }
                catch (ArgumentOutOfRangeException e)//33333333333333333333333333333333333333333
                {
                    MessageBox.Show(e.ParamName);
                }
                
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {   
            fill(1);
        }


        private void button2_Click(object sender, EventArgs e)
        {
            fill(2);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            fill(3);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            fill(4);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            fill(5);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            fill(6);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            fill(7);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            fill(8);
        }

        private void button9_Click(object sender, EventArgs e)
        { 
            fill(9);
        }

        private void button0_Click(object sender, EventArgs e)
        {

            if (textBox1.Text != "0")
            {
                fill(0); 
            }
        }

        private void comma_Click(object sender, EventArgs e)
        {
            try
            {
                if (textBox1.Text.Length > 19)
                {
                    throw new ArgumentOutOfRangeException("Длина строки больше 19 символов. NINADA TAK");
                }
                textBox1.Text += ",";
            }
            catch (ArgumentOutOfRangeException ex)//555555555555555555555555555555555555555
            {
                MessageBox.Show(ex.ParamName);
            }
            
        }

        private void multiply_Click(object sender, EventArgs e)
        {
            if (check())
            {
                try
                {
                    if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                        throw new NotFiniteNumberException();
                    equals();
                    mult = true;
                    textBox1.Text = "0";
                }
                catch (NotFiniteNumberException exception)
                {
                    MessageBox.Show(exception.Message);
                }
            }
        }

        private void division_Click(object sender, EventArgs e)
        {
            if (check())
            {
                try
                {
                    if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                        throw new NotFiniteNumberException();
                    equals();
                    div = true;
                    textBox1.Text = "0";
                }
                catch (NotFiniteNumberException exception)
                {
                    MessageBox.Show(exception.Message);
                }
            }
        }

        private void plus_Click(object sender, EventArgs e)
        {
            if (check())
            {
                try
                {
                    if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                        throw new NotFiniteNumberException();
                    equals();
                    sum = true;
                    textBox1.Text = "0";
                }
                catch (NotFiniteNumberException exception)
                {
                    MessageBox.Show(exception.Message);
                }
            }
        }

        private void minus_Click(object sender, EventArgs e)
        {
            if (check())
            {
                try
                {
                    if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                        throw new NotFiniteNumberException();
                    equals();
                    dif = true;
                    textBox1.Text = "0";
                }
                catch (NotFiniteNumberException exception)
                {
                    MessageBox.Show(exception.Message);
                }
            }
        }

        private void equal_Click(object sender, EventArgs e)
        {
            if (check())
            {

                try
                {
                    if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                        throw new NotFiniteNumberException();

                    if (sum)
                    {
                        textBox1.Text = (double.Parse(textBox1.Text) + double.Parse(prevNumber.Text)).ToString();
                    }
                    if (dif)
                    {
                        textBox1.Text = (double.Parse(prevNumber.Text) - double.Parse(textBox1.Text)).ToString();
                    }
                    if (mult)
                    {
                        textBox1.Text = (double.Parse(textBox1.Text) * double.Parse(prevNumber.Text)).ToString();
                    }

                    if (div)
                    {
                        try
                        {
                            if (double.Parse(textBox1.Text) == 0)
                            {
                                throw new DivideByZeroException();//опа, деление на нуль 1111111111111111111111111
                            }
                            textBox1.Text = (double.Parse(prevNumber.Text) / double.Parse(textBox1.Text)).ToString();
                        }
                        catch (DivideByZeroException ex)
                        {
                            MessageBox.Show(ex.Message);                            
                        }

                    }
                    if (power)
                    {
                        textBox1.Text = Math.Pow(double.Parse(prevNumber.Text), double.Parse(textBox1.Text)).ToString();
                    }
                    sum = dif = div = mult = power = false;
                    prevNumber.Text = "";
                }
                catch (NotFiniteNumberException exception)
                {
                    MessageBox.Show(exception.Message);
                }
            }
        }

        private void sin_Click(object sender, EventArgs e)
        {
            if (check())
            {
                try
                {
                    if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                        throw new NotFiniteNumberException();
                    textBox1.Text = Math.Sin(double.Parse(textBox1.Text)).ToString();
                }
                catch (NotFiniteNumberException exception)
                {
                    MessageBox.Show(exception.Message);
                }
                
            }
        }

        private void cos_Click(object sender, EventArgs e)
        {
            if (check())
            {
                try
                {
                    if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                        throw new NotFiniteNumberException();
                    textBox1.Text = Math.Cos(double.Parse(textBox1.Text)).ToString();
                }
                catch (NotFiniteNumberException exception)
                {
                    MessageBox.Show(exception.Message);
                }
                
            }
        }

        private void arcsin_Click(object sender, EventArgs e)
        {
            if (check())
            {
                try
                {
                    if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                        throw new NotFiniteNumberException();
                    textBox1.Text = Math.Asin(double.Parse(textBox1.Text)).ToString();
                }
                catch (NotFiniteNumberException exception)
                {
                    MessageBox.Show(exception.Message);
                }
                
            }
        }

        private void arccos_Click(object sender, EventArgs e)
        {
            if (check())
            {
                try
                {
                    if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                        throw new NotFiniteNumberException();
                    textBox1.Text = Math.Acos(double.Parse(textBox1.Text)).ToString();
                }
                catch (NotFiniteNumberException exception)
                {
                    MessageBox.Show(exception.Message);
                }
                
            }
        }

        private void sqrt_Click(object sender, EventArgs e)
        {
            if (check())
            {
                try
                {
                    if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                        throw new NotFiniteNumberException();
                    textBox1.Text = Math.Sqrt(double.Parse(textBox1.Text)).ToString();
                }
                catch (NotFiniteNumberException exception)
                {
                    MessageBox.Show(exception.Message);
                }
                
            }
        }

        private void pow_Click(object sender, EventArgs e)
        {
            if (check())
            {
                try
                {
                    if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                        throw new NotFiniteNumberException();
                    equals();
                    power = true;
                    textBox1.Text = "0";
                }
                catch (NotFiniteNumberException exception)
                {
                    MessageBox.Show(exception.Message);
                }
            }
        }

        private void log_Click(object sender, EventArgs e)
        {
            if (check())
            {
                try
                {
                    try
                    {
                        if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                            throw new NotFiniteNumberException();
                        textBox1.Text = Math.Log10(double.Parse(textBox1.Text)).ToString();
                    }
                    catch (NotFiniteNumberException notFiniteNumberException)
                    {
                        MessageBox.Show(notFiniteNumberException.Message);
                        throw;
                    }
                    finally
                    {
                        //textBox1.Text = "0";//что-нибудь бесполезное
                    }
                
                }
                catch (Exception exception)
                {
                    MessageBox.Show(exception.StackTrace);
                }
                
                
            }
        }
        ///////////////////////////
        private void notImplement_Click(object sender, EventArgs e)
        {
            try
            {
                pricol_bez_sms_i_registracii();
            }
            catch (NotImplementedException exception) //44444444444444444
            {
                MessageBox.Show(exception.Message);
            }
        }

        private void pricol_bez_sms_i_registracii()
        {
            throw new NotImplementedException();
        }

        ///////////////////////////

        private void sqr_Click(object sender, EventArgs e)
        {
            
            if (check())
            {
                try
                {
                    if (Double.IsInfinity(double.Parse(textBox1.Text)) || Double.IsNaN(double.Parse(textBox1.Text)))
                        throw new NotFiniteNumberException();
                    textBox1.Text = (double.Parse(textBox1.Text) * double.Parse(textBox1.Text)).ToString();
                }
                catch (NotFiniteNumberException exception)
                {
                    MessageBox.Show(exception.Message);
                }
            }
                
            
        }

        private void clear_Click(object sender, EventArgs e)
        {
            textBox1.Text = "0";
            prevNumber.Text = "";
            sum = dif = div = mult = power = false;
        }

        private void del_Click(object sender, EventArgs e)
        {
            try
            {
                Delete();           
            }
            catch (ArgumentOutOfRangeException ex)//раньше был IndexOutOfRangeException //мало ли, вдруг выйдет  55555555555555555555
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Delete()
        {
            try
            {
                textBox1.Text = textBox1.Text.Remove(textBox1.Text.Length - 1);
            }
            finally
            {
                if (textBox1.Text == "")
                    textBox1.Text = "0";
            }
        }

        private void swap_Click(object sender, EventArgs e)
        {
            if (check())
            {
                double x = (-1) * double.Parse(textBox1.Text);
                textBox1.Text = Convert.ToString(x);
            }
        }
    }
}
