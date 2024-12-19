#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    int Height = 140, sum = 0;
    vector<string> v(Height);
    for (string &row : v)
    {
        getline(cin, row);
    }
    int Width = v[0].length();

    auto inside = [&](int r, int c)
    {
        return 0 <= r && r < Height && 0 <= c && c < Width;
    };
    const string temp = "XMAS";
    const int len = temp.length();

    for (int s = 0; s < Height; s++)
    {
        for (size_t col = 0; col < Width; col++)
        {
            if (v[s][col] == 'X')
            {
                for (int rowDir = -1; rowDir <= 1; rowDir++)
                {
                    for (int colDir = -1; colDir <= 1; colDir++)
                    {
                        if (rowDir == 0 && colDir == 0)
                            continue; // skip ,cos why tf do u wanna not go anywhere
                        bool isNotDying = true;
                        for (size_t i = 0; i < len; i++)
                        {
                            int r2 = s + rowDir * i;
                            int c2 = col + colDir * i;

                            if (!inside(r2, c2) || v[r2][c2] != temp[i])
                            {
                                isNotDying = false;
                                break;
                            }
                        }
                        sum += isNotDying;
                    }
                }
            }
        }
    }

    cout << sum << endl;
    return 0;
}
