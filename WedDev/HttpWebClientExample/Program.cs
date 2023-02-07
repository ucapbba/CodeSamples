using System;
using System.Net.Http;
using System.Threading.Tasks;

namespace HttpWebClientExample
{
    class Program
    {
        static async Task Main(string[] args)
        {
            using var client = new HttpClient();
            var url = "http://localhost:8081/";
            var content = await client.GetStringAsync(url);
            Console.WriteLine(content);
            var result = await client.SendAsync(new HttpRequestMessage(HttpMethod.Head, url));
            Console.WriteLine(result);
        }
    }
}
