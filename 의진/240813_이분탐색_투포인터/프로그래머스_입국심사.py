def solution(n, times):
    start = 1
    end = max(times) * n

    while start <= end:
        mid = (start + end) // 2
        if is_possible(mid, n, times):
            end = mid - 1
        else:
            start = mid + 1

    return start


def is_possible(test_t, n, times):
    available = 0
    for time in times:
        available += (test_t // time)

    if available >= n:
        return True
    else:
        return False
