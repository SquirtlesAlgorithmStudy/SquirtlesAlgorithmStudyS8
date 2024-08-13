// 2531 conveyor belt sushi

// 1. 연속해서 k개 접시먹을 경우 정액
// 2. 처음과 끝이 연결되어 있기 때문에 %연산자를 사용하여 계속 돌게
// 3. 초밥 종류 하나가 쓰인 쿠폰을 발행, 하나를 추가로 무료 제공, belt위에 없을 경우 새로 만들어줌
// 4. 이미 먹은 초밥종류에 쿠폰이 포함되어 있으면 가짓수 늘리지 말기
// 5. 먼저 쿠폰에 초밥을 먹었다 가정하고 최댓값을 측정하면

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, d, k, c; // 접시수, 종류, 연속횟수, 쿠폰번호
int susi[30001];
int visited[30001]; // 이미 선택된 초밥?
int max_susi = 0;   // 최대 가짓수

int main()
{
    cin >> n >> d >> k >> c;

    // 연속된 k개 접시 선택
    for (int i = 0; i < n; i++)
    {
        cin >> susi[i];
    }

    for (int i = 0; i < n; i++)
    {
        int flag = 0;   // 중복된 초밥갯수를 세는
        int coupon = 1; // 가짓수에 포함되면 0, 아니면 1

        for (int j = i; j < i + k; j++)
        {
            if (!visited[susi[j % n]] == 1)
                visited[susi[j % n]] = true;
            else
                flag++; // 중복된 초밥 있음
        }
        if (visited[c])
            coupon = 0;
        max_susi = max(max_susi, k - flag + coupon);
        memset(visited, false, sizeof(visited));
    }
    cout << max_susi << endl;
    return 0;
}