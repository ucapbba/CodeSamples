using Newtonsoft.Json;
using System;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

namespace HttpWebClientExample
{
    class Program
    {
        static async Task Main(string[] args)
        {
            using var client = new HttpClient();
            var url = "http://127.0.0.1:5000/incomes";
            var content = await client.GetStringAsync(url);
            Console.WriteLine(content);
            var result = await client.SendAsync(new HttpRequestMessage(HttpMethod.Head, url));
            Console.WriteLine(result);
            
            //post
            var person = new string("{description:lottery,amount:1000.0}"); //todo
            var json = JsonConvert.SerializeObject(person);
            var data = new StringContent(json, Encoding.UTF8, "application/json");
            var response = await client.PostAsync(url, data);
            var result2 = await response.Content.ReadAsStringAsync();
            Console.WriteLine(result2);
        }
    }
}
