using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;

namespace ConsoleApplication2
{
    [Serializable]
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
    [Serializable]
    class auto : airplanes
    {
        int odo;
        string techvis;

        public int Odo { get { return odo; } }
        public string Techvis { get { return techvis; } }
        public auto(int power , int cost , int number , string mark , int odo , string techvis)
            : base(power , cost , number , mark)
        {
            this.odo = odo;
            this.techvis = techvis;
        }
        public override void info()
        {
            base.inf();
            Console.WriteLine(" " + odo + " " + techvis);
        }
    }

    class Program
    {
        static void Main()
        {
            const int n = 5;
            int i;
            airplanes[] mech;
            FileStream fs;
            BinaryFormatter form = new BinaryFormatter();
            try { fs = new FileStream("D:\\a.dat" , FileMode.Open , FileAccess.Read); }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                return;
            }
            mech = (airplanes[])form.Deserialize(fs);
            fs.Close();
            Console.WriteLine("Введите номер самолета:"); 
            int num = int.Parse(Console.ReadLine());
           
            for (i = 0; i < n; ++i )
                if (mech[i] is airplanes && mech[i].Number == num)
                    Console.WriteLine("Мощность самолета: " + mech[i].Power + ", максимальная высота полета: " + mech[i].Height + "\n");
            Console.ReadKey();
            int max = 0;
            for (i = 0; i < n; ++i)
            {
                if (mech[i] is auto)
                {
                    auto a = (auto)mech[i];
                    if (a.Cost > max)
                        max = a.Cost;
                }
            }
            for (i = 0; i < n; ++i)
            {
                if (mech[i] is auto)
                {
                    auto a = (auto)mech[i];
                    if (a.Cost == max)
                        Console.WriteLine(a.Techvis);
                }
            }
            double nal = 0;
            for (i = 0; i < n; ++i)
            {
                if (!(mech[i] is auto))
                {
                    airplanes a = (airplanes)mech[i];
                    nal += 0.03 * a.Cost;
                }
            }
            Console.WriteLine(nal);
            Console.ReadKey();
        }
    }
}
