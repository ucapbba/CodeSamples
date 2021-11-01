using System;
using CLI;
namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Read();
            Entity e = new Entity("The Wallman", 20, 35);
            e.Move(5, -10);
            Console.WriteLine(e.XPosition + " " + e.YPosition);
            Console.Read();

            // Go to http://aka.ms/dotnet-get-started-console to continue learning how to build a console app! 
        }
    }
}
