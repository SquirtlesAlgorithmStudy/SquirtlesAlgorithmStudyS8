// 4485.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

/*
������ ���� ���ӿ��� ȭ���� ������ ����(rupee)��. �׷��� ��Ȥ '���Ϸ���'�� �Ҹ��� ������ ���ǵ� �����ϴµ�, �̰� ȹ���ϸ� ������ ������ ���ǰ� �����ϰ� �ȴ�!

������ ���� �ø����� ���ΰ�, ��ũ�� ���� ���Ϸ��Ǹ� ������ N x N ũ���� ������ ���� ���� ���� �ִ�. [0][0]�� ĭ�̱⵵ �ϴ�.
�� �̷� ���� ���Գİ� ���´ٸ� �ۿ��� ������� �ڲ� "������ ������ ������ ��� �ְ� ������?"��� ����ñ� �����̴�. 
��ũ�� ��� ���� ���� ���ΰ��̰� ���ٴ� �׳� �����ִ� �����ε�, ���� Ÿ��Ʋ�� ���ٰ� �����ִٰ� �ڲ� ������� �̷��� �����ϴϱ� ���ź��� �ɸ� ���⿡ ���� ���̴�.

�Ͽ�ư ����...�ƴ� ��ũ�� �� ������ �ݴ��� �ⱸ, ���� ������ �Ʒ� ĭ�� [N-1][N-1]���� �̵��ؾ� �Ѵ�. ������ �� ĭ���� ���Ϸ��ǰ� �ִµ�, �� ĭ�� ������ �ش� ���Ϸ����� ũ�⸸ŭ �������� �Ұ� �ȴ�. 
��ũ�� �Ҵ� �ݾ��� �ּҷ� �Ͽ� ���� �ǳ������ �̵��ؾ� �ϸ�, �� ���� �����¿� ������ ������ 1ĭ�� �̵��� �� �ִ�.

��ũ�� ���� ���ۿ� ���� �ּ� �ݾ��� ���ϱ�?



�Է�

�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�.

�� �׽�Ʈ ���̽��� ù° �ٿ��� ������ ũ�⸦ ��Ÿ���� ���� N�� �־�����. (2 �� N �� 125) N = 0�� �Է��� �־����� ��ü �Է��� ����ȴ�.

�̾ N���� �ٿ� ���� ������ �� ĭ�� �ִ� ���Ϸ����� ũ�Ⱑ �������� ���еǾ� ���ʴ�� �־�����. 

���Ϸ����� ũ�Ⱑ k�� �� ĭ�� ������ k���Ǹ� �Ҵ´ٴ� ���̴�. ���⼭ �־����� ��� ������ 0 �̻� 9 ������ �� �ڸ� ����.



���

�� �׽�Ʈ ���̽����� �� �ٿ� ���� ������ ���Ŀ� ���缭 ����Ѵ�. ������ ���� ����� �����Ͻÿ�.


���� �Է� 1
3
5 5 4
3 9 1
3 2 7
5
3 7 2 0 1
2 8 0 9 1
1 2 1 8 1
9 8 9 2 0
3 6 5 1 5
7
9 0 5 1 1 5 3
4 1 2 1 6 5 3
0 7 6 1 6 8 5
1 1 7 8 3 2 3
9 4 0 7 6 4 1
5 8 3 2 4 8 3
7 4 8 4 8 3 4
0

���� ���

Problem 1: 20
Problem 2: 19
Problem 3: 36



*/


#define INT_MAX 2147483647

int N;
int board[125][125];
int cost[125][125] = { INT_MAX, };
bool visited[125][125] = { false, };

int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };



struct CompareNode {
	bool operator()(const pair<pair<int, int>, int>& a,
		const pair<pair<int, int>, int>& b) const {
		return a.second > b.second;
	}
};



void dijkstra()
{
    
    // ��ġ, ���

	priority_queue<pair<pair<int, int>, int>,
		vector<pair<pair<int, int>, int>>,
		CompareNode> pq;


    pq.push({ {0, 0}, board[0][0] });

    cost[0][0] = board[0][0];

    while (!pq.empty())
    {
		int r = pq.top().first.first;
		int c = pq.top().first.second;

		int curCost = pq.top().second;

		pq.pop();

		if (visited[r][c])
			continue;

		visited[r][c] = true;

		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;

			if (cost[nr][nc] > curCost + board[nr][nc])
			{
				cost[nr][nc] = curCost + board[nr][nc];
				pq.push({ {nr, nc}, cost[nr][nc] });
			}
		}
	}

}





int main()
{

	int problem = 1;

	while (1)
	{
		cin >> N;

		if (N == 0)
			break;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
				cost[i][j] = INT_MAX;
				visited[i][j] = false;
			}
		}

		dijkstra();

		cout << "Problem " << problem << ": " << cost[N - 1][N - 1] << endl;

		problem++;
	}

	return 0;

}