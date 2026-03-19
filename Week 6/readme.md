DSA Practical - Week 6

1. Count Stages in Multistage Graph

Problem: Determine how many stages are present in a multistage graph represented by an adjacency matrix  
Approach: Process nodes from destination to source and assign stage values using dynamic programming based on outgoing edges  
Time Complexity: O(V^2)  
Space Complexity: O(V)

2. Minimum Cost Path in Multistage Graph

Problem: Find the minimum cost path from source to destination by selecting exactly one node at each stage  
Approach: Use backward dynamic programming to compute minimum cost from each node to destination and store next-node choices to reconstruct the path  
Time Complexity: O(V^2)  
Space Complexity: O(V)
