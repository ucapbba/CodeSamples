using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSExamples
{
    delegate void CallbackMethod(int result,int result2);
    class Calculator
    {
        public event CallbackMethod CalculationComplete;

        public int Add(int x, int y)
        {
            int result = x + y;

            // Raise the callback event
            CalculationComplete?.Invoke(result,result);

            return result;
        }
    }

    // Define a class that handles the callback event
    class CallbackHandler
    {
        public void HandleCallback(int result,int result2)
        {
            Console.WriteLine("Calculation complete! Result: " + result);
            Console.WriteLine("Calculation complete! Result: " + result2);
        }
    }
}
