using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSExamples
{
    public delegate int Operation(int a, int b);
    class DelegateExample
    {
        // Define some methods that match the delegate type
        public int Add(int a, int b)
        {
            return a + b;
        }

        public  int Multiply(int a, int b)
        {
            return a * b;
        }

        // Define a method that takes a delegate as a parameter
        public int PerformOperation(int a, int b, Operation op)
        {
            return op(a, b);
        }

    }
}
