using System;
using System.Threading;
using System.Threading.Tasks;

namespace AwaitTask
{

    namespace AsyncBreakfast
    {
        // These classes are intentionally empty for the purpose of this example. They are simply marker classes for the purpose of demonstration, contain no properties, and serve no other purpose.
        internal class Bacon { }
        internal class Coffee { }
        internal class Egg { }
        internal class Juice { }
        internal class Toast { }

        class BreakfastTasks
        {
            public static Juice PourOJ()
            {
                Console.WriteLine("Pouring orange juice");
                return new Juice();
            }

            public static async Task<Toast> MakeToastWithButterAndJamAsync(int number)
            {
                var toast = await ToastBreadAsync(number);
                ApplyButter(toast);
                ApplyJam(toast);

                return toast;
            }
            public static void ApplyJam(Toast toast) =>
                Console.WriteLine("Putting jam on the toast");

            public static void ApplyButter(Toast toast) =>
                Console.WriteLine("Putting butter on the toast");

            public static async Task<Toast> ToastBreadAsync(int slices)
            {
                for (int slice = 0; slice < slices; slice++)
                {
                    Console.WriteLine("Putting a slice of bread in the toaster");
                }
                Console.WriteLine("Start toasting...");
                await Task.Delay(3000);
                Console.WriteLine("Remove toast from toaster");

                return new Toast();
            }

            public static async Task<Bacon> FryBaconAsync(int slices)
            {
                Console.WriteLine($"putting {slices} slices of bacon in the pan");
                Console.WriteLine("cooking first side of bacon...");
                await Task.Delay(3000);
                for (int slice = 0; slice < slices; slice++)
                {
                    Console.WriteLine("flipping a slice of bacon");
                }
                Console.WriteLine("cooking the second side of bacon...");
                await Task.Delay(3000);
                Console.WriteLine("Put bacon on plate");

                return new Bacon();
            }

            public static async Task<Egg> FryEggsAsync(int howMany)
            {
                Console.WriteLine("Warming the egg pan...");
                await Task.Delay(3000);
                Console.WriteLine($"cracking {howMany} eggs");
                Console.WriteLine("cooking the eggs ...");
                await Task.Delay(3000);
                Console.WriteLine("Put eggs on plate");

                return new Egg();
            }
            public static Toast ToastBread(int slices)
            {
                for (int slice = 0; slice < slices; slice++)
                {
                    Console.WriteLine("Putting a slice of bread in the toaster");
                }
                Console.WriteLine("Start toasting...");
                Task.Delay(3000).Wait();
                Console.WriteLine("Remove toast from toaster");

                return new Toast();
            }

            public static Bacon FryBacon(int slices)
            {
                Console.WriteLine($"putting {slices} slices of bacon in the pan");
                Console.WriteLine("cooking first side of bacon...");
                Task.Delay(3000).Wait();
                for (int slice = 0; slice < slices; slice++)
                {
                    Console.WriteLine("flipping a slice of bacon");
                }
                Console.WriteLine("cooking the second side of bacon...");
                Task.Delay(3000).Wait();
                Console.WriteLine("Put bacon on plate");

                return new Bacon();
            }

            public static Egg FryEggs(int howMany)
            {
                Console.WriteLine("Warming the egg pan...");
                Task.Delay(3000).Wait();
                Console.WriteLine($"cracking {howMany} eggs");
                Console.WriteLine("cooking the eggs ...");
                Task.Delay(3000).Wait();
                Console.WriteLine("Put eggs on plate");

                return new Egg();
            }

            public static Coffee PourCoffee()
            {
                Console.WriteLine("Pouring coffee");
                return new Coffee();
            }
        }
    }

    public class MyCallerType
    {
        private Thread currentThread;

        private SynchronizationContext context;

        public event EventHandler EventCallback;

        public MyCallerType()
        {
            context = SynchronizationContext.Current;
            context = context ?? new SynchronizationContext();

            currentThread = new Thread(new ThreadStart(Run));
            currentThread.Start();
        }

        private void CallEventHandler(object state)
        {
            EventHandler handler = EventCallback;

            if (handler != null)
            {
                handler(this, EventArgs.Empty);
            }
        }

        public void Run()
        {
            context.Send(new SendOrPostCallback(this.CallEventHandler), null);
        }
        public void RunAsync()
        {
            context.Post(new SendOrPostCallback(this.CallEventHandler), null);
        }

    }
}
