# Missing Number

## Description

This program finds the missing number in a consecutive list of integers. Given n numbers from a sequence of n+1 consecutive integers, it identifies which number is missing.

## Algorithm

1. Calculate the expected sum of n+1 consecutive integers using formula: (n+1)\*(n+2)/2
2. Calculate the actual sum of elements in the array
3. The difference between expected sum and actual sum is the missing number

## Mathematical Formula

For consecutive integers from 1 to n+1:

- Total Sum = (n+1) \* (n+2) / 2
- Missing Number = Total Sum - Array Sum

## Functions

- `findMissingNumber(int arr[], int n)`: Returns the missing number from the consecutive sequence

## Input

- Number of elements in array (n): integer (one less than total sequence length)
- Array elements: n integers from a consecutive sequence

## Output

- The missing number from the sequence

## Time Complexity

O(n) where n is the number of elements in the array

## Space Complexity

O(1) - constant space

## Example

```
Enter number of elements (one less than total): 4
Enter elements:
1
2
4
5
Missing number: 3
```

```
Enter number of elements (one less than total): 5
Enter elements:
2
3
4
5
6
Missing number: 1
```
