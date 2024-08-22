numbers = [1, 3, 5, 7, 9, 11, 13]


def multi_by_3(lst):
    for i in range(len(lst)):
        lst[i] *= 3
    return lst


result = multi_by_3(numbers)
print(result)
