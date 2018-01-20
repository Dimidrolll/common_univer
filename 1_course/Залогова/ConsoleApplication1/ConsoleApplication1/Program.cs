using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;


namespace ConsoleApplication1
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

        public airplanes(int power, int cost, int number, string mark, int height) {
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
        public void inf() {
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
        public auto(int power , int cost , int number , string mark, int odo, string techvis)
            : base (power, cost, number, mark) {
                this.odo = odo;
                this.techvis = techvis;
        }
        public override void info() {
            base.inf();
            Console.WriteLine(" " + odo + " " + techvis);
        }

       
    }

    

    class Program
    {
        static void Main()
        {
            const int n = 5;
            airplanes[] machines = new airplanes[n];
            StreamReader f;
            string[] s = new string[7];
            string str;
            try {
                f = new StreamReader("C:\\Users\\acer\\Desktop\\input.txt");
            }
            catch (Exception e) {
                Console.WriteLine();
                return;
            }
            int i = 0;
            while ((str = f.ReadLine()) != null) {
                s[0] = str.Split(' ')[0];
                s[1] = str.Split(' ')[1];
                s[2] = str.Split(' ')[2];
                s[3] = str.Split(' ')[3];
                s[4] = str.Split(' ')[4];
                s[5] = str.Split(' ')[5];
                if (s[0] == "0") {
                    machines[i] = new airplanes(int.Parse(s[1]) , int.Parse(s[2]) , int.Parse(s[3]) , s[4], int.Parse(s[5]));
                    ++i;
                }
                else {
                    s[6] = str.Split(' ')[6];
                    machines[i] = new auto(int.Parse(s[1]) , int.Parse(s[2]) , int.Parse(s[3]) , s[4] , int.Parse(s[5]), s[6]);
                    ++i;
                }
            }
            f.Close();
            for (i = 0; i < n; ++i)
                machines[i].info();
            Console.WriteLine();          
            FileStream fs;
            BinaryFormatter form = new BinaryFormatter();
            try{ fs = new FileStream("D:\\a.dat", FileMode.Create,FileAccess.Write);}
            catch(Exception e) {
                Console.WriteLine(e.Message);
                return;
            }
            form.Serialize(fs , machines);
            fs.Close();
            Console.ReadKey();
        }
    }
}
