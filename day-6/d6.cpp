#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(int argc, char *argv[])
{
  int height = 130;
  vector<string> s(height);
  for (size_t i = 0; i < height; i++)
  {
    cin >> s[i];
  }
  int width = s[0].length();

  pair<int, int> me;
  int dir = 0;

  for (size_t i = 0; i < height; i++)
  {
    for (size_t j = 0; j < width; j++)
    {
      if (s[i][j] == '^')
      {
        me = {i, j};
        s[i][j] = '.';
      }
    }
  }
  while (true)
  {
    int r2 = me.first + dir[dir].first;
    int c2 = me.second + dir[dir].second;
    if (!(0 <= r2 && r2 < height && 0 <= c2 && c2 < width))
    {
      me = {r2, c2};
    }
    else
    {
      dir = (dir + 1) % 4;// 90 degreree turn basically
    }
  }

  return 0;
}