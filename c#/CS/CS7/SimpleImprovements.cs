using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CS7
{
    class SimpleImprovements
    {
        public static void Examples()
        {
            //numeric literals
            int i = 1_234_456;
        }

        public static void outExample(int inVal, out int outVal)
        {
            outVal = inVal;
        }

        public static void refExample(ref int inVal, ref int outVal)
        {
            outVal = inVal;
        }
    }
}

