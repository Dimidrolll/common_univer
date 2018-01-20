using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
namespace языки4
{
    class newspaper
    {
        string name; //название
        int persons; //количество сотрудников
        int tirag;
        string val;

        public string Name { get { return name; } }
        public int Persons { get { return persons; } }

        public newspaper(string name , int persons , int tirag, string val)//конструктор
        {
            this.name = name;
            this.persons = persons;
            this.tirag = tirag;
            this.val = val;
        }
    

        public void Show()
        {
            Console.WriteLine("В редакции газеты " + name + " трудятся " + persons + " сотрудников. Тираж: " + tirag);
            Console.WriteLine("В этой газете пишут " + val);
        }

        
    }

    class Program
    {
        
        public static void new_state(ref newspaper z)
        {
           
        }

        public static void Main()
        {
            Console.WriteLine("Введите название, количество сотрудников и тираж: ");
            Company comp1 = new Company(Console.ReadLine() , int.Parse(Console.ReadLine()) , int.Parse(Console.ReadLine()));
           
            Console.WriteLine("Средняя зарплата рабочих: " + comp1.AverageSalary());
            Console.WriteLine("В этой компании может работать максимум " + comp1.MaxPersons(10000) + " человек со средней зарплатой 10000.");
            new_state(ref comp1);
            if (comp1 == null)
                Console.WriteLine("Компания закрыта.");
            else
                comp1.Show();
            Console.ReadKey();
        }
        
    }
}