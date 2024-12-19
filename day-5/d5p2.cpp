
#include <bits/stdc++.h>
using namespace std;

// using global cos i can't be bothered to pass it around
// lmao co-pilot just auto added this comment
map<int, vector<int>> edge;

void topo(int a, vector<int> &order, map<int, int> &in, const set<int> &present)
{
  order.push_back(a);
  for (int b : edge[a])
  {
    if (present.count(b))
    {

      if (--in[b] == 0)
      {
        topo(b, order, in, present);
      }
    }
  }
}

int main(int argc, char *argv[])
{
  string str;
  int sum = 0;
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

      map<int, int> in;
      set<int> present;
      for (int a : v)
      {
        present.insert(a);
      }

      for (size_t i = 0; i < v.size(); i++)
      {
        int a = v[i];
        for (int b : edge[a])
        {
          if (present.count(b))
          {
            in[b]++;
          }
          if (before.count(b))
          {
            ded = true;
          }
        }
        before.insert(a);
      }
      if (!ded)
      {
        // sum += v[v.size() / 2];
      }
      else
      {
        // swap
        vector<int> order;
        vector<int> start;
        for (int a : v)
        {
          if (in[a] == 0)
          {
            start.push_back(a);
          }
        }
        for (int a : start)
        {
          topo(a, order, in, present);
        }
        sum += (order[order.size() / 2]);
      }
    }
  }
  cout << sum << endl;
  return 0;
}