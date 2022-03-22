using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TryCatch
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("Hello World!");

            //throw new InvalidOperationException();
            try
            {
                throw new ArgumentException();
            }
            catch(Exception e)
            {
                if(e is ArgumentException)
                {
                    Console.WriteLine("Caught - rethrow!");
                    throw; //re-throws ArgumentException - code ends 
                }

                Console.WriteLine("Handling other excpetions");
            }
        }
    }
}
