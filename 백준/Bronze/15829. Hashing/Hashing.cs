int n = int.Parse(Console.ReadLine());
            string str = Console.ReadLine();
            int result = 0,multiply = 1;

            for (int i = 0; i < n; i++, multiply *= 31)
            {
                result += (str[i] - 96) * multiply;
            }
                Console.WriteLine(result);