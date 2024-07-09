import sys
from collections import deque
from pprint import pprint
input = sys.stdin.readline

T = int(input())

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]


def bfs(start, fire_pos, visited):
    q = deque()
    visited[start[0]][start[1]] = True
    q.append((start, 0))
    cur_depth = -1

    while q:
        pos, depth = q.popleft()
        r = pos[0]
        c = pos[1]

        if cur_depth < depth:
            cur_depth = depth
            new_fire_pos = []
            for fire in fire_pos:
                for i in range(4):
                    nr = fire[0] + dr[i]
                    nc = fire[1] + dc[i]
                    if nr < 0 or nr == h or nc < 0 or nc == w:
                        continue
                    if board[nr][nc] == ".":
                        board[nr][nc] = "*"
                        new_fire_pos.append((nr, nc))

                fire_pos = new_fire_pos

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]
            if nr < 0 or nr == h or nc < 0 or nc == w:
                return depth + 1
            if board[nr][nc] != ".":
                continue
            if visited[nr][nc] == True:
                continue

            visited[nr][nc] = True
            q.append(((nr, nc), depth + 1))

    return "IMPOSSIBLE"


for _ in range(T):
    w, h = map(int, input().split())
    board = [list(input().strip()) for _ in range(h)]
    visited = [[False] * w for _ in range(h)]

    fire_pos = []

    for r in range(h):
        for c in range(w):
            if board[r][c] == "@":
                start = (r, c)
                board[r][c] = "."
            elif board[r][c] == "*":
                fire_pos.append((r, c))

    print(bfs(start, fire_pos, visited))
