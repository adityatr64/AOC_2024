#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

// #define N 1000

bool notdying(vector<int> v)
{
    int arrSize = v.size();
    bool fine = true;
    bool uping = true;
    bool downing = true;

    for (size_t i = 0; i < arrSize - 1; i++)

    {
        int diff = v[i + 1] - v[i];

        if (diff > 0)
        {
            downing = false;
        }
        if (diff < 0)
        {
            uping = false;
        }

        if (abs(diff) < 1 || abs(diff) > 3)
        {
            fine = false;
            break;
        }
    }
    return fine && (uping || downing);
}

int main(int argc, char *argv[])
{
    int sum = 0;
    int N = 1000;
    while (N--)
    {
        string line;
        getline(cin, line); // Read entire line
        stringstream ss(line);
        vector<int> v;
        int num;

        while (ss >> num)
        {
            v.push_back(num);
        }
        bool isGone = true;
        auto checkWithout = [&](int i)
        {
            vector<int> v2 = v;
            v2.erase(v2.begin() + i);
            if (notdying(v2))
            {
                isGone = false;
            }
        };
        int arrSize = v.size();
        checkWithout(0);
        for (int i = 0; i < arrSize - 1; i++)
        {
            int delta = v[i + 1] - v[i];
            if (abs(delta) < 1 || abs(delta) > 3)
            {
                checkWithout(i);
                checkWithout(i + 1);
                break;
            }
            if (i + 2 < arrSize)
            {
                int delta2 = v[i + 2] - v[i + 1];
                if ((delta > 0) != (delta2 > 0))
                {
                    checkWithout(i);
                    checkWithout(i + 1);
                    checkWithout(i + 2);
                    break;
                }
            }
        }
        if (!isGone)
        {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
