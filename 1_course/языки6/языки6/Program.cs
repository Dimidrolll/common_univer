using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace языки6
{
    class OldEntry
    {
        protected string surname;
        protected string name;
        protected string fathname;
        protected int day;
        protected int month;
        protected int year;

        public string Surname { get { return surname; } }
        public string Name { get { return name; } }
        public string Fathname { get { return fathname; } }
        public int Day { get { return day; } }
        public int Month { get { return month; } }
        public int Year { get { return year; } }

        public OldEntry(string surname , string name , string fathname , int day , int month , int year)
        {
            this.surname = surname;
            this.name = name;
            this.fathname = fathname;
            this.day = day;
            this.month = month;
            this.year = year;
        }

        public virtual void info()//полиморфизм
        {
            Console.WriteLine("Имя покупателя: " + surname + ' ' + name + ' ' + fathname + ". Дата рождения: " + day + '.' + month + '.' + year);
        }
    }

    class NewEntry : OldEntry
    {
        int phone;
        public int Phone { get { return phone; } }
        public NewEntry(string surname , string name , string fathname , int day , int month , int year , int phone)
            : base(surname , name , fathname , day , month , year)
        { this.phone = phone; }
        public override void info()
        {
            base.info();
            Console.WriteLine("Номер телефона покупателя: " + phone);
        }
    }

    class Program
    {
        public static void Main()
        {
            int i;
            List<OldEntry> shoppers = new List<OldEntry>();
            StreamReader f;
            string s , s1;
            string[] s_arr = new string[20];
            //чтение из файла 
            try { f = new StreamReader("C:\\Users\\acer\\Documents\\Visual Studio 2010\\Projects\\языки6\\языки6\\bin\\Release\\input.txt" , Encoding.Default); }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Console.WriteLine("Проверьте наличие файла!");
                return;
            }
            int q1 , q2 , q3, q4;
            int n1 = 0, n2 = 0, w = 0;
            while ((s = f.ReadLine()) != null)
            {
                s_arr[0] = s.Split(' ')[0];
                if (s_arr[0] == "nophone")//обозначение отсутсвия телефона
                {
                    
                    s_arr[1] = s.Split(' ')[1];
                    s_arr[2] = s.Split(' ')[2];
                    s_arr[3] = s.Split(' ')[3];
                    s_arr[4] = s.Split(' ')[4];
                    s_arr[5] = s.Split(' ')[5];
                    s_arr[6] = s.Split(' ')[6];

                    q1 = Convert.ToInt32(s_arr[4]);
                    q2 = Convert.ToInt32(s_arr[5]);
                    q3 = Convert.ToInt32(s_arr[6]);
                    shoppers.Add(new OldEntry(s_arr[1] , s_arr[2] , s_arr[3] , q1 , q2 , q3));
                    ++n1;
                }
                else
                {
                    s_arr[0] = s.Split(' ')[0];
                    s_arr[1] = s.Split(' ')[1];
                    s_arr[2] = s.Split(' ')[2];
                    s_arr[3] = s.Split(' ')[3];
                    s_arr[4] = s.Split(' ')[4];
                    s_arr[5] = s.Split(' ')[5];
                    s_arr[6] = s.Split(' ')[6];

                    q1 = Convert.ToInt32(s_arr[3]);
                    q2 = Convert.ToInt32(s_arr[4]);
                    q3 = Convert.ToInt32(s_arr[5]);
                    q4 = Convert.ToInt32(s_arr[6]);
                    shoppers.Add(new NewEntry(s_arr[0] , s_arr[1] , s_arr[2] , q1 , q2 , q3 , q4));
                    ++n2;
                }
                ++w;
            }
            f.Close();
      
            Console.WriteLine("Информация о всех записях магазина: ");
            for (i = 0; i < w; ++i)
            {
                shoppers[i].info();
                Console.WriteLine();
            }
            Console.WriteLine();
            Console.WriteLine("Введите фамилию, имя и отчество покупателя через пробел. "); //поиск номера телефона
            s1 = Console.ReadLine();
            for (i = 0; i < w; ++i)
                if (shoppers[i] is NewEntry)
                {
                    NewEntry x = new NewEntry("" , "" , "" , 0 , 0 , 0 , 0);
                    x = (NewEntry)shoppers[i];
                    s_arr[0] = s1.Split(' ')[0];
                    s_arr[1] = s1.Split(' ')[1];
                    s_arr[2] = s1.Split(' ')[2];
                    if ((x.Surname == s_arr[0]) && (x.Name == s_arr[1]) && (x.Fathname == s_arr[2]))
                    {
                        Console.WriteLine("Номер телефона покупателя " + s1 + ": " + x.Phone);
                        break;
                    }
                    else
                    {
                        Console.WriteLine("Покупатель не оставил свой номер телефона или такого покупателя не зарегистрировано.");
                        break;
                    }
                }
            Console.WriteLine();
            Console.WriteLine("Новые записи: ");
            Console.WriteLine();
            for (i = 0; i < w; ++i)
                if (shoppers[i] is NewEntry)
                {
                    shoppers[i].info();
                    Console.WriteLine();
                }
            Console.WriteLine("В магазине " + n1 + " старых записей и " + n2 + " новых записей.");
            Console.ReadKey(); 
        }
    }
}