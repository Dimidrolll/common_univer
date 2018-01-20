using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RNO1
{
    class tourfirm
    {
        string name;
        string[] surname;
        int[] str;
        int count;
        public string Name { get { return name; } }
        public string[] Surname { get { return surname; } }
        public int[] Str { get { return str; } }
        public int Count { get { return count; } }

        public tourfirm(string name ,int count) {
            this.name = name;
            this.count = count;
            surname = new string[count];
            str = new int [count];
            for (int i = 0; i < count; ++i) {
                Console.WriteLine("Введите фамилию и размер страховки клиента №" + (i + 1));
                surname[i] = Console.ReadLine();
                str[i] = int.Parse(Console.ReadLine()); 
            }
        }
        public void inf() {
            Console.WriteLine("Название компании: " + name + ". В ней " + count + " клиентов.");
            Console.WriteLine("Клиенты компании и размер их страховки: ");
            for (int i = 0; i < count; ++i) {
                Console.WriteLine("Клиент №" + i + ": " + surname[i] + "  " + str[i]);
            }
        }
        public int sum()
        { 
            int rez = 0;
            for (int i = 0; i < count; ++i)
                rez += str[i];
            return rez;
        }
        public int max() {
            int m = 0;
            for (int i = 0; i < count; ++i)
                if (m < str[i]) m = str[i];
            return m;
        }
    }
    class Program
    {
        static void Main()
        {
            const int n = 3; 
            tourfirm[] comp = new tourfirm [n];//массив объектов
            for (int i = 0; i < n; ++i)
            {
                Console.WriteLine("Введите название компании и кол-во клиентов.");
                comp[i] = new tourfirm(Console.ReadLine() , int.Parse(Console.ReadLine()));
            }
            int SUM = 0;
            for (int i = 0; i < n; ++i)//сумма всех страховок
            {
                SUM += comp[i].sum();
            }
            Console.WriteLine("Сумма всех страховок: " + SUM);

            int MAX = 0, j = 0;
            for (int i = 0; i < n; ++i)//максимальная страховка
                if (MAX < comp[i].max()){
                    MAX = comp[i].max();
                    j = i;
                }
            Console.WriteLine("Максимальная страховка " + MAX + " у клиента компании " + comp[j].Name);
            Console.ReadKey();
        }
    }
}
