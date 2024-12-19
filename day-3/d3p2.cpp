#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    string str;
    char ch;
    int sum = 0;
    while (scanf("%c", &ch) != EOF)
    {
        str += ch;
    }
    int n = str.length();

    auto numberIs = [&](size_t &i)
    {
        int a = 0;
        while (a < 1000 && isdigit(str[i]))
        {
            a = a * 10 + str[i] - '0';
            i++;
        }
        if (1 <= a && a <= 999)
            return a;
        return -1;
    };
    bool dont = false;
    for (size_t i = 0; i < n; i++)
    {
        cout << str.substr(i, 7) << endl;
        if (str.substr(i, 7) == "don\'t()")
        {
            dont = true;
            i += 7;
        }
        if (str.substr(i, 4) == "do()")
        {
            dont = false;
            i += 4;
        }
        if (str.substr(i, 4) == "mul(")
        {
            i += 4;
            if (dont == true)
            {
                continue;
            }

            int a = (int)numberIs(i);
            if (str[i] == ',')
            {
                i += 1;
                int b = (int)numberIs(i);
                if (str[i] == ')')
                {
                    if (a != -1 && b != -1)
                    {
                        sum += a * b;
                    }
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
