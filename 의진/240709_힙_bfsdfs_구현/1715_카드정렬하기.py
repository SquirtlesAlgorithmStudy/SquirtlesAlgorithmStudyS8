import heapq
import sys

input = sys.stdin.readline

N = int(input())
num_list = [int(input()) for _ in range(N)]

if N == 1:
    print(0)
    sys.exit()

heapq.heapify(num_list)

ans = 0

while len(num_list) > 1:
    first_card = heapq.heappop(num_list)
    second_card = heapq.heappop(num_list)
    grouped = first_card + second_card
    ans += grouped
    heapq.heappush(num_list, grouped)

print(ans)
