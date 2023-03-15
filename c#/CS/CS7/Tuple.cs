using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CS7
{
    class Tuple
    {
        public static (int, string) GetPersonDetails(int i, string name)
        {
            // Database lookup code goes here
            // For the sake of example, let's just return some hard-coded values
            return (i, name);
        }

        //Expression Body Memeber example
        public static (int, string) GetPersonDetails2(int i, string name) => (i, name);
    }
}
