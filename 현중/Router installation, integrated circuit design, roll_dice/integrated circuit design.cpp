// integrated circuit design

// 선이 꼬이지 않게 설계
// 1< n < 40,000

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX = 40000

using namespace std;

// n개의 port
int N;
int Arr[MAX]; // 수열을 저장할 배열

vector<int> V; // LIS를 저장할 벡터

void Input()
{
    cin >> N;
    for (int i = 0; i <= N; i++)
    {
        cin >> Arr[i];
    }
}

// LIS
void Solution()
{
}