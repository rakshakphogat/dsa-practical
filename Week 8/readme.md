DSA Practical - Week 8

1. Matrix Chain Multiplication

Problem: Find the minimum number of scalar multiplications needed to multiply a chain of matrices  
Approach: Use dynamic programming to try all partition points and store optimal subproblem costs  
Time Complexity: O(n^3)  
Space Complexity: O(n^2)

2. Multistage Graph

Problem: Find the minimum cost path in a multistage graph  
Approach: Use backward dynamic programming from destination to source to compute minimum cost at each vertex  
Time Complexity: O(V + E)  
Space Complexity: O(V)
