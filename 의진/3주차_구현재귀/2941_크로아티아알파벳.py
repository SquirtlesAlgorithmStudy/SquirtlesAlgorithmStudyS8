import sys
input = sys.stdin.readline

string = input().rstrip()

idx = 0
answer = 0
while idx < len(string):
    char = string[idx]
    match char:
        case "l":
            if idx + 1 < len(string) and string[idx:idx+2] == "lj":
                answer += 1
                idx += 2
            else:
                answer += 1
                idx += 1
        case "n":
            if idx + 1 < len(string) and string[idx:idx+2] == "nj":
                answer += 1
                idx += 2
            else:
                answer += 1
                idx += 1
        case "s":
            if idx + 1 < len(string) and string[idx:idx+2] == "s=":
                answer += 1
                idx += 2
            else:
                answer += 1
                idx += 1
        case "z":
            if idx + 1 < len(string) and string[idx:idx+2] == "z=":
                answer += 1
                idx += 2
            else:
                answer += 1
                idx += 1

        case "c":
            if idx + 1 < len(string):
                if string[idx:idx+2] == "c=":
                    answer += 1
                    idx += 2
                elif string[idx:idx+2] == "c-":
                    answer += 1
                    idx += 2
                else:
                    answer += 1
                    idx += 1
            else:
                answer += 1
                idx += 1

        case "d":
            if idx + 1 < len(string) and string[idx:idx+2] == "d-":
                answer += 1
                idx += 2

            elif idx + 2 < len(string) and string[idx:idx+3] == "dz=":
                answer += 1
                idx += 3
            else:
                answer += 1
                idx += 1
        case _:
            answer += 1
            idx += 1
print(answer)
