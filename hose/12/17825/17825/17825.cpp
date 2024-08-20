// 17825.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int dice[10];

int horse[4];

int board[33];

int result = 0;

void dfs(int cnt, int sum)
{
	if (cnt == 10)
	{
		if (result < sum)
		{
			result = sum;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int cur = horse[i];
		int next = cur;
		int move = dice[cnt];


		if (cur == 5 || cur == 10 || cur == 15)
		{
			next = board[cur];
			move--;
		}

		while (move--)
		{
			next = board[next];
		}

		if (next != 21 && board[next] != 21)
		{
			bool flag = true;
			for (int j = 0; j < 4; j++)
			{
				if (i != j && horse[j] == next)
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				horse[i] = next;
				dfs(cnt + 1, sum + board[next]);
				horse[i] = cur;
			}
		}
		else
		{
			horse[i] = next;
			dfs(cnt + 1, sum);
			horse[i] = cur;
		}
	}
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> dice[i];
	}

	for (int i = 0; i <= 20; i++)
	{
		board[i] = i + 1;
	}

	board[21] = 21;
	board[22] = 23;
	board[23] = 24;
	board[24] = 30;
	board[25] = 26;
	board[26] = 30;
	board[27] = 28;
	board[28] = 29;
	board[29] = 30;
	board[30] = 31;
	board[31] = 32;
	board[32] = 20;

	dfs(0, 0);

	cout << result << endl;

	return 0;
}

