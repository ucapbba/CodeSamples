using AwaitTask.AsyncBreakfast;
using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;

namespace AwaitTask
{
        class Program
        {
     


    static async Task Main(string[] args) 
        {

            FunctionTask.ShowThreadInfo();
            var myTask = await Functions.BreakfastExampleAsync();

            //MyCallerType type = new MyCallerType();
            //type.Run();
            //type.RunAsync();
        }
    }
}