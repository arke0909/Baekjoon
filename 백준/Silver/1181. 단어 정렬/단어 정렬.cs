using System;
using System.Linq;

namespace BeakJoon
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            string[] words = new string[n];
            for (int i = 0; i < n; i++)
                words[i] = Console.ReadLine();

            words = words
                  .Distinct()
                  .OrderBy(w => w.Length)
                  .ThenBy(w => w)
                  .ToArray();

            foreach (var word in words)
                Console.WriteLine(word);
        }
    }
}