using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Serialization.Formatters.Binary;
namespace ConsoleApplication1
{
    [Serializable]
    class prop_prep 
    {
        protected string surname;
        protected string name;
        protected string otch;
        protected string fac;
        string caf;
        public string Surname { get { return surname; } }
        public string Name { get { return name; } }
        public string Otch { get { return otch; } }
        public string Fac { get { return fac; } }
        public string Caf { get { return caf; } }
        public prop_prep(string surname , string name , string otch , string fac , string caf) {
            this.surname = surname;
            this.name = name;
            this.otch = otch;
            this.fac = fac;
            this.caf = caf;
        }
        public prop_prep(string surname , string name , string otch , string fac)
        {
            this.surname = surname;
            this.name = name;
            this.otch = otch;
            this.fac = fac;
        }
        public virtual void show() {
            Console.WriteLine("Prep " + surname + ", caf " + caf);
        }
    }
    [Serializable]
    class prop_stud : prop_prep
    { 
        int year; 
        public int Year { get { return year; } }
        public prop_stud(string surname , string name , string otch , string fac , int year):
            base(surname , name , otch , fac)
        {
            this.year = year;
        }
        public override void show()
        {
            Console.WriteLine("Stud " + surname + ", year " + year);
        }
    }
    class Program
    {
        static void Main()
        {
            const int n = 5;
            prop_prep[] register = new prop_prep[n];
            StreamReader f;
            string[] s = new string[6];
            string str;
            try
            {
                f = new StreamReader("C:\\Users\\acer\\Desktop\\input1.txt");
            }
            catch (Exception e)
            {
                Console.WriteLine();
                return;
            }
            int i = 0;
            while ((str = f.ReadLine()) != null)
            {
                s = str.Split(' ');

                if (s[0] == "0")
                    register[i] = new prop_prep(s[1] , s[2] , s[3] , s[4] , s[5]);
                else
                    register[i] = new prop_stud(s[1] , s[2] , s[3] , s[4] , int.Parse(s[5]));
                ++i;
            }
            f.Close();
            BinaryFormatter format = new BinaryFormatter();
            FileStream fs = new FileStream("a.dat" , FileMode.Create , FileAccess.Write);
            format.Serialize(fs,register);
            fs.Close();
            Console.ReadKey();
        }
    }
}
