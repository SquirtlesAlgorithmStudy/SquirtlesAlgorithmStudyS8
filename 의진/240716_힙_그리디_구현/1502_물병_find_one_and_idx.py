import sys
input = sys.stdin.readline

n, k = map(int, input().split())

result = 0


def find_one_and_idx(n):
    one_count = 0
    idx_cnt = 0
    first_one_idx = -1
    while n != 0:
        if n % 2 == 1:
            one_count += 1
            if first_one_idx == -1:
                first_one_idx = idx_cnt
        n //= 2
        idx_cnt += 1
    return one_count, first_one_idx


while True:
    one_count, first_one_index = find_one_and_idx(n)
    if one_count <= k:
        break
    result += 2 ** first_one_index
    n += 2 ** first_one_index

print(result)
