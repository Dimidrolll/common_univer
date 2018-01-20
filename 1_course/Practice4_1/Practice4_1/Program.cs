using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Practice4_1
{
    
    class faculty
    {
        public string name;
        public int year;
        public int persons;
        public int cost;
        public faculty(string name , int year , int persons , int cost)
        {
            this.name = name;
            this.year = year;
            this.persons = persons;
            this.cost = cost;
        }
        public void inf()
        {
            Console.WriteLine("Название факультета: " + name + ". Год основания: " + year + ". Количество учащихся: " + persons + ". Стоимость обучения " + cost);
        }
        

    }

    
    

    class Program
    {
        public static void Main()
        {
            const int n = 5;
            faculty[] fac = new faculty[n];
            fac[0] = new faculty("Физический", 1959, 314, 25000);
            fac[1] = new faculty("Юридический", 2002, 146, 100000);
            fac[2] = new faculty("МехМат", 1234, 999, 30000);
            fac[3] = new faculty("Психопатологический", 666, 10, 20000);
            fac[4] = new faculty("Деревянный", 2018, 0, 10000);


            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += fac[i].cost;
            double sr = sum / n;
            Console.WriteLine("Средняя стоимость: " + sr);
            for (int i = 0; i < n; ++i)
                if (fac[i].cost <= sr && fac[i].year <= 2000)
                    fac[i].inf();
            Console.WriteLine();
            Console.ReadKey();
        }
    }
}

