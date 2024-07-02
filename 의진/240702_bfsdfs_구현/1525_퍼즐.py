import sys
from collections import deque
input = sys.stdin.readline

visited = set()


def from_2d_to_1d(r, c):
    return 3 * r + c


def from_1d_to_2d(idx):
    return (idx // 3, idx % 3)


def str_swap(left, right, text):
    text = list(text)
    text[left], text[right] = text[right], text[left]
    text = "".join(text)
    return text


dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]

board = []
for _ in range(3):
    board += list(input().rstrip().split())

zero_idx = board.index("0")
init_state = ("".join(board), zero_idx)


def bfs(start_state):
    q = deque()
    q.append((start_state, 0))
    visited.add(start_state)

    while q:
        state, depth = q.popleft()
        if state[0] == "123456780":
            return depth

        r, c = from_1d_to_2d(state[1])
        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if nr < 0 or nr > 2 or nc < 0 or nc > 2:
                continue

            next_idx = from_2d_to_1d(nr, nc)
            next_state_str = str_swap(state[1], next_idx, state[0])

            next_state = (next_state_str, next_idx)

            if next_state in visited:
                continue

            q.append((next_state, depth + 1))
            visited.add(next_state)
    return -1


print(bfs(init_state))
