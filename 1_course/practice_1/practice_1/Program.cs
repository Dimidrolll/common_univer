using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        //static void Main()
        //{
        //    int i;
            
        //    for (i = 110; i <= 999; i += 22)
        //    {
        //        Console.Write(i + " ");
        //    }
        //    Console.WriteLine("Нажмите любую кнопку!");
        //    Console.ReadKey();
        //}
        static void Main()
        {
            double sum = 0, x = 1, n = 1;
            //Console.WriteLine("Vvedy n");
            //n = int.Parse(Console.ReadLine());
            while (Math.Abs(x) > 0.0001)
            {

                sum += x;
                ++n;
                x = x * (-1) * Math.Pow(n - 1, n - 1) / Math.Pow(n, n);
 
            }
            Console.WriteLine("Сумма равна: " + "{0:0.####}", sum);
            Console.WriteLine("Нажмите любую кнопку!");
            Console.ReadKey();
        }


    }
}
