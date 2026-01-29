DSA Practical - Week 1

1. Horner's Rule

Problem: Evaluate a polynomial at a given value of x  
Approach: Recursively evaluate from the highest degree term, factoring out x at each step  
Time Complexity: O(n)  
Space Complexity: O(n)

2. Linear Search

Problem: Find the index of a target element in an array  
Approach: Iterate through the array sequentially until the target is found  
Time Complexity: O(n)  
Space Complexity: O(1)

3. Missing Number

Problem: Find the missing number in a consecutive sequence  
Approach: Check consecutive elements for a gap greater than 1  
Time Complexity: O(n)  
Space Complexity: O(1)

4. Permutation Generation of Binary String

Problem: Generate all binary strings of length n  
Approach: Recursively place '0' and '1' at each position  
Time Complexity: O(2^n)  
Space Complexity: O(n)

5. Permutation Generation of String

Problem: Generate all permutations of a given string  
Approach: Recursively swap characters and generate permutations for remaining positions  
Time Complexity: O(n!)  
Space Complexity: O(n)

6. Power Iterative

Problem: Calculate x raised to power n  
Approach: Multiply x iteratively n times  
Time Complexity: O(n)  
Space Complexity: O(1)

7. Power Recursive

Problem: Calculate x raised to power n  
Approach: Use divide and conquer by squaring half powers  
Time Complexity: O(log n)  
Space Complexity: O(log n)

8. Sum of Arrays

Problem: Calculate the sum of all elements in an array  
Approach: Iterate through array and accumulate the sum  
Time Complexity: O(n)  
Space Complexity: O(1)

9. Tower of Hanoi

Problem: Solve the Tower of Hanoi puzzle with n disks  
Approach: Recursively move n-1 disks to auxiliary, move largest disk to destination, move n-1 disks to destination  
Time Complexity: O(2^n)  
Space Complexity: O(n)
