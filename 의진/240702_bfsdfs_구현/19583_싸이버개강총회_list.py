# List 이용 : Time Out
import sys
input = sys.stdin.readline


def time_to_regular_form(time: str):
    hour, minute = map(int, time.split(":"))
    regular_form = hour * 60 + minute
    return regular_form


def log_line_to_info(log_line: str):
    time, name = log_line.split()
    time = time_to_regular_form(time)
    return time, name


infos = list(input().rstrip().split())
S = time_to_regular_form(infos[0])
E = time_to_regular_form(infos[1])
Q = time_to_regular_form(infos[2])

# print(S, E, Q)

ans = 0
enter_check = []
while True:
    try:
        log_line = input().rstrip()
        time, name = log_line_to_info(log_line)
        if time <= S:
            if name not in enter_check:
                enter_check.append(name)
        elif (E <= time <= Q):
            for idx, n in enumerate(enter_check):
                if n == name:
                    del enter_check[idx]
                    ans += 1
                    break

    except:
        break

print(ans)
