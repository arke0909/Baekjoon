using System;
using System.Numerics;

namespace BeakJoon
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string str = Console.ReadLine();
            BigInteger result = 0;
            BigInteger multiply = 1;

            for (int i = 0; i < n; i++, multiply *= 31)
            {
                result += (str[i] - 'a' + 1) * multiply;
            }
                Console.WriteLine(result % 1234567891);
        }
    }
}
