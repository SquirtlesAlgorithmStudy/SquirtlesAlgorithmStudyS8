#include <iostream>

using namespace std;

const int MOD = 1000000000;

int main() {
    int N, K;
    cin >> N >> K;

    // 2차원 배열 선언
    int dp[201][201] = {0};

    // 초기 조건: dp[0][k] = 1 (0을 k개의 숫자로 만드는 방법은 1가지)
    for (int k = 1; k <= K; ++k) {
        dp[0][k] = 1;
    }

    // dp 테이블 채우기
    for (int n = 1; n <= N; ++n) {
        for (int k = 1; k <= K; ++k) {

            // k개의 숫자로 n을 만드는 방법 = k-1개의 숫자로 n을 만드는 방법 + k개의 숫자로 n-1을 만드는 방법
            dp[n][k] = (dp[n-1][k] + dp[n][k-1]) % MOD;
        }
    }

    // 결과 출력
    cout << dp[N][K] << endl;

    return 0;
}
