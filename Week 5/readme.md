DSA Practical - Week 5

1. Dijkstra

Problem: Find the shortest path from a source node to all other nodes in a weighted graph with non-negative edges  
Approach: Repeatedly select the unvisited node with minimum tentative distance and relax its adjacent edges  
Time Complexity: O(V^2) (for adjacency matrix / simple implementation)  
Space Complexity: O(V)

2. Kruskal

Problem: Find the Minimum Spanning Tree (MST) of a connected weighted graph  
Approach: Sort edges by weight and add the next lightest edge that does not form a cycle (using disjoint set/union-find)  
Time Complexity: O(E log E)  
Space Complexity: O(V)

3. Prim's

Problem: Find the Minimum Spanning Tree (MST) of a connected weighted graph  
Approach: Start from any vertex and grow the MST by repeatedly adding the minimum weight edge that connects a visited node to an unvisited node  
Time Complexity: O(V^2) (for adjacency matrix / simple implementation)  
Space Complexity: O(V)

Print paths for all
