import sys
from collections import deque
input = sys.stdin.readline

N, L, R = map(int, input().split())
populations = [list(map(int, input().split())) for _ in range(N)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
count = 1
visited = [[0] * N for _ in range(N)]
results = [0]


def bfs(r, c, area_num):
    is_changed = False
    q = deque()
    q.append((r, c))
    visited[r][c] = area_num
    population_count = populations[r][c]
    nation_count = 1
    next = set()
    changed_nation = set()
    while q:
        y, x = q.popleft()
        candidate_count = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < N and visited[ny][nx] == area_num:
                candidate_count += 1

            if 0 <= nx < N and 0 <= ny < N and visited[ny][nx] == 0 and L <= abs(populations[y][x] - populations[ny][nx]) <= R:
                visited[ny][nx] = area_num
                population_count += populations[ny][nx]
                nation_count += 1
                is_changed = True
                candidate_count += 1
                q.append((ny, nx))
        if 1 <= candidate_count <= 3:
            next.add((y, x))
        if candidate_count >= 1:
            changed_nation.add((y, x))
    results.append(population_count // nation_count)
    return is_changed, next, changed_nation


is_changed = True
result_count = 0
new_candidate = {(r, c) for r in range(N) for c in range(r % 2, N, 2)}
next_candidate = set()
while is_changed:
    results = [0]
    visited = [[0] * N for _ in range(N)]
    is_changed = False
    visited_count = 0
    next_candidate = new_candidate
    new_candidate = set()
    changed_nation = set()
    for r, c in next_candidate:
        if not visited[r][c]:
            visited_count += 1
            if is_changed is False:
                is_changed, next, changed = bfs(r, c, visited_count)
            else:
                _, next, changed = bfs(r, c, visited_count)
            new_candidate = next | new_candidate
            changed_nation = changed | changed_nation
    for r, c in changed_nation:
        populations[r][c] = results[visited[r][c]]
    if is_changed is True:
        result_count += 1
print(result_count)
