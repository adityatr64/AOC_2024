#include <iostream>
#include <vector>
using namespace std;

const vector<pair<int, int>> dirs = {
    {-1, -1},
    {-1, 1},
    {1, 1},
    {1, -1}};

int main(int argc, char *argv[])
{
  int Height = 140, sum = 0;
  vector<string> v(Height);
  for (string &row : v)
  {
    getline(cin, row);
  }
  int Width = v[0].length();

  for (int s = 1; s < Height - 1; s++)
  {
    for (size_t col = 1; col < Width - 1; col++)
    {
      if (v[s][col] == 'A')
      {
        string str;
        for (pair<int, int> dir : dirs)
        {
          str += v[s + dir.first][col + dir.second];
        }
        if (str == "MMSS" || str == "MSSM" || str == "SSMM" || str == "SMMS")
        {
          sum++;
        }
      }
    }
  }
  cout << sum << endl;
  return 0;
}
