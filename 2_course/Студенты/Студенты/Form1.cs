using System;
using System.Collections;
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
using Студенты.model;

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

            HashSet<Item> hashSet = new HashSet<Item>(Item.ValueComparer);

            addProperties(hashSet, typeof(Student));
            addProperties(hashSet, typeof(StudentCat));

            foreach (var item in hashSet)
            {
                comboBox1.Items.Add(item);
            }

            
            comboBox1.SelectedIndex = 0;
        }

        private void addProperties(HashSet<Item> hashSet, Type type)
        {
            foreach (var propertyInfo in type.GetProperties())
            {
                var attributes = propertyInfo.GetCustomAttributes(typeof(RusName), true);
                foreach (var attribute in attributes)
                {
                    var rusName = attribute as RusName;
                    if (rusName != null)
                    {
                        var item = new Item { Name = rusName.GetRusName(), Value = propertyInfo.Name };
                        hashSet.Add(item);
                    }
                }
            }
        }

        class Item
        {
            public string Name { get; set; }
            public string Value { get; set; }

            private sealed class ValueEqualityComparer : IEqualityComparer<Item>
            {
                public bool Equals(Item x, Item y)
                {
                    if (ReferenceEquals(x, y)) return true;
                    if (ReferenceEquals(x, null)) return false;
                    if (ReferenceEquals(y, null)) return false;
                    if (x.GetType() != y.GetType()) return false;
                    return string.Equals(x.Value, y.Value);
                }

                public int GetHashCode(Item obj)
                {
                    return (obj.Value != null ? obj.Value.GetHashCode() : 0);
                }
            }

            public static IEqualityComparer<Item> ValueComparer { get; } = new ValueEqualityComparer();
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
            var filterItem = comboBox1.SelectedItem as Item;
            if (filterItem == null)
            {
                return;
            }

            ListIterator copyIter = iter.Copy();
            while (copyIter.HasNext())
            {
                Student student = copyIter.Next();
                var propertyToSearchIn = student.GetType().GetProperty(filterItem.Value);
                if (propertyToSearchIn == null)
                {
                    continue;
                }
                string value = propertyToSearchIn.GetValue(student) as string;
                if (searchText.Text == value)
                {
                    iter = copyIter;
                    ShowSt();
                    Blocked();
                    return;
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

    

    
}