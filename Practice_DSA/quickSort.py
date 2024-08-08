def quick_sort(array):
    def _quick_sort(arr, low, high):
        if low < high:
            pivot_index = (low+high)/2
            pivot_value = arr[pivot_index]

            partition_index = _partition(arr,low, high, pivot_value):

            _quick_sort(arr, low, partition_index - 1)
            _quick_sort(arr, partition_index, high)

def _partition(arr, low, high, pivot_value):
    while low <= high:
        while arr[low] < pivot_value:
            low += 1
        while arr[high] > pivot_value:
            high -= 1
        if low <= high:
            arr[low], arr[high] = arr[high], arr[low]
            low += 1
            high -= 1
        return low

_quick_sort(arr, 0, len(arr)-1)

if __name__ == "__main__":
    data = [3, 6, 8, 10, 1, 2, 1]
    print("Original array:", data)
    quick_sort(data)
    print("Sorted array:", data)
