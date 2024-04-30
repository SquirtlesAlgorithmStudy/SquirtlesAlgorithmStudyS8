import sys
input = sys.stdin.readline

N = int(input())
locations = list(map(int, input().split()))

locations.sort()
print(locations[(len(locations)-1) // 2])
