#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <cmath>     // for abs
#include <cstdlib>   // for size_t

#define N 1000
using namespace std; // to avoid writing std everywhere
int main(int argc, char *argv[])
{
    vector<int> a, b;
    for (size_t i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
        /* code */
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        sum += abs(a[i] - b[i]);
    }

    cout << sum << endl;

    return 0;
}
