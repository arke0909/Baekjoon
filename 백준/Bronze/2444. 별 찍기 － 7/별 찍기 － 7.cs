int n = int.Parse(Console.ReadLine());

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = n - i - 1; j > 0; j--)
                {
                    Console.Write(" ");
                }

                for (int j = 0; j < 2 * i + 1; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }


            for (int i = 0; i < n; i++)
            {
                for (int j = n - i; j < n; j++)
                {
                    Console.Write(" ");
                }

                for (int j = 2 * (n - i)- 1; j > 0; j--)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }