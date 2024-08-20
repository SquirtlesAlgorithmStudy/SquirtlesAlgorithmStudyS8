// 2839 deliver sugar

// 1. greedy
#include <iostream>

using namespace std;

int N;
int main()
{
    cin >> N;    // 설탕무게
    int ans = 0; // 봉지갯수
    while (N >= 0)
    {
        if (N % 5 == 0)
        {                   // 5로 나눌 수 있는가?
            ans += (N / 5); // 있다면 몫이 정답
            cout << ans << endl;
            return 0;
        }
        // 5로 나눌 수 없는가?
        N -= 3; // 3kg을 빼고
        ans++;  // 3키로 설탕가방 +1
    }
    cout << -1 << endl; // 5,3으로 나눌수 없으면 -1출력
}

// 2.DP
#include <iostream>

using namespace std;

int dp[5001];

int main()
{
    int n;
    cin >> n;
    // 3,5kg를 만드는 가장 최소의 봉지수 = 1
    dp[3] = dp[5] = 1;

    // 3과 5 다음 6부터
    for (int i = 6; i <= n; i++)
    {
        if (dp[i - 3])
            dp[i] = dp[i - 3] + 1;

        // dp[i-3]에 값이 존재 : dp[i]가 업데이트 됐었을 수 있다.
        // dp[i]에 값이 없다면 : dp[i] = dp[i-5] +1 로 업데이트
        if (dp[i - 5])
            dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
    }

    cout << (dp[n] == 0 ? -1 : dp[n]) << endl;

    return 0;
}
