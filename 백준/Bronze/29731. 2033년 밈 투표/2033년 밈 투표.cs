string[] arr = { "Never gonna give you up", "Never gonna let you down", "Never gonna run around and desert you", "Never gonna make you cry"
    , "Never gonna say goodbye", "Never gonna tell a lie and hurt you", "Never gonna stop"};

int n = int.Parse(Console.ReadLine());

bool[] flag = new bool[n];

bool result = false;

for (int i = 0; i < n; i++)
{
    string str = Console.ReadLine();

    foreach (string s in arr)
    {
        if(s == str)
        {
            flag[i] = true;
            break;
        }

        flag[i] = false;
    }
}

foreach (bool b in flag)
{
    result = b;

    if(!b)
    {
        Console.WriteLine("Yes");
        break;
    }
}

if(result) Console.WriteLine("No");