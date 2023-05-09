using System;
//Console.WriteLine("Hello, World!"); // veri yazmak için kullandığım yapı 
namespace deneme1 // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string str1 = "a";
            int int1 = 10;
            int newValue = int1 + Convert.ToInt16(str1);
            Console.WriteLine(newValue);
        }
    }
}