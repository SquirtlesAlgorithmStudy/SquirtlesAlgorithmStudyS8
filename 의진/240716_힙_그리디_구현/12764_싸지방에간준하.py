import sys
import heapq
input = sys.stdin.readline

N = int(input())
people = [tuple(map(int, input().split())) for _ in range(N)]

pq_person = []
pq_pc = []
now_pc = 0
pc_info_list = [0 for _ in range(N)]
person_idx2pc = [-1 for _ in range(N)]

for idx, person in enumerate(people):
    heapq.heappush(pq_person, (person[0], "Start", idx))
    heapq.heappush(pq_person, (person[1], "End", idx))

while pq_person:
    item = heapq.heappop(pq_person)
    idx = item[2]
    if item[1] == "Start":
        if pq_pc:
            pc = heapq.heappop(pq_pc)
        else:
            pc = now_pc
            now_pc += 1
        pc_info_list[pc] += 1
        person_idx2pc[idx] = pc

    else:
        pc = person_idx2pc[idx]
        heapq.heappush(pq_pc, pc)

print(now_pc)
for item in pc_info_list[:now_pc]:
    print(item, end=" ")
