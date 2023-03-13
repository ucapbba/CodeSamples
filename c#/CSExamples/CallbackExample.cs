using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSExamples
{
    delegate void CallbackMethod(int result);
    class Calculator
    {
        public event CallbackMethod CalculationComplete;

        public int Add(int x, int y)
        {
            int result = x + y;

            // Raise the callback event
            CalculationComplete?.Invoke(result);

            return result;
        }

        public int Multiply(int x, int y)
        {
            int result = x * y;

            // Raise the callback event
            CalculationComplete?.Invoke(result);

            return result;
        }
    }

    // Define a class that handles the callback event
    class CallbackHandler
    {
        public void HandleCallback(int result)
        {
            Console.WriteLine("Calculation complete! Result: " + result);
        }
    }
}
