int n = int.Parse(Console.ReadLine());

            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    Console.Write("*");
                }

                for (int j = 2 * (n - i); j > 0; j--)
                {
                    Console.Write(" ");
                }

                for (int j = 0; j < i; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }

            for (int i = 1; i < n; i++)
            {
                for (int j = i; j < n; j++)
                {
                    Console.Write('*');
                }

                for (int j = 0; j < i * 2; j++)
                {
                    Console.Write(' ');
                }

                for (int j = i; j < n; j++)
                {
                    Console.Write('*');
                }
                Console.WriteLine();
            }