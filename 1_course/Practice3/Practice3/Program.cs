using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class mailAddress
{
    public string name;
    public int index;
    public string city;
    public string street;
    public short number_of_dom;
    public bool can;
    public mailAddress(string name, int index, string city, string street, short number_of_dom, bool can)
    {
        this.name = name;
        this.index = index;
        this.city = city;
        this.street = street;
        this.number_of_dom = number_of_dom;
        this.can = can;
    }
    public void info () { 
        Console.WriteLine("Название компании: " + name);
        Console.WriteLine("Адрес: город " + city + ", улица " + street + ", дом " + number_of_dom);
        Console.WriteLine("Почтовый индекс: " + index);
        Console.WriteLine("Могу ли я - простой смертный, написать письмо Димасу? Ответ всемогущего оракула: " + can);
    }
    public void inspection(bool q)
    {
        if (q == true) Console.WriteLine("Вы можете написать письмо.");
        else Console.WriteLine("Вы не можете написать письмо.");
    }
}



namespace ConsoleApplication1
{
    class proga
    {
        static void Main()
        {
            mailAddress Comp = new mailAddress("У Димаса", 666551, "Пермь","Петропавловская", 115, true);
           
            Comp.info();
            Comp.inspection(Comp.can);//проверка
            Console.WriteLine("Сложим индекс и номер дома и получим пароль к личному кабинету в системе: www.UDimasa.domen (если мы можем написать письмо)");
            if (Comp.can)
            {
                int sum = Comp.index + Comp.number_of_dom;
                Console.WriteLine("Получили пароль: " + sum);
            }
            else Console.WriteLine("Отказано в доступе. Шиш вам, а не пароль.");

            Console.ReadKey();

        }
    }

}
