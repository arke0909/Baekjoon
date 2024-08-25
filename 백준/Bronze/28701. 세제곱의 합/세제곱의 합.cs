using System;
using System.Numerics;

namespace BeakJoon
{
    class Program
    {
        static void Main(string[] args)
        {
            BigInteger n = int.Parse(Console.ReadLine());
            int result = 1, result1 = 1;
            for (int i = 2; i <= n; i++)
            {
                result += i;
                result1 += i * i * i;    
            }
            Console.WriteLine(result);
            Console.WriteLine(result * result);
            Console.WriteLine(result1);

        }
    }
}
