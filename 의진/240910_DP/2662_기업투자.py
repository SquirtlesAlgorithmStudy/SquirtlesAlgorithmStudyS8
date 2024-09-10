import sys
import copy
input = sys.stdin.readline

N, M = map(int, input().split())
enterprise_table = [[0, 0, 0]] + \
    [list(map(int, input().split())) for _ in range(N)]

dp = [[0] * (N + 1) for _ in range(M+1)]
info = [[[]] * (N + 1) for _ in range(M+1)]

for enterprise in range(1, M+1):
    info[enterprise][0] = [0] * enterprise

for weight in range(1, N+1):
    dp[1][weight] = enterprise_table[weight][1]
    info[1][weight] = [weight]

for i in range(2, M+1):
    for w_limit in range(N+1):
        dp[i][w_limit] = dp[i-1][w_limit]
        info[i][w_limit] = copy.copy(info[i-1][w_limit])
        info[i][w_limit].append(0)
        for w_add in range(1, N+1):
            if w_limit - w_add >= 0:
                if dp[i][w_limit] < dp[i-1][w_limit - w_add] + enterprise_table[w_add][i]:
                    dp[i][w_limit] = dp[i-1][w_limit - w_add] + \
                        enterprise_table[w_add][i]
                    info[i][w_limit] = copy.copy(info[i-1][w_limit-w_add])
                    info[i][w_limit].append(w_add)

print(dp[M][N])
print(*info[M][N])