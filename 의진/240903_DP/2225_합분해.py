import sys
input = sys.stdin.readline

N, K = map(int, input().split())

dp = [[0] * (K+1) for _ in range(N+1)]

for i in range(N+1):
    dp[i][1] = 1
# for i in range(K+1):
#     dp[0][i] = 1

for c in range(2, K+1):
    for r in range(1, N+1):
        dp[r][c] = dp[r-1][c] + dp[r][c-1]

print(dp[N][K] % 1000000000)


