using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace языки5
{
    class Student
    {
        protected string name;
        protected int year;
        protected string faculty;
        public Student(string name , int year , string faculty)
        {
            this.name = name;
            this.year = year;
            this.faculty = faculty;
        }

        public string Name { get { return name; } }
        public int Year { get { return year; } }
        public string Faculty { get { return faculty; } }

        public void info_s()
        {
            Console.WriteLine("Студент " + name + " поступил в ВУЗ в " + year + " году" + " на " + faculty + " факультет.");
        }

        public void rating(int score)
        {
            Console.WriteLine("Этот студент имеет " + score + " баллов в рейтинге.");
        }
        
    }
    class Graduate_student : Student//наследование
    {
        string science_men;
        int code;

        public Graduate_student(string name , int year , string faculty , string science_men , int code) : base(name , year , faculty)
        {
            this.science_men = science_men;
            this.code = code;
        }

        public string Science_men { get { return science_men; } }
        public int Code { get { return code; } }

        public void info_g()
        {
            base.info_s();
            Console.WriteLine("Имя руководителя " + science_men + ". Код специальности аспиранта " + code);
        }
    }

    class Program
    {
        public static void Main(string[] args)
        {
            int n, p;
            Console.Write("Введите количество студентов n: ");
            n = int.Parse(Console.ReadLine());
            Student[] stud = new Student[n];
            int[] score = new int[n];
            for (int i = 0; i < n; ++i)
            {
                Console.WriteLine("Введите имя, год поступления, факультет и рейтинг студента №" + (i + 1) + ": ");
                stud[i] = new Student(Console.ReadLine() , int.Parse(Console.ReadLine()) , Console.ReadLine());
                score[i] = int.Parse(Console.ReadLine());
            }
            Console.WriteLine();
            Console.Write("Введите количество аспирантов m: "); p = int.Parse(Console.ReadLine());
            Graduate_student[] grad = new Graduate_student[p];
            for (int i = 0; i < p; ++i)
            {
                Console.WriteLine("Введите имя, год поступления, факультет, имя руководителя и код специальности аспиранта №" + (i + 1) + ".");
                grad[i] = new Graduate_student(Console.ReadLine() , int.Parse(Console.ReadLine()) , Console.ReadLine() , Console.ReadLine() , int.Parse(Console.ReadLine()));
            }
            Console.WriteLine();
            for (int i = 0; i < n; ++i)
            {
                stud[i].info_s();
                stud[i].rating(score[i]);
            }
            for (int i = 0; i < n; ++i)
            {
                grad[i].info_g(); 
            }
            Console.ReadKey();
        }
    }
}