#include <string>
#include <vector>

using namespace std;

string str[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int solution(string s) {
    for (int i = 0; i < 10; i++)
    {
        string item = str[i];
        if (s.find(item) != string::npos)
        {
            s.replace(s.find(item), item.length(), to_string(i));
            i = 0;
        }
    }

    int answer = stoi(s);
    return answer;
}