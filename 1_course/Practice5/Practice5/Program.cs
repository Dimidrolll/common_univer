using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace Practice5
{

    class buyer
    {
        public string surname;
        public int number;
        public string date;
        public string mark;
        public string color;
        public int cost;

        public buyer(string surname , int number , string date , string mark , string color , int cost)
        {
            this.surname = surname;
            this.date = date;
            this.mark = mark;
            this.color = color;
            this.number = number;
            this.cost = cost;
        }

        public void inf()
        {
            Console.WriteLine("Фамилия: " + surname + ". Номер удостоверения: " + number + ". Дата рожения: " + date);
            Console.WriteLine("Марка авто: " + mark + ". Цвет машины: " + color + ". Стоимость : " + cost);
        }
        public double aver_cost(buyer[] persons , int n)
        {
            int sum = 0;
            for (int i = 0; i < n; ++i)
                sum += persons[i].cost;
            return sum / n;

        }
    }





    class Program
    {
        static void Main()
        {
            const int n = 10;
            buyer[] persons = new buyer[n];
            buyer t = new buyer("" , 0, "" , "" , "" , 0);
            

            StreamReader f;
            string s;
            int x , y , i = 0;

            string[] strf = new string[6];
            try
            {
                f = new StreamReader("C:\\Users\\acer\\Documents\\Visual Studio 2010\\Projects\\Practice5\\Practice5\\input.txt");
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Console.WriteLine("Проверьте  имя файла");
                return;
            }
            while ((s = f.ReadLine()) != null)
            {
                Console.WriteLine(s);
                strf[0] = s.Split(' ')[0];
                strf[1] = s.Split(' ')[1];
                strf[2] = s.Split(' ')[2];
                strf[3] = s.Split(' ')[3];
                strf[4] = s.Split(' ')[4];
                strf[5] = s.Split(' ')[5];

                x = Convert.ToInt32(strf[1]); y = Convert.ToInt32(strf[5]);
                persons[i] = new buyer(strf[0] , x , strf[2] , strf[3] , strf[4] , y);
                ++i;
            }
            f.Close();
            persons[1].inf();
            double q;
            int max = 0 , min = 99999 , maxim = 0 , minim = 0;
            q = persons[0].aver_cost(persons , n);
            for (i = 0; i < n; ++i)
            {
                if (max < persons[i].cost)
                {
                    max = persons[i].cost;
                    maxim = i;
                }
                if (min > persons[i].cost)
                {
                    min = persons[i].cost;
                    minim = i;
                }
            }
            StreamWriter f1 = new StreamWriter("C:\\Users\\acer\\Documents\\Visual Studio 2010\\Projects\\Practice5\\Practice5\\output.txt");
            f1.WriteLine(q);
            f1.WriteLine(persons[maxim].surname + ' ' + persons[maxim].number);
            f1.WriteLine(persons[minim].surname + ' ' + persons[minim].number);
            f1.Close();

            Console.WriteLine("Владельцев какой марки сортируем?");
            s = Console.ReadLine();
            for (i = 0; i < n; i++)
            {
                for (int j = 0; j < 9 - i; j++)
                    if (persons[j].cost > persons[j + 1].cost)
                    {
                        t = persons[j];
                        persons[j] = persons[j + 1];
                        persons[j + 1] = t;
                    }
            }
            for (i = 0; i < n; ++i){
                if (persons[i].mark == s)
                    persons[i].inf();

            }


            Console.ReadKey();
        }
    }
}
