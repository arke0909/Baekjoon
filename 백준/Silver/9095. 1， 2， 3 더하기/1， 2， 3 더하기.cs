int n = int.Parse(Console.ReadLine());
            int[] list = new int[10];
            list[0] = 1;
            list[1] = 2;
            list[2] = 4;

            for (int i = 3; i < list.Length; i++)
            {
                list[i] = list[i - 1] + list[i - 2] + list[i - 3];
            }
            for (int i = 0; i < n; i++)
            {
                int num = int.Parse(Console.ReadLine());
                if (num > 11) return;
                Console.WriteLine(list[num - 1]);
            }