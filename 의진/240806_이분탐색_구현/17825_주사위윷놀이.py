import sys
import copy
dice_result = list(map(int, input().split()))

board = {i: i*2 for i in range(20)}
board.update({99: 10, 100: 13, 101: 16, 102: 19, 199: 20, 200: 22, 201: 24,
              299: 30, 300: 28, 301: 27, 302: 26, 400: 25, 401: 30, 402: 35,
              500: 40, 600: 0})
answer = 0


def get_next_node(step, current_pos):
    new_pos = step + current_pos
    if new_pos == 5:
        return 99
    if new_pos == 10:
        return 199
    if new_pos == 15:
        return 299
    if new_pos == 20 or new_pos == 403:
        return 500
    if 20 < new_pos < 99 or 403 < new_pos < 499 or 500 < new_pos < 599:
        return 600

    if 201 < new_pos < 299:
        new_pos = new_pos + 198
        if new_pos == 403:
            return 500
        if new_pos > 403:
            return 600

    for i in [1, 3]:
        if (i * 100 + 2) < new_pos < (i * 100 + 99):
            new_pos = (new_pos - (i * 100) + 397)
            if new_pos == 403:
                return 500
            if new_pos == 404:
                return 600
            return new_pos
    return new_pos


def dfs(state, current_score, turn):
    global answer
    # print(state)
    if turn == 10:
        answer = max(answer, current_score)
        return
    for i in range(4):
        if state[i] == 600:
            continue
        n_pos = get_next_node(dice_result[turn], state[i])
        # print(f"n_pos ={n_pos}")
        if n_pos not in state or n_pos == 600:
            cache = state[i]
            state[i] = n_pos
            # print(f"score={board[n_pos]}")
            dfs(state, current_score + board[n_pos], turn + 1)
            state[i] = cache


dfs([0, 0, 0, 0], 0, 0)
print(answer)
