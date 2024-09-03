import sys
input = sys.stdin.readline

N = int(input())
prices = [tuple(map(int, input().split())) for _ in range(N)]

dp = []
dp.append([prices[0][i] for i in range(3)])
for _ in range(N-1):
    dp.append([0, 0, 0])

for i in range(1, N):
    for j in range(3):
        dp[i][j] = min(dp[i-1][((j+1) % 3)], dp[i-1][((j+2) % 3)]) +\
            prices[i][j]


print(min(dp[N-1]))