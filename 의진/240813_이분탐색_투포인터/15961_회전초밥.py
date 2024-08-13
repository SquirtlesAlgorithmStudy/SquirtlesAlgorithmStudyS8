import sys
input = sys.stdin.readline

N, d, k, c = map(int, input().split())
items = [int(input()) for _ in range(N)]

start = 0
end = k-1

item_dict = {}
for i in range(k):
    if item_dict.get(items[i]) is not None:
        item_dict[items[i]] += 1
    else:
        item_dict[items[i]] = 1

if item_dict.get(c) is not None:
    item_dict[c] += 1
else:
    item_dict[c] = 1

max_val = len(item_dict.keys())

for _ in range(N):
    if item_dict[items[start]] == 1:
        del item_dict[items[start]]
    else:
        item_dict[items[start]] -= 1

    start = (start + 1) % N
    end = (end + 1) % N

    if item_dict.get(items[end]) is not None:
        item_dict[items[end]] += 1
    else:
        item_dict[items[end]] = 1

    max_val = max(max_val, len(item_dict.keys()))

print(max_val)
