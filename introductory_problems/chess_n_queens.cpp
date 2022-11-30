#include <iostream>

using namespace std;

bool reserved[8][8], col[16], diag1[16], diag2[16];
int ans= 0;

void initialize()
{
    for(int i = 0; i < 8; i++)
    {
        col[i] = diag1[i] = diag2[i] = false;
        for(int j = 0; j < 8; j++)
            reserved[i][j] = false;
    }
}

void place_on_board(int r)
{
    if(r == 8)
    {
        ans++;
        return;
    }
    for(int c = 0; c < 8; c++)
    {
        if(col[c] || diag1[r + c] || diag2[r-c+7] || reserved[r][c])
            continue;
        col[c] = diag1[r + c] = diag2[r-c+7] = true;
        place_on_board(r + 1);
        col[c] = diag1[r + c] = diag2[r-c+7] = false;
    }
}

int main()
{
    string row;
    initialize();
    for(int i = 0; i < 8; i++)
    {
        getline(cin, row);
        for( int j = 0; j < 8; j++)
        {
            if(row[j] != '.')
                reserved[i][j] = true;
        }
    }
    place_on_board(0);
    cout << ans << "\n";
    return 0;
}