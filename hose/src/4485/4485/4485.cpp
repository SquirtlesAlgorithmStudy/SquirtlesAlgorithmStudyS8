// 4485.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

/*
젤다의 전설 게임에서 화폐의 단위는 루피(rupee)다. 그런데 간혹 '도둑루피'라 불리는 검정색 루피도 존재하는데, 이걸 획득하면 오히려 소지한 루피가 감소하게 된다!

젤다의 전설 시리즈의 주인공, 링크는 지금 도둑루피만 가득한 N x N 크기의 동굴의 제일 왼쪽 위에 있다. [0][0]번 칸이기도 하다.
왜 이런 곳에 들어왔냐고 묻는다면 밖에서 사람들이 자꾸 "젤다의 전설에 나오는 녹색 애가 젤다지?"라고 물어봤기 때문이다. 
링크가 녹색 옷을 입은 주인공이고 젤다는 그냥 잡혀있는 공주인데, 게임 타이틀에 젤다가 나와있다고 자꾸 사람들이 이렇게 착각하니까 정신병에 걸릴 위기에 놓인 것이다.

하여튼 젤다...아니 링크는 이 동굴의 반대편 출구, 제일 오른쪽 아래 칸인 [N-1][N-1]까지 이동해야 한다. 동굴의 각 칸마다 도둑루피가 있는데, 이 칸을 지나면 해당 도둑루피의 크기만큼 소지금을 잃게 된다. 
링크는 잃는 금액을 최소로 하여 동굴 건너편까지 이동해야 하며, 한 번에 상하좌우 인접한 곳으로 1칸씩 이동할 수 있다.

링크가 잃을 수밖에 없는 최소 금액은 얼마일까?



입력

입력은 여러 개의 테스트 케이스로 이루어져 있다.

각 테스트 케이스의 첫째 줄에는 동굴의 크기를 나타내는 정수 N이 주어진다. (2 ≤ N ≤ 125) N = 0인 입력이 주어지면 전체 입력이 종료된다.

이어서 N개의 줄에 걸쳐 동굴의 각 칸에 있는 도둑루피의 크기가 공백으로 구분되어 차례대로 주어진다. 

도둑루피의 크기가 k면 이 칸을 지나면 k루피를 잃는다는 뜻이다. 여기서 주어지는 모든 정수는 0 이상 9 이하인 한 자리 수다.



출력

각 테스트 케이스마다 한 줄에 걸쳐 정답을 형식에 맞춰서 출력한다. 형식은 예제 출력을 참고하시오.


예제 입력 1
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

예제 출력

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
    
    // 위치, 비용

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