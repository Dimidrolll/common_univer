using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace языки2
{
        class person_in_bank
    {
        string name;
        int passport;
        int _counts;
        public List<int> counts;
        public List<double> deposits;
            // свойства
        public string Name { get { return name; } }
        public int Passport { get { return passport; } }
        public int _Counts { get { return _counts; } }

        public person_in_bank(string name , int passport , int _counts)//конструктор
        {
            this.name = name;
            this.passport = passport;
            this._counts = _counts;
            counts = new List<int>();
            deposits = new List<double>();
            for (int i = 1; i <= _counts; ++i)
            {
                Console.WriteLine("Введи номер счета клиента ");
                counts.Add(int.Parse(Console.ReadLine()));
                Console.WriteLine("Введи размер вклада клиента ");
                deposits.Add(double.Parse(Console.ReadLine()));
            }
        }

        public void number() {// определяем номер наибольшего вклада
            double max = -1;
            int q = 1;
            for (int i = 1; i <= _counts; ++i)
                if (max < deposits[i])
                {
                    max = deposits[i];
                    q = i;
                }
            Console.WriteLine("Искомый номер счета: " + counts[q]);
        }

        public double O_number()
        {// определяем наибольший вклад
            double max = -1;
            //int q = 1;
            for (int i = 1; i <= _counts; ++i)
                if (max < deposits[i])
                {
                    max = deposits[i];
                   
                }
            return max;
        }

        public int ind_number()
        {// определяем индекс наибольшего вклада
            double max = -1;
            int q = 1;
            for (int i = 1; i <= _counts; ++i)
                if (max < deposits[i])
                {
                    max = deposits[i];
                    q = i;
                }
            return q;
        }

        public void summ_out(){// определяем сумму вкладов
            double sum = 0;
            
            for (int i = 1; i <= _counts; ++i)
                sum += deposits[i];
            Console.WriteLine("Сумма вкладов: " + sum);    
        }

        public double summ(){// определяем сумму вкладов
            double sum = 0;

            for (int i = 1; i <= _counts; ++i)
                sum += deposits[i];
            return sum;
        }   
    }

    class Program
    {
        public static void Main()
        { 
            List<person_in_bank> person1 = new List<person_in_bank>();
            Console.WriteLine("Введите количество клиентов банка. ");
            int n = int.Parse(Console.ReadLine());
            for (int i = 1; i <= n; ++i){
                Console.WriteLine("Введите фамилию, паспорт, количество счетов клиента банка ");
                person1.Add(new person_in_bank(Console.ReadLine() , int.Parse(Console.ReadLine()) , int.Parse(Console.ReadLine())));
            }
            double O_sum = 0;
            for (int i = 1; i <= n; ++i)
                O_sum += person1[i].summ(); 
            Console.WriteLine("Сумма вкладов всех клиентов: " + O_sum);//сумма вкладов всех клиентов
            double[] max = new double[10]; double maxx = 0; int q = 0;
            for (int i = 1; i <= n; ++i)
            {
                max[i] = person1[i].O_number();
                if (maxx < max[i])
                {
                    maxx = max[i];
                    q = i;
                }
            }
            int q3 = person1[q].ind_number();
            Console.WriteLine("Премия начислена клиенту: " + person1[q].Name);
            Console.WriteLine("На вкладе: " + person1[q].deposits[q3] * 1.02);//начисление процентов
            Console.WriteLine("Кому перевод (укажите индекс)?");// перевод
            int q1 = int.Parse(Console.ReadLine());
            Console.WriteLine("От кого перевод (укажите индекс)?");
            int q2 = int.Parse(Console.ReadLine());
            int index1 = 0,index11 = 0, index2 = 0,index22 = 0;
            for (int i = 1 ; i <= n ; ++i)
            {
                for (int j = 1; j <= person1[i]._Counts; ++j)
                {
                    if (person1[i].counts[j] == q1) { 
                        index1 = i;
                        index11 = j;
                    }
                    if (person1[i].counts[j] == q2)
                    {
                        index22 = j;
                        index2 = i;
                    }
                }
            }
            Console.WriteLine("Сколько перевести?");
            int transf = int.Parse(Console.ReadLine());
            person1[index1].deposits[index11] = transf + person1[index1].deposits[index11];
            person1[index2].deposits[index22] = person1[index2].deposits[index22] - transf;
            Console.WriteLine("Перевод выполнен! \n На счету клиента " + person1[index1].Name + " " + person1[index1].deposits[index11] + "у.е.");
            Console.WriteLine(" На счету клиента " + person1[index2].Name + " " + person1[index2].deposits[index22] + "у.е.");
            Console.ReadKey();
        }
        
    }
     
}
