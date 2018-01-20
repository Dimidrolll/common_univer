using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class newspaper_editoring
    {
        public string name;
        public int tiraj;
        public int persons;
        public string name_of_red;
        public string[] name_of_j = new string [99];
        public int[] persons_z = new int[99];
        public int red_z;
        public newspaper_editoring(string name, int tiraj, int persons)
        {
            this.name = name;
            this.tiraj = tiraj;
            this.persons = persons;
        }
        public void info() {//информация о газете
            Console.WriteLine("Название: " + name + '\n' + "Тираж: " + tiraj + '\n'
                + "В редакции трудится " + persons + " человек" + "\n");
        }
        public void init_pers(string[] s, int[] a,int q,ref string sg,ref int ag)//инициализация персонала
        {
            for (int i = 0; i < q - 1; ++i)
            {
                Console.WriteLine("Введи имя журналиста: ");
                s[i] = Console.ReadLine();
                Console.WriteLine("Введи з/п журналиста: ");
                a[i] = int.Parse(Console.ReadLine());
            }
            Console.WriteLine("Введи имя главного редактора: ");
            sg = Console.ReadLine();
            Console.WriteLine("Введи з/п главного редактора: ");
            ag = int.Parse(Console.ReadLine());
        }
        public void info_pers(string[] s,int[] a,int q)//вывод данных о журналистах
        {
            Console.WriteLine("Журналисты и их з/п: ");
            for (int i = 0; i < q - 1; ++i)
            {
                Console.Write(s[i] + ' ');
                Console.WriteLine(a[i]);
            }
        }
        public void info_red(string s, int a)//вывод данных о гл.редакторе
        {
            Console.WriteLine("Главный редактор и его з/п: ");
            
                Console.Write(s + ' ');
                Console.WriteLine(a);
            
        }
        public void sr_z(int[] s, int a)//средняя зарплата журналистов
        {
            
            double sum = 0;
            for (int i = 0; i < a - 1; ++i)
                sum += s[i];
            Console.WriteLine("Средняя з/п журналистов: " + sum / (a - 1));
        }
        public void sum_z(int[] s, int a)//средняя зарплата работников
        {

            double sum = 0;
            for (int i = 0; i < a - 1; ++i)
                sum += s[i];
            Console.WriteLine("Средняя з/п работников: " + sum);
        }
        public void del_red() 
        {
            Console.WriteLine("Хотите уволить главного редактора? Да - 1, нет - 0.");
            int t = int.Parse(Console.ReadLine());
            if (t == 1)
            {
                Console.WriteLine("Главный редактор уволен.");
                Console.WriteLine("Его временно будет замещать журналист " + name_of_j[0]);
                name_of_red = name_of_j[0];
                Console.WriteLine("Журналисты и их з/п: ");
                for (int i = 1; i < persons - 1; ++i)
                {
                    Console.Write(name_of_j[i] + ' ');
                    Console.WriteLine(persons_z[i]);
                }
                Console.WriteLine("Главный редактор и его з/п: ");
                Console.Write(name_of_red + ' ');
                Console.WriteLine(red_z);
            }
            else
            {
                Console.WriteLine("Главный редактор помилован.");
                Console.WriteLine("Журналисты и их з/п: ");
                for (int i = 0; i < persons - 1; ++i)
                {
                    Console.Write(name_of_j[i] + ' ');
                    Console.WriteLine(persons_z[i]);
                }
                Console.WriteLine("Главный редактор и его з/п: ");
                Console.Write(name_of_red + ' ');
                Console.WriteLine(red_z);
            }
        }
    }
    
    
    class Program
    {
        public static void Main()
        {
            newspaper_editoring paper1 = new newspaper_editoring("Газета моей мечты", 20000, 3);
            newspaper_editoring paper2 = new newspaper_editoring("Я - Звизда!", 666, 35);
            newspaper_editoring paper3 = new newspaper_editoring("Никому не нужные новости", 50, 1000);
            paper1.info();
            paper1.init_pers(paper1.name_of_j, paper1.persons_z, paper1.persons,ref paper1.name_of_red,ref paper1.red_z);
            paper1.info_pers(paper1.name_of_j, paper1.persons_z, paper1.persons);
            paper1.info_red(paper1.name_of_red,paper1.red_z);
            paper1.sr_z(paper1.persons_z, paper1.persons);
            paper1.sum_z(paper1.persons_z, paper1.persons);
            paper1.del_red();
            Console.ReadKey();
        }
        
    }
     
}
