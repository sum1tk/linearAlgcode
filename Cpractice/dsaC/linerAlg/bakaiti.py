def quickselect(array, k):
    if len(array) <= 1:
        return array[0]

    pivot = array[len(array) // 2]
    smaller = [x for x in array if x < pivot]
    larger = [x for x in array if x >= pivot]

    if len(smaller) >= k:
        return quickselect(smaller, k)
    else:
        return quickselect(larger, k - len(smaller) - 1)
    
arr = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
k = 4  # Find the 4th smallest element
result = quickselect(arr,k)
print("The", k, "th smallest element is:", result)