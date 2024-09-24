import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
candy = [0] + list(map(int, input().split())) 
connections = [tuple(map(int, input().split())) for _ in range(M)]

parents = [i for i in range(N+1)]
reward = [0] * (N+1)

if K == 1:
    print(0)
    sys.exit()

def find(x):
    if parents[x] != x:
        parents[x] = find(parents[x])
    return parents[x]

def union(x, y):
    parent_x = find(x)
    parent_y = find(y)
    if parent_x <= parent_y:
        parents[parent_y] = parent_x 
    else:
        parents[parent_x] = parent_y


for connection in connections:
    union(connection[0], connection[1])
    
reward_info = {}    
for i in range(1, N+1):
    parent = find(i)
    if reward_info.get(parent) is None:
        reward_info[parent] = [candy[i] ,1]
    else:
        reward_info[parent][0] += candy[i]
        reward_info[parent][1] += 1

reward_info = list(reward_info.values())

dp = [[0] * (len(reward_info)) for _ in range(K+1)]

for i in range(K+1):
    if i >= reward_info[0][1]:
        dp[i][0] = reward_info[0][0]

for i in range(1, len(reward_info)):
    for j in range(1, K+1):
        if j - reward_info[i][1] >= 0:
            dp[j][i] = max(dp[j][i-1], dp[j-reward_info[i][1]][i-1] + reward_info[i][0])
        else:
            dp[j][i] = dp[j][i-1]

print(dp[-2][-1])
    