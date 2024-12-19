#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <map>       // for map
#include <cmath>     // for abs
#include <cstddef>   // for size_t

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
    }
    map<int, int> m;
    for (auto i : b)
    {
        m[i]++;
    }
    long long sum = 0;
    for (size_t i = 0; i < N; i++)
    {

        sum += a[i] * m[a[i]];
    }
    cout << sum << endl;
    return 0;
}
