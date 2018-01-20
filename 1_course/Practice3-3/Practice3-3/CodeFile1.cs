using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


class Polynom
{
    public double[] array;
    public int degree;


    public Polynom(int degree)//конструктор
    {
        if (degree == -1) return;
        else
        {
            this.degree = degree;
            array = new double[degree + 1];
            Console.WriteLine("Введите коэффициенты: ");
            for (int i = 0; i <= degree; i++)
                array[i] = double.Parse(Console.ReadLine());
        }
    }

    public void value(double x)//значение многочлена при задаваемом х
    {
        double rez = 0;
        for (int i = 0; i <= degree; i++)
            rez += array[i] * Math.Pow(x , i);
        Console.WriteLine("Значение многочлена при x = " + x + " : " + rez);
    }

    public void summa()//сумма многочленов
    {
        int i , degree1 , degree2;
        Console.Write("Введите степень первого многочлена: ");
        degree1 = int.Parse(Console.ReadLine());
        double[] massiv1 = new double[degree1 + 1];
        Console.WriteLine("Введите коэффициенты первого многочлена:");
        for (i = 0; i <= degree1; i++)
            massiv1[i] = double.Parse(Console.ReadLine());
        Console.Write("Введите степень второго многочлена: ");
        degree2 = int.Parse(Console.ReadLine());
        double[] massiv2 = new double[degree2 + 1];
        Console.WriteLine("Введите коэффициенты второго многочлена:");
        for (i = 0; i <= degree2; i++)
            massiv2[i] = double.Parse(Console.ReadLine());

        if (degree1 > degree2)
        {
            array = new double[degree1 + 1];
            for (i = 0; i <= degree2; i++)
                array[i] = massiv1[i] + massiv2[i];
            for (i = degree2 + 1; i <= degree1; i++)
                array[i] = massiv1[i];
            i = degree1;
            while (array[i] == 0)
                i--;
            degree = i;
        }
        else
        {
            array = new double[degree2 + 1];
            for (i = 0; i <= degree1; i++)
                array[i] = massiv1[i] + massiv2[i];
            for (i = degree1 + 1; i <= degree2; i++)
                array[i] = massiv2[i];
            i = degree2;
            while ((array[i] == 0) && (i > 0))
                i--;
            degree = i;
        }
    }
    public void difference()//разность
    {
        int i , degree1 , degree2;
        Console.Write("Введите степень первого многочлена: ");
        degree1 = int.Parse(Console.ReadLine());
        double[] massiv1 = new double[degree1 + 1];
        Console.WriteLine("Введите коэффициенты первого многочлена:");
        for (i = 0; i <= degree1; i++)
            massiv1[i] = double.Parse(Console.ReadLine());
        Console.Write("Введите степень второго многочлена: ");
        degree2 = int.Parse(Console.ReadLine());
        double[] massiv2 = new double[degree2 + 1];
        Console.WriteLine("Введите коэффициенты второго многочлена:");
        for (i = 0; i <= degree2; i++)
            massiv2[i] = double.Parse(Console.ReadLine());

        if (degree1 > degree2)
        {
            array = new double[degree1 + 1];
            for (i = 0; i <= degree2; i++)
                array[i] += massiv1[i] - massiv2[i];
            for (i = degree2 + 1; i <= degree1; i++)
                array[i] = massiv1[i];
            i = degree1;
            while (array[i] == 0)
                i--;
            degree = i;
        }
        else
        {
            array = new double[degree2 + 1];
            for (i = 0; i <= degree1; i++)
                array[i] += massiv1[i] - massiv2[i];
            for (i = degree1 + 1; i <= degree2; i++)
                array[i] = massiv2[i];
            i = degree2;
            while ((array[i] == 0) && (i > 0))
                i--;
            degree = i;
        }
    }
    public void inf()
    {
        string s = "";
        Console.WriteLine("Степень многочлена: " + degree);
        Console.Write("Вид многочлена с заданными коэффициентами: ");
        for (int i = 0; i <= degree; i++)
        {
            if ((i == 0) && (array[i] != 0))
            {
                s += array[i];
                if (i + 1 <= degree)
                    s += "+";
            }
            if ((array[i] != 0) && (i != 0))
            {
                s += array[i] + "x^" + i;
                if (i + 1 <= degree)
                    s += "+";
            }
        }
        Console.WriteLine(s);
    }
}


namespace Practice3_3
{
    class Program
    {
        public static void Main()
        {
            Console.Write("Введите степень многочлена: ");
            Polynom polin = new Polynom(int.Parse(Console.ReadLine()));
            polin.inf();
            Console.Write("Введите значение аргумента x: ");
            polin.value(double.Parse(Console.ReadLine()));

            Polynom polsum = new Polynom(-1);
            Console.WriteLine("Сумма двух многочленов");
            polsum.summa();
            polsum.inf();

            Console.WriteLine("Разность двух многочленов");
            Polynom poldif = new Polynom(-1);
            poldif.difference();
            poldif.inf();


            Console.WriteLine("Нажмите любую кнопку!");
            Console.ReadKey();
        }
    }
}
