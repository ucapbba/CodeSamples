using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CS7
{
    class Program
    {
        static async Task Main(string[] args)
        {
            (int id, string name) = Tuple.GetPersonDetails(1, "bob");

            int outVal;
            SimpleImprovements.outExample(1, out outVal);

            //static main in c# 7
            await LongRunningMethodAsync();
        }

        static async Task LongRunningMethodAsync()
        {
            Console.WriteLine("Long running method started...");

            // Simulate a long-running task.
            await Task.Delay(5000);

            Console.WriteLine("Long running method completed.");
        }
    }
}
