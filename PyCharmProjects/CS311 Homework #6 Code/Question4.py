def display_floats_less_than_n(arr, size, n):
    i = 0
    while i < size:
        if arr[i] < n:
            print(arr[i])
        i += 1

arr = [100.97, 2.2, 10.8, 87.1, 25.4, 30.3, 50.1, 297.0, 73.8]
size = len(arr)
n = 50.3

display_floats_less_than_n(arr, size, n)
