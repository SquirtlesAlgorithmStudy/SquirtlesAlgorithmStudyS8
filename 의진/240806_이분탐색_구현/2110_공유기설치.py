import sys
input = sys.stdin.readline

N, C = map(int, input().split())
houses = [int(input()) for _ in range(N)]
houses.sort()

start = 1
end = houses[-1] - houses[0]


def is_possible(houses, test_dist):
    remain = C-1
    current_house = houses[0]
    for i in range(len(houses)-1):
        if houses[i+1] - current_house >= test_dist:
            current_house = houses[i+1]
            remain -= 1
            if remain == 0:
                return True
    return False


while start <= end:
    mid = (start + end) // 2
    if is_possible(houses, mid):
        start = mid + 1
    else:
        end = mid - 1

print(end)
