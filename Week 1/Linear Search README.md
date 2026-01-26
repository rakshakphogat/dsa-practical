# Linear Search

## Description

This program implements linear search algorithm to find an element in an array. It sequentially checks each element until the target is found or the end of the array is reached.

## Algorithm

1. Iterate through the array from index 0 to n-1
2. Compare each element with the target
3. If element matches target, return the index
4. If no match is found after checking all elements, return -1

## Functions

- `linearSearch(int arr[], int n, int target)`: Searches for target in array and returns its index or -1 if not found

## Input

- Number of elements (n): integer
- Array elements: n integers
- Target element to search: integer

## Output

- Index of the element if found, or "Element not found" message

## Time Complexity

- Best case: O(1) - element found at first position
- Average case: O(n)
- Worst case: O(n) - element not present or at last position

## Space Complexity

O(1) - constant space

## Example

```
Enter number of elements: 5
Enter elements:
10
20
30
40
50
Enter element to search: 30
Element found at index: 2
```

```
Enter number of elements: 5
Enter elements:
10
20
30
40
50
Enter element to search: 60
Element not found
```
