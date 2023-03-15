using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CS7
{
    class ExpressionBodyMemeber
    {
        private string firstName;
        private string lastName;

        // Expression-bodied constructor
        public ExpressionBodyMemeber(string firstName, string lastName) => (this.firstName, this.lastName) = (firstName, lastName);

        // Expression-bodied property
        public string FullName => $"{firstName} {lastName}";

        // Expression-bodied method
        public void PrintFullName() => Console.WriteLine(FullName);
    }

    public class Calculator
    {
        // Expression-bodied method
        public int Add(int a, int b) => a + b;

        // Expression-bodied property
        public double Pi => 3.14159265359;

        // Expression-bodied getter-only property
        public string AppName => $"{nameof(Calculator)} v1.0";
    }
}
