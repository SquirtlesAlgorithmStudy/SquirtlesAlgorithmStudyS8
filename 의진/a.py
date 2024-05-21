def sorting_rule(x):
    return x[0] + x[1]


O(nlogn)


a = [(3, 1), (3, 4), (5, 2)]

a.sort(key=sorting_rule)

print(a)
