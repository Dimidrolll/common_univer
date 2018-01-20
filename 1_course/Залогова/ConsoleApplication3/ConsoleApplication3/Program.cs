using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace ConsoleApplication1
{

    class airplanes
    {
        protected int power;
        protected int cost;
        protected int number;
        protected string mark;
        int height;
        public int Power { get { return power; } }
        public int Cost { get { return cost; } }
        public int Number { get { return number; } }
        public string Mark { get { return mark; } }
        public int Height { get { return height; } }

        public airplanes(int power , int cost , int number , string mark , int height)
        {
            this.power = power;
            this.cost = cost;
            this.number = number;
            this.mark = mark;
            this.height = height;
        }
        public airplanes(int power , int cost , int number , string mark)
        {
            this.power = power;
            this.cost = cost;
            this.number = number;
            this.mark = mark;
        }
        public virtual void info()
        {
            Console.WriteLine("Марка " + mark + " " + height);
        }
        public void inf()
        {
            Console.Write("Марка " + mark + " ");
        }
    }

    class auto : airplanes
    {
        int odo;

        public int Odo { get { return odo; } }
        public auto(int power , int cost , int number , string mark , int odo)
            : base(power , cost , number , mark)
        {
            this.odo = odo;
        }
        public override void info()
        {
            base.inf();
            Console.WriteLine(" " + odo);
        }


    }



    class Program
    {
        static void Main()
        {
            const int n = 5;
            auto[] machines = new auto[n];

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
                s[0] = str.Split(' ')[0];
                s[1] = str.Split(' ')[1];
                s[2] = str.Split(' ')[2];
                s[3] = str.Split(' ')[3];
                s[4] = str.Split(' ')[4];
                s[5] = str.Split(' ')[5];
                machines[i] = new auto(int.Parse(s[1]) , int.Parse(s[2]) , int.Parse(s[3]) , s[4] , int.Parse(s[5]));
                ++i;
            }
            f.Close();

            for (i = 0; i < n; ++i)
                machines[i].info();
            Console.WriteLine();

            for (i = 0; i < n; ++i)
            {
                if (machines[i] is auto)
                {
                    auto a = (auto)machines[i];
                    Console.WriteLine(a.Power);
                }
            }

            //Console.WriteLine("Введите номер самолета:");
            //int num = int.Parse(Console.ReadLine());

            //for (i = 0; i < n; ++i)
            //    if (mech[i] is airplanes && mech[i].Number == num)
            //        Console.WriteLine("Мощность самолета: " + mech[i].Power + ", максимальная высота полета: " + mech[i].Height + "\n");
            //int max = 0;
            //for (i = 0; i < n; ++i)
            //{
            //    if (mech[i] is auto)
            //    {
            //        auto a = (auto)mech[i];
            //        if (a.Cost > max)
            //            max = a.Cost;
            //    }
            //}
            //for (i = 0; i < n; ++i)
            //{
            //    if (mech[i] is auto)
            //    {
            //        auto a = (auto)mech[i];
            //        if (a.Cost == max)
            //            Console.WriteLine(a.Techvis);
            //    }
            //}

            //double nal = 0;
            //for (i = 0; i < n; ++i)
            //{
            //    if (!(mech[i] is auto))
            //    {
            //        airplanes a = (airplanes)mech[i];
            //        nal += 0.03 * a.Cost;
            //    }
            //}
            //Console.WriteLine(nal);
            Console.ReadKey();
        }
    }
}
