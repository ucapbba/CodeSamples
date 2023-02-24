using System;

namespace CSExamples
{


    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");
            //DelegateExample delegateExample = new DelegateExample();
            //int result1 = delegateExample.PerformOperation(10, 20, new Operation(delegateExample.Add)); // result1 = 30
            //int result2 = delegateExample.PerformOperation(10, 20, new Operation(delegateExample.Multiply)); // result2 = 200

            ////Callback example
            //I just met you,
            //And this is crazy,
            //But here's my number (delegate),
            //So if something happens(event),
            //Call me, maybe (callback)?
            // Use the classes to perform a calculation and handle the callback
            Calculator calculator = new Calculator();
            CallbackHandler handler = new CallbackHandler();
            calculator.CalculationComplete += handler.HandleCallback;
            int sum = calculator.Add(2, 3); // Output: "Calculation complete! Result: 5"

        }
    }
}
