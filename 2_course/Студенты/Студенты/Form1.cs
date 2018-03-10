using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace Студенты
{
    public partial class Form1 : Form
    {
        public List<Student> students = new List<Student>();
        public ListIterator iter;

        public Form1()
        {
            InitializeComponent();
            iter = new ListIterator(students);
            comboBox1.SelectedIndex = 0;
        }

        private void открытьСписокToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;

            using (FileStream fs = new FileStream(openFileDialog1.FileName, FileMode.OpenOrCreate))
            {
                XmlSerializer xs = new XmlSerializer(typeof(List<Student>));
                try
                {
                    students = (List<Student>) xs.Deserialize(fs);
                    iter = new ListIterator(students);
                    if (iter.HasNext())
                    {
                        iter.Next();
                    }
                    Blocked();
                    ShowSt();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
        }

        private void сохранитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;
            Change();
            XmlSerializer xs = new XmlSerializer(typeof(List<Student>));

            using (StreamWriter sw = new StreamWriter(saveFileDialog1.FileName))
            {
                xs.Serialize(sw, students);
            }
        }

        private void добавитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            iter.Add(new Student());

            Change();
            ShowSt();
            Blocked();
        }

        private void добавитьКотаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            iter.Add(new StudentCat());
            
            Change();
            ShowSt();
            Blocked();
        }

        private void удалитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            iter.Remove();
            ShowSt();
            Blocked();
        }

        private void Blocked()
        {
            if (iter.IsEmpty())
            {
                удалитьToolStripMenuItem.Enabled = false;
                surnameText.Enabled = false;
                nameText.Enabled = false;
                facText.Enabled = false;
                foodText.Enabled = false;
                searchText.Enabled = false;
                prevBut.Enabled = false;
                nextBut.Enabled = false;
                предыдущийToolStripMenuItem.Enabled = false;
                следующийToolStripMenuItem.Enabled = false;
                comboBox1.Enabled = false;
            }
            else
            {
                удалитьToolStripMenuItem.Enabled = true;
                surnameText.Enabled = true;
                nameText.Enabled = true;
                facText.Enabled = true;
                searchText.Enabled = true;
                prevBut.Enabled = true;
                nextBut.Enabled = true;
                предыдущийToolStripMenuItem.Enabled = true;
                следующийToolStripMenuItem.Enabled = true;
                comboBox1.Enabled = true;
                foodText.Enabled = iter.Current.GetType() == typeof(StudentCat);
            }

            
            предыдущийToolStripMenuItem.Enabled = iter.HasPrevious();
            prevBut.Enabled = iter.HasPrevious();

            следующийToolStripMenuItem.Enabled = iter.HasNext();
            nextBut.Enabled = iter.HasNext();
        }

        private void ShowSt()
        {
            if (!iter.IsEmpty())
            {
                surnameText.Text = iter.Current.Surname;
                nameText.Text = iter.Current.Name;
                facText.Text = iter.Current.Faculty;
                if (iter.Current is StudentCat)
                {
                    foodText.Text = ((StudentCat) iter.Current).Food;
                }
                else
                {
                    foodText.Text = "";
                }
            }
            else
            {
                surnameText.Text = "";
                nameText.Text = "";
                facText.Text = "";
                foodText.Text = "";
            }
        }

        private void Change()
        {
            iter.Current.Surname = surnameText.Text;
            iter.Current.Name = nameText.Text;
            iter.Current.Faculty = facText.Text;
            if (iter.Current.GetType() == typeof(StudentCat))
            {
                ((StudentCat)iter.Current).Food = foodText.Text;
            }
        }

        private void предыдущийToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Change();
            iter.Previous();
            ShowSt();
            Blocked();
        }

        private void следующийToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Change();
            iter.Next();
            ShowSt();
            Blocked();
        }

        private void prevBut_Click(object sender, EventArgs e)
        {
            предыдущийToolStripMenuItem_Click(sender, e);
        }

        private void nextBut_Click(object sender, EventArgs e)
        {
            следующийToolStripMenuItem_Click(sender,e);
        }

        private void Search()
        {
            ListIterator copyIter = iter.Copy();
            while (copyIter.HasNext())
            {
                Student student = copyIter.Next();
                foreach (var property in student.GetType().GetProperties())
                {
                    if (comboBox1.SelectedItem.ToString() == "Фамилия" && property.Name == "Surname")
                    {
                        if (searchText.Text == student.Surname)
                        {
                            iter = copyIter;
                            ShowSt();
                            Blocked();
                            return;
                        }
                    }

                    if (comboBox1.SelectedItem.ToString() == "Имя" && property.Name == "Name")
                    {
                        if (searchText.Text == student.Name)
                        {
                            iter = copyIter;
                            ShowSt();
                            Blocked();
                            return;
                        }
                    }

                    if (comboBox1.SelectedItem.ToString() == "Факультет" && property.Name == "Faculty")
                    {
                        if (searchText.Text == student.Faculty)
                        {
                            iter = copyIter;
                            ShowSt();
                            Blocked();
                            return;
                        }
                    }

                    if (comboBox1.SelectedItem.ToString() == "Еда" && property.Name == "Food")
                    {
                        if (searchText.Text == ((StudentCat) student).Food)
                        {
                            iter = copyIter;
                            ShowSt();
                            Blocked();
                            return;
                        }
                    }


                }

         
            } 


        }

        private void searchText_TextChanged(object sender, EventArgs e)
        {
            Search();

        }

        private void comboBox1_SelectedValueChanged(object sender, EventArgs e)
        {
            Search();
        }
    }

    [Serializable]
    [XmlInclude(typeof(StudentCat))]
    public class Student
    {
        public string Surname { get; set; }
        public string Name { get; set; }
        public string Faculty { get; set; }

        public Student()
        {
            Surname = "";
            Name = "";
            Faculty = "";
        }

    }

    public class StudentCat : Student
    {
        public string Food { get; set; }

        public StudentCat()
        {
            Surname = "";
            Name = "";
            Faculty = "";
            Food = "";
        }
    }
}