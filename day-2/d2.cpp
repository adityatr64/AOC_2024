#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

#define N 1000

int main(int argc, char *argv[])
{
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line); // Read entire line
        stringstream ss(line);
        vector<int> v;
        int num;

        while (ss >> num) // Parse integers from line
        {
            v.push_back(num);
        }

        int arrSize = v.size();
        if (arrSize < 2) // Skip reports with fewer than 2 levels
        {
            continue;
        }

        bool isGone = false;
        bool uping = true;
        bool downing = true;

        for (size_t i = 0; i < arrSize - 1; i++) // Check pairs
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

            if (abs(diff) < 1 || abs(diff) > 3) // Invalid difference
            {
                isGone = true;
                break;
            }
        }

        if (!isGone && (uping || downing)) // Check if safe
        {
            sum++;
        }
    }

    cout << sum << endl; // Output the total safe reports
    return 0;
}
