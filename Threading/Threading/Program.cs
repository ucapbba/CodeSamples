using System;
using System.Threading;

namespace Threasing
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Main thread starts here.");

            // Create a background thread for heavy lifting
            Thread backgroundThread = new Thread(DoSomeHeavyLifting);
            backgroundThread.Start();

            // This method doesn't take anytime at all.  
            Program.DoSomething();

            Console.WriteLine("Main thread ends here.");
            Console.ReadKey();
        }

        public static void DoSomeHeavyLifting()
        {
            Console.WriteLine("I'm lifting a truck!!");
            Thread.Sleep(1000);
   
            Console.WriteLine(Environment.NewLine+"Lifting once ...."+ Environment.NewLine);
            Thread.Sleep(1000);
            Console.WriteLine(Environment.NewLine + "Lifting once 2 times...."+ Environment.NewLine);
            Thread.Sleep(1000);
            Console.WriteLine(Environment.NewLine + "Done lifting"+Environment.NewLine);
        }
        public static void DoSomething()
        {

            Console.WriteLine("***************** Hey! DoSomething Else here! *******************");
            for (int i = 0; i < 20; i++)
            {
                Console.Write($"{i} async loop");
                Thread.Sleep(200);
            }
            Console.WriteLine();
            Console.WriteLine("****************  DoSomething Else done. *******************");
        }
    }
}
