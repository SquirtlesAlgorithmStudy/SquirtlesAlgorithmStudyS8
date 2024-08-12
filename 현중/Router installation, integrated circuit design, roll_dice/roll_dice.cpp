#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#define endl "\n"
using namespace std;

int dice[10];
array<array<int, 6>, 33> board = {{{0, 1, 2, 3, 4, 5},
                                   {2, 3, 4, 5, 6, 7},
                                   {4, 5, 6, 7, 8, 9},
                                   {6, 7, 8, 9, 10, 11},
                                   {8, 9, 10, 11, 12, 13},
                                   {10, 11, 12, 13, 14, 15},
                                   {12, 13, 14, 15, 16, 17},
                                   {14, 15, 16, 17, 18, 19},
                                   {16, 17, 18, 19, 20, 21},
                                   {18, 19, 20, 21, 22, 23},
                                   {20, 21, 22, 23, 24, 25},
                                   {22, 23, 24, 25, 26, 27},
                                   {24, 25, 26, 27, 28, 29},
                                   {26, 27, 28, 29, 30, 31},
                                   {28, 29, 30, 31, 32, 32},
                                   {30, 32, 32, 32, 32, 32},
                                   {28, 30, 32, 32, 32, 32},
                                   {27, 29, 30, 32, 32, 32},
                                   {26, 28, 29, 30, 32, 32},
                                   {25, 27, 28, 29, 30, 32},
                                   {20, 26, 27, 28, 29, 30},
                                   {21, 25, 26, 27, 28, 29},
                                   {23, 24, 25, 26, 27, 28},
                                   {22, 23, 24, 25, 26, 27},
                                   {24, 25, 26, 27, 28, 29},
                                   {25, 27, 28, 29, 30, 32},
                                   {26, 28, 29, 30, 32, 32},
                                   {27, 29, 30, 32, 32, 32},
                                   {30, 32, 32, 32, 32, 32},
                                   {28, 30, 32, 32, 32, 32},
                                   {27, 31, 24, 25, 26, 20},
                                   {26, 24, 25, 26, 20, 32}}};
int ans = 0;

void dfs(array<int, 4> pawn, int diceIndex, int score)
{
    bool startZero = false;
    for (int i = 0; i < 4; ++i)
    {
        if (pawn[i] == 0)
        {
            if (startZero)
                continue;
            else
                startZero = true;
        }
        else if (pawn[i] == 32)
        {
            continue;
        }
        int ti = board[pawn[i]][dice[diceIndex]];
        if (find(pawn.begin(), pawn.end(), ti) == pawn.end() || ti == 32)
        {
            array<int, 4> tPawn = pawn;
            tPawn[i] = ti;
            if (diceIndex == 9)
            {
                ans = max(ans, score + board[ti][0]);
            }
            else
            {
                dfs(tPawn, diceIndex + 1, score + board[ti][0]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; ++i)
    {
        cin >> dice[i];
    }

    array<int, 4> pawn = {0, 0, 0, 0};
    dfs(pawn, 0, 0);
    cout << ans << endl;

    return 0;
}
