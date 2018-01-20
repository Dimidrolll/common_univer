using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


    class Polynom
    {
        public double[] massiv;
        public int degree;
        public Polynom(int degree)
        {
            this.degree = degree;
            massiv = new double[degree + 1];
            Console.WriteLine("Введите коэффициенты: ");
            for (int i = 0; i <= degree; i++)
                massiv[i] = double.Parse(Console.ReadLine());
        }
        public Polynom() { }
        public void Itog(double x)//
        {
            double rez = 0;
            for (int i = 0; i <= degree; i++)
                rez += massiv[i] * Math.Pow(x , i);
            Console.Write("Значение многочлена при x = " + x + ": ");
            Console.Write(rez);
            Console.WriteLine("\n");
        }

        public void Add()//+
        {
            int i , degree1 , degree2;
            Console.Write("Введите степень первого многочлена: ");
            degree1 = int.Parse(Console.ReadLine());
            double[] massiv1 = new double[degree1 + 1];
            Console.WriteLine("Введите коэффициенты первого многочлена:");
            for (i = 0; i <= degree1; i++)
                massiv1[i] = double.Parse(Console.ReadLine());
            Console.WriteLine("\n");
            Console.Write("Введите степень второго многочлена: ");
            degree2 = int.Parse(Console.ReadLine());
            double[] massiv2 = new double[degree2 + 1];
            Console.WriteLine("Введите коэффициенты второго многочлена:");
            for (i = 0; i <= degree2; i++)
                massiv2[i] = double.Parse(Console.ReadLine());

            if (degree1 > degree2)
            {
                massiv = new double[degree1 + 1];
                for (i = 0; i <= degree2; i++)
                    massiv[i] = massiv1[i] + massiv2[i];
                for (i = degree2 + 1; i <= degree1; i++)
                    massiv[i] = massiv1[i];
                i = degree1;
                while (massiv[i] == 0)
                    i--;
                degree = i;
            }
            else
            {
                massiv = new double[degree2 + 1];
                for (i = 0; i <= degree1; i++)
                    massiv[i] = massiv1[i] + massiv2[i];
                for (i = degree1 + 1; i <= degree2; i++)
                    massiv[i] = massiv2[i];
                i = degree2;
                while ((massiv[i] == 0) && (i > 0))
                    i--;
                degree = i;
            }
        }
        public void Diff()//-
        {
            int i , degree1 , degree2;
            Console.Write("Введите степень первого многочлена: ");
            degree1 = int.Parse(Console.ReadLine());
            double[] massiv1 = new double[degree1 + 1];
            Console.WriteLine("Введите коэффициенты первого многочлена:");
            for (i = 0; i <= degree1; i++)
                massiv1[i] = double.Parse(Console.ReadLine());
            Console.WriteLine("\n");
            Console.Write("Введите степень второго многочлена: ");
            degree2 = int.Parse(Console.ReadLine());
            double[] massiv2 = new double[degree2 + 1];
            Console.WriteLine("Введите коэффициенты второго многочлена:");
            for (i = 0; i <= degree2; i++)
                massiv2[i] = double.Parse(Console.ReadLine());

            if (degree1 > degree2)
            {
                massiv = new double[degree1 + 1];
                for (i = 0; i <= degree2; i++)
                    massiv[i] += massiv1[i] - massiv2[i];
                for (i = degree2 + 1; i <= degree1; i++)
                    massiv[i] = massiv1[i];
                i = degree1;
                while (massiv[i] == 0)
                    i--;
                degree = i;
            }
            else
            {
                massiv = new double[degree2 + 1];
                for (i = 0; i <= degree1; i++)
                    massiv[i] += massiv1[i] - massiv2[i];
                for (i = degree1 + 1; i <= degree2; i++)
                    massiv[i] = massiv2[i];
                i = degree2;
                while ((massiv[i] == 0) && (i > 0))
                    i--;
                degree = i;
            }
        }
        public void Info()
        {
            string s = "";
            Console.WriteLine("Степень многочлена: " + degree);
            Console.Write("Вид многочлена с заданными коэффициентами: ");
            for (int i = 0; i <= degree; i++)
            {
                if ((i == 0) && (massiv[i] != 0))
                {
                    s += massiv[i];
                    if (i + 1 <= degree)
                        s += " + ";
                }
                if ((massiv[i] != 0) && (i != 0))
                {
                    s += massiv[i] + "x^" + i;
                    if (i + 1 <= degree)
                        s += " + ";
                }
            }
            Console.Write(s);
            Console.WriteLine("\n");
        }
    }





namespace Practice3_3
{
    class Program
    {
         void Main()
        {
            Console.Write("Введите степень многочлена: ");
            Polynom pol = new Polynom(int.Parse(Console.ReadLine()));
            Console.WriteLine("\n");

            pol.Info();
            Console.Write("Введите значение аргумента x: ");
            pol.Itog(double.Parse(Console.ReadLine()));

            Polynom pola = new Polynom();
            Polynom pold = new Polynom();
            pola.Add();
            Console.WriteLine("Сумма двух многочленов");
            pola.Info();
            pold.Diff();
            Console.WriteLine("Разность двух многочленов");
            pold.Info();
            Console.WriteLine("Нажмите любую кнопку!");
            Console.ReadKey();
        }
    }
}
