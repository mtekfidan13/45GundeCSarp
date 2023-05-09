using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Variables_and_DataTypes
{
    public class Program
    {
        static void Main(string[] args)
        {
            byte b = 5;     //1byte
            sbyte c = 5;    //1byte

            short s = 5;    //2byte
            ushort us = 5;   //2byte

            Int16 i16 = 2;  //2byte
            int i = 2;      //4byte
            Int32 i32 = 2;  //4byte
            Int64 i64 = 2;  //8byte

            uint ui = 2;    //4byte
            long l = 4;     //8byte
            ulong ul = 4;   //8byte

            //Real sayılar
            float f = 5;    //4byte
            double d = 5;   //8byte
            decimal de = 5; //16byte

            char ch = '5';  //2byte
            string sr = "Mustafa";  //Sınırsız

            bool b1 = true;
            bool b2 = false;

            DateTime dt = DateTime.Now;

            Console.WriteLine(dt);

            object o1 = "x";
            object o2 = "y";
            object o3 = 4;
            object o4 = 4.3;

            //string ifadeler

            string str1 = string.Empty;
            str1 = "Mustafa TEKFIDAN";
            string ad = "MUSTAFA";
            string soyad = "TEKFIDAN";
            string tamIsim = ad + " " + soyad;

            //Integer

            int integer1 = 5;
            int integer2 = 3;
            int integer3 = integer1 + integer2;

            //boolean

            bool bool1 = 10 > 2;

            //Değişken Dönüşümleri
            string str20 = "20";
            int int20 = 20;
            string yeniDeger = str20 + int20.ToString();
            Console.WriteLine(yeniDeger);   //2020

            int int21 = int20 + Convert.ToInt32(str20);
            Console.WriteLine(int21);

            int int22 = int20 + int.Parse(str20);   //çıktısı 40

            //datetime

            string datetime = DateTime.Now.ToString("dd.MM.yyyy");
            Console.WriteLine(datetime);

            string datetime2 = DateTime.Now.ToString("dd/MM/yyyy");
            Console.WriteLine(datetime2);

            string datetime3 = DateTime.Now.ToString("HH:mm");
            Console.WriteLine(datetime3);



        }
    }
}