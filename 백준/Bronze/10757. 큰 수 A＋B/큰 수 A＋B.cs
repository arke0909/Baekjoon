using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace BackJune
{
    class Program
    {
        static void Main(string[] args)
        {
            BigInteger[] ab = Array.ConvertAll(Console.ReadLine().Split(' '), BigInteger.Parse);
            Console.WriteLine(ab[0] + ab[1]);
        }
    }
}
