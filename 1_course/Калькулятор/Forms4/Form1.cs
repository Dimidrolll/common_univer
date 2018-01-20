using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        bool p = true; bool m = true; bool u = true; bool d = true; bool l = true;
        string left = "" , right = ""; bool znak;

        private void textBox1_TextChanged(object sender , EventArgs e)
        {
            
        }

        private void button1_Click_1(object sender , EventArgs e)
        {
            textBox1.Text = textBox1.Text + "1";
            if (!p || !m || !u || !d)
                right += "1";
            znak = true;
        }

        private void button2_Click_1(object sender , EventArgs e)
        {
            
            textBox1.Text += "2";
            if (!p || !m || !u || !d)
                right += "2";
            znak = true;
        
        }

        private void button3_Click_1(object sender , EventArgs e)
        {
             
            textBox1.Text += "3";
            if (!p || !m || !u || !d)
                right += "3";
            znak = true;
        
        }

        private void button4_Click_1(object sender , EventArgs e)
        {
            textBox1.Text += "4";
            if (!p || !m || !u || !d)
                right += "4";
            znak = true;
        }

        private void button5_Click_1(object sender , EventArgs e)
        {
            textBox1.Text += "5";
            if (!p || !m || !u || !d)
                right += "5";
            znak = true;
        
        }

        private void button6_Click_1(object sender , EventArgs e)
        {

            textBox1.Text += "6";
            if (!p || !m || !u || !d)
                right += "6";
            znak = true;
        
        }

        private void button7_Click_1(object sender , EventArgs e)
        {
             
            textBox1.Text += "7";
            if (!p || !m || !u || !d)
                right += "7";
        znak = true;
        }

        private void button8_Click_1(object sender , EventArgs e)
        {
            
            textBox1.Text += "8";
            if (!p || !m || !u || !d)
                right += "8";
        znak = true;
        }

        private void buttonE_Click_1(object sender , EventArgs e)
        {
            
            double rl = 0 , rr = 0 , rrr = 0;
            textBox1.Text = "";
            rl = double.Parse(left);
            rr = double.Parse(right);
            if (!p)
            {
                rrr = rl + rr;
                textBox1.Text = Convert.ToString(rrr);
                left = "";
                right = "";
                p = true;
            }
            if (!m)
            {
                rrr = rl - rr;
                textBox1.Text = Convert.ToString(rrr);
                left = "";
                right = "";
                m = true;
            }
            if (!u)
            {
                rrr = rl * rr;
                textBox1.Text = Convert.ToString(rrr);
                left = "";
                right = "";
                u = true;
            }
            if (!d)
            {
                rrr = rl / rr;
                textBox1.Text = Convert.ToString(rrr);
                left = "";
                right = "";
                d = true;
            }
        
        }

        private void button9_Click_1(object sender , EventArgs e)
        {
            
            textBox1.Text += "9";
            if (!p || !m || !u || !d)
                right += "9";
        znak = true;
        }

        private void button0_Click_1(object sender , EventArgs e)
        {
            
            textBox1.Text += "0";
            if (!p || !m || !u || !d)
                right += "0";
        znak = true;
        }

        private void buttonC_Click_1(object sender , EventArgs e)
        {
            textBox1.Text = "";
        
        }

        private void buttonT_Click_1(object sender , EventArgs e)
        {
           
            if (l == true)
            {
                textBox1.Text += ",";
                if (!p || !m || !u || !d)
                    right += ",";
                l = false;
            }
        
        }

        private void buttonPM_Click_1(object sender , EventArgs e)
        {
             
            if(znak==true)
            {
                textBox1.Text = "-" + textBox1.Text;
                znak = false;
            }
            else if (znak==false)
            {
                textBox1.Text=textBox1.Text.Replace("-", "");
                znak = true;
        }

        
        }

        private void buttonP_Click_1(object sender , EventArgs e)
        {
             
            left = textBox1.Text;
            textBox1.Text += "+";
            p = false;
            l = true;
        
        }

        private void buttonM_Click_1(object sender , EventArgs e)
        {
            
            left = textBox1.Text;
            textBox1.Text += "-";
            m = false;
            l = true;
        
        }

        private void buttonU_Click_1(object sender , EventArgs e)
        {
            
            left = textBox1.Text;
            textBox1.Text += "*";
            u = false;
            l = true;
        
        }

        private void buttonD_Click_1(object sender , EventArgs e)
        {
            
            left = textBox1.Text;
            textBox1.Text += "/";
            d = false;
            l = true;
        
        }

        private void button17_Click(object sender , EventArgs e)
        {
            int lenght = textBox1.Text.Length - 1;
            string text = textBox1.Text;
            textBox1.Clear();
            for (int i = 0; i < lenght; i++)
            {
                textBox1.Text = textBox1.Text + text[i];
            }
        }

    }
}
