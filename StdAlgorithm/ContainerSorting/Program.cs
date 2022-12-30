using System;
using System.Collections.Generic;
using System.Linq;

namespace ContainerSorting
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            List<container> myList = new List<container>();
            myList.Add(new container("Alp[ha",1));
            myList.Add(new container("*",2));
            myList.Add(new container("Gamaa",3));
            myList.Add(new container("Beta",4));
            myList.Add(new container("A",5));
            myList.Add(new container("Brad",6));
            myList.Add(new container("Veto",7));


            List<container> orderedlist = myList.OrderBy(a => a.name).ToList();
           
            var star = orderedlist.Find(a => a.name == "*");
            orderedlist.RemoveAt(0);
            orderedlist.Add(star);

        }
    }

    public class container
    {
        public container(string _name,int _number)
        {
            name = _name;
            number = _number;
        }
        public string name { get; set; }
        public int number { get; set; }
    }
}
