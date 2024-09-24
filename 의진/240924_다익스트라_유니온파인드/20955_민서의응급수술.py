import sys
input = sys.stdin.readline

N, M = map(int, input().split())
connections = [tuple(map(int, input().split())) for _ in range(M)]
parents = [i for i in range(N + 1)]

def find(x):
    if parents[x] != x:
        parents[x] = find(parents[x])  # Path compression
    return parents[x]

def union(x, y):
    parent_x = find(x)
    parent_y = find(y)
    if parent_x != parent_y:
        if parent_x <= parent_y:
            parents[parent_y] = parent_x 
        else:
            parents[parent_x] = parent_y

cut_cnt = 0

for x, y in connections:
    if find(x) == find(y):
        cut_cnt += 1  # Edge creates a cycle
    else:
        union(x, y)

parent_set = set(find(i) for i in range(1, N + 1))

result = cut_cnt + len(parent_set) - 1  # -1 because we want to connect components
print(result)
