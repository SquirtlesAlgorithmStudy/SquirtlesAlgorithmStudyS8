import sys
input = sys.stdin.readline

N, K = map(int, input().split())
students = list(map(int, input().split()))

diff_list = []
diff_sum = 0

for i in range(len(students)-1):
    diff = students[i+1] - students[i]
    diff_sum += diff
    diff_list.append(diff)

diff_list.sort(reverse=True)

for diff in diff_list[:K-1]:
    diff_sum -= diff
    
print(diff_sum)
