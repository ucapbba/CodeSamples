using System;
using System.Threading.Tasks;

class Program
{
    static async Task Main()
    {
        var workTask = DoSomeWorkAsync();
        var otherWorkTask = DoSomeOtherWorkAsync();
        await Task.WhenAll(workTask, otherWorkTask);

        Console.WriteLine("Both tasks completed!");
    }

    static async Task DoSomeWorkAsync()
    {
        // Simulate some work here
        Console.WriteLine("Start work");
        await Task.Delay(1000);
        Console.WriteLine("Work completed!");
    }

    static async Task DoSomeOtherWorkAsync()
    {
        // Simulate some other work here
        Console.WriteLine("Start other work!");
        await Task.Delay(2000);
        Console.WriteLine("Other work completed!");
    }
}