import sys
input = sys.stdin.readline

N, K = map(int, input().split())
items = [tuple(map(int, input().split())) for _ in range(N)]

dp = [[0] * (K+1) for _ in range(N)]

for i in range(K+1):
    if i >= items[0][0]:
        dp[0][i] = items[0][1]

for c in range(1, K+1):
    for r in range(1, N):
        dp[r][c] = dp[r-1][c]
        if c-items[r][0] >= 0:
            dp[r][c] = max(dp[r][c], dp[r-1][c-items[r][0]] + items[r][1])

print(dp[N-1][K])