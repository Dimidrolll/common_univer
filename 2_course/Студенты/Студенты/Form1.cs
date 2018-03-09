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
        public int curSt = -1;
        public Form1()
        {
            InitializeComponent();
            //Blocked();
        }

        private void открытьСписокToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;

            using (FileStream fs = new FileStream(openFileDialog1.FileName, FileMode.OpenOrCreate))
            {

                XmlSerializer formatter = new XmlSerializer(typeof(List<Student>));
                students = (List<Student>)formatter.Deserialize(fs);
                if (students.Count != 0)
                {
                    curSt = 0;
                }
                Blocked();
                if (curSt != -1)
                {
                    ShowSt();
                }
            }
        }
        private void сохранитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;

            XmlSerializer formatter = new XmlSerializer(typeof(List<Student>));

            using (FileStream fs = new FileStream(saveFileDialog1.FileName, FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, students);
            }
        }

        private void добавитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            students.Add(new Student() { Surname = "", Name = "", Faculty = "" });
            if (curSt == -1)
            {
                ++curSt;
            }
            Change();
            ShowSt();
            Blocked();
        }
        private void удалитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            students.Remove(students[curSt]);
            if (curSt == students.Count) --curSt;
            ShowSt();
            Blocked();
        }

        private void Blocked()
        {
            //if (students == null)
                //return;
            if (curSt == -1)
            {
                удалитьToolStripMenuItem.Enabled = false;
                surnameText.Enabled = false;
                nameText.Enabled = false;
                facText.Enabled = false;
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
            }

            if (curSt == 0 || curSt == -1)
            {
                предыдущийToolStripMenuItem.Enabled = false;
                prevBut.Enabled = false;
            }
            else
            {
                предыдущийToolStripMenuItem.Enabled = true;
                prevBut.Enabled = true;
            }
            if (curSt == students.Count - 1)
            {
                следующийToolStripMenuItem.Enabled = false;
                nextBut.Enabled = false;
            }
            else
            {
                следующийToolStripMenuItem.Enabled = true;
                nextBut.Enabled = true;
            }
        }

        private void ShowSt()
        {
            if (curSt != -1)
            {
                surnameText.Text = students[curSt].Surname;
                nameText.Text = students[curSt].Name;
                facText.Text = students[curSt].Faculty; 
            }
            else
            {
                surnameText.Text = "";
                nameText.Text = "";
                facText.Text = "";
            }
        }

        private void Change()
        {
            students[curSt].Surname = surnameText.Text;
            students[curSt].Name = nameText.Text;
            students[curSt].Faculty = facText.Text;
        }

        private void предыдущийToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Change();
            --curSt;
            ShowSt();
            Blocked();
        }

        private void следующийToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Change();
            ++curSt;
            ShowSt();
            Blocked();
        }

        private void prevBut_Click(object sender, EventArgs e)
        {
            Change();
            --curSt;
            ShowSt();
            Blocked();
        }

        private void nextBut_Click(object sender, EventArgs e)
        {
            Change();
            ++curSt;
            ShowSt();
            Blocked();
        }

        
    }

    [Serializable]
    public class Student
    {
        public string Surname { get; set; }
        public string Name { get; set; }
        public string Faculty { get; set; }

        public Student()
        {
        }
    }
}
