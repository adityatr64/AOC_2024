
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  string str;
  int sum = 0;
  map<int, vector<int>> edge;
  cout << "bruh World!" << endl;
  while (getline(cin, str))
  {
    if (str.empty() || !isdigit(str[0]))
    {
      continue;
    }
    vector<int> v;
    bool pipe = false;
    int len = str.length();
    for (size_t i = 0; i < len; i++)
    {
      if (isdigit(str[i]))
      {
        int x = 0;
        while (isdigit(str[i]))
        {
          x = x * 10 + (str[i] - '0');
          i++;
        }
        v.push_back(x);
        switch (str[i])
        {
        case '|':
          pipe = true;
          break;
        case 0:
        case ',':
        case '\n':
          break;
        default:
          cout << "BRO WTF is \'" << str[i] << "\' at position " << i << endl;
        }
      }
    }
    if (pipe)
    {
      edge[v[0]].push_back(v[1]);
    }
    else
    {
      set<int> before;
      bool ded = false;
      for (size_t i = 0; i < v.size(); i++)
      {
        int a = v[i];
        for (int b : edge[a])
        {
          if (before.count(b))
          {
            ded = true;
          }
        }
        before.insert(a);
      }
      if (!ded)
      {
        sum += v[v.size() / 2];
      }
      else
      {
        // swap
      }
    }
  }
  cout << sum << endl;
  return 0;
}