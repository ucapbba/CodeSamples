using AwaitTask.AsyncBreakfast;
using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;

namespace AwaitTask
{
        class Program
        {
            static async Task Main(string[] args) //Breakfast example
            {

           //BreakfastExample();
            Coffee cup = BreakfastTasks.PourCoffee();
            Console.WriteLine("coffee is ready");

            var eggsTask = BreakfastTasks.FryEggsAsync(2);
            var baconTask = BreakfastTasks.FryBaconAsync(3);
            var toastTask = BreakfastTasks.MakeToastWithButterAndJamAsync(2);

            var breakfastTasks = new List<Task> { eggsTask, baconTask, toastTask };
            while (breakfastTasks.Count > 0)
            {
                Task finishedTask = await Task.WhenAny(breakfastTasks);
                if (finishedTask == eggsTask)
                {
                    Console.WriteLine("eggs are ready");
                }
                else if (finishedTask == baconTask)
                {
                    Console.WriteLine("bacon is ready");
                }
                else if (finishedTask == toastTask)
                {
                    Console.WriteLine("toast is ready");
                }
                await finishedTask;
                breakfastTasks.Remove(finishedTask);
            }

            Juice oj = BreakfastTasks.PourOJ();
            Console.WriteLine("oj is ready");
            Console.WriteLine("Breakfast is ready!");
            //MyCallerType type = new MyCallerType();
            //type.Run();
            //type.RunAsync();
        }

    }
}