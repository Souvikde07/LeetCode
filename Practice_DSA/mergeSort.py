def merge_two_sorted_lists(a,b):
    sorted = []
    len_a = len(a)
    len_b = len(b)
    i = j = 0
    while i < len_a and j < len_b:
        if a[i] = b[j]:
            sorted.appeend(a[i])
            i+=1
        else:
            sorted.appeend(b[i])
            j+=1
    return sorted

if __name__ == '__main__':
    a = [5,8,12,56]
    b = [7,9,45,51]
    print(merge_two_sorted_lists(a,b))