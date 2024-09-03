n = int(input())

arr = [list(map(int, input().split())) for _ in range(n)]
arr = [a for a, _ in arr] + [arr[-1][1]]
dp = [[0] * n for _ in range(n)]

for step in range(1,n):
    for loc in range(n-step):
        end = loc + step
        mul = arr[loc] * arr[end+1]
        minimum =  min(yk + xk + sz * mul for yk, xk, sz in zip(dp[loc][loc:end], dp[end][loc+1:end+1], arr[loc+1:end+1]))
        dp[loc][end] = dp[end][loc] = minimum

print(dp[0][-1])


# 1. 1차원으로 Matrix Shape 접근
# 2. Slicing과 Zip 함수 이용 -> 최적화된 실행을 보여줌