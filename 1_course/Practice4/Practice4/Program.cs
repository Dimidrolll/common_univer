using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Practice4
{
    class Person
    {
        protected string name;
        public string surname;
        protected int age;
        public string sex;
        public Person(string name , string surname , int age , string sex)
        {
            this.name = name;
            this.surname = surname;
            this.age = age;
            this.sex = sex;
        }
        public void inf()
        {
            Console.WriteLine("Имя " + name + ", фамилия " + surname + ", возраст " + age + ", пол " + sex);
        }
        public int getSex()
        {
            if (sex == "ж")
                return 1;
            else
                return 0;
        }
    }

    class Employee : Person
    {
        public string company;
        public string position;
        public int salary;
        public Employee(string name , string surname , int age , string sex , string company , string position , int salary)
            : base(name , surname , age , sex)
        {
            this.company = company;
            this.position = position;
            this.salary = salary;
        }
        public void inf()
        {
            base.inf();
            Console.WriteLine("Название компании, в которой данный человек работает - " + company + "; должность, которую занимает он - " + position + "; его оклад - " + salary + ".");
        }
    }

    class Program
    {
        public static void Main()
        {
            const int n = 5;
            Person[] Pers = new Person[n];
            Employee[] Empl = new Employee[n];

            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("Введите имя, фамилию, возраст, пол, название компании, должность, оклад человека №" + (i + 1) + " : ");
                Empl[i] = new Employee(Console.ReadLine() , Console.ReadLine() , int.Parse(Console.ReadLine()) , Console.ReadLine() , Console.ReadLine() , Console.ReadLine() , int.Parse(Console.ReadLine()));
                Console.WriteLine();
            }

            for (int i = 0; i < n; i++)
                Empl[i].inf();

            Console.WriteLine();
            string s;
            Console.WriteLine("Введите название компании: ");
            s = Console.ReadLine();
            Console.WriteLine("Отсортированный список: ");
            for (int i = 0; i < n; i++)
                if (Empl[i].getSex() == 1 && Empl[i].company == s)
                    //Empl[i].inf();
                    Console.WriteLine(Empl[i].company + ' ' + Empl[i].surname + ' ' + Empl[i].sex);
            for (int i = 0; i < n; i++)
                if (Empl[i].getSex() == 0 && Empl[i].company == s)
                    //Empl[i].inf();
                    Console.WriteLine(Empl[i].company + ' ' + Empl[i].surname + ' ' + Empl[i].sex);
            Console.WriteLine();
            Console.ReadKey();
        }
    }
}
