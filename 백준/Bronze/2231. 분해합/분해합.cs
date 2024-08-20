int n = int.Parse(Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                int a = i;
                int b = i;

                 while (a > 0)
                {
                    b += a % 10;
                    a /= 10;
                }

                 if (b == n)
                {
                    Console.WriteLine(i);
                    n = 0;
                    break;
                }
            }
            if (n != 0) Console.WriteLine(0);