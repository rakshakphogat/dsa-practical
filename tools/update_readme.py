import re
from pathlib import Path

P = Path(r"c:\Users\hp\Desktop\dsa practical\README.md")
text = P.read_text(encoding='utf-8')

# Fix code indentation: ensure all lines inside fenced code blocks have 4-space indent
lines = text.splitlines(keepends=False)
out = []
in_code = False

for line in lines:
    if line.strip().startswith('```'):
        in_code = not in_code
        out.append(line)
    elif in_code and line.strip() and not line.startswith('    '):
        # Inside code fence and line is not empty and not already indented: add 4 spaces
        out.append('    ' + line)
    else:
        out.append(line)

text = '\n'.join(out)
P.write_text(text, encoding='utf-8')
print('Code indentation fixed')

# Now append the three new practicals
new_practicals = '''
### **Practical 28. Graph Coloring**

**Problem Statement:** Given a graph, determine if it can be colored using at most m colors such that no two adjacent vertices have the same color. If possible, print the coloring; otherwise, print "Not possible to color".

**Algorithm of Solution:**

1. Use backtracking to try coloring each vertex with each available color.
2. For each vertex, check if the color is safe (no adjacent vertex has the same color).
3. If a valid coloring is found, return true; otherwise, backtrack and try a different color.
4. If all vertices are colored successfully, print the solution; otherwise, print "Not possible".

**Code:**

```cpp
    bool isSafe(int vertex, vector<vector<int>>& graph, vector<int>& color, int c) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[vertex][i] && c == color[i])
                return false;
        }
        return true;
    }
    
    bool colorGraphUtil(vector<vector<int>>& graph, int m, vector<int>& color, int vertex) {
        if (vertex == graph.size())
            return true;
    
        for (int c = 1; c <= m; c++) {
            if (isSafe(vertex, graph, color, c)) {
                color[vertex] = c;
                
                if (colorGraphUtil(graph, m, color, vertex + 1))
                    return true;
                
                color[vertex] = 0;
            }
        }
        return false;
    }
    
    void colorGraph(vector<vector<int>>& graph, int m) {
        int n = graph.size();
        vector<int> color(n, 0);
        
        if (colorGraphUtil(graph, m, color, 0)) {
            cout << "Graph coloring is possible:\\n";
            for (int i = 0; i < n; i++) {
                cout << "Vertex " << i << " -> Color " << color[i] << "\\n";
            }
        } else {
            cout << "Not possible to color the graph with " << m << " colors\\n";
        }
    }
```

**Graph:**

**Time Complexity:** Best = Average = Worst = O(m^n) where m is colors and n is vertices

**Space Complexity:** O(n)

### **Practical 29. Hamiltonian Cycle**

**Problem Statement:** Given a graph, determine if a Hamiltonian cycle exists. A Hamiltonian cycle is a cycle that visits every vertex exactly once and returns to the starting vertex. If it exists, print the cycle; otherwise, print "No Hamiltonian cycle exists".

**Algorithm of Solution:**

1. Use backtracking starting from vertex 0.
2. For each position in the path, try placing each unvisited vertex that is adjacent to the previous vertex.
3. Once all vertices are placed, check if the last vertex connects back to the first vertex.
4. If valid, print the cycle; otherwise, backtrack and try a different path.

**Code:**

```cpp
    bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
        if (graph[path[pos - 1]][v] == 0)
            return false;
        
        for (int i = 0; i < pos; i++)
            if (path[i] == v)
                return false;
        
        return true;
    }
    
    bool hamiltonianUtil(vector<vector<int>>& graph, vector<int>& path, int pos, int n) {
        if (pos == n) {
            if (graph[path[pos - 1]][path[0]] == 1)
                return true;
            else
                return false;
        }
        
        for (int v = 1; v < n; v++) {
            if (isSafe(v, graph, path, pos)) {
                path[pos] = v;
                
                if (hamiltonianUtil(graph, path, pos + 1, n))
                    return true;
                
                path[pos] = -1;
            }
        }
        
        return false;
    }
    
    void hamiltonianCycle(vector<vector<int>>& graph, int n) {
        vector<int> path(n, -1);
        path[0] = 0;
        
        if (hamiltonianUtil(graph, path, 1, n)) {
            cout << "Hamiltonian cycle exists:\\n";
            for (int i = 0; i < n; i++) {
                cout << path[i] << " ";
            }
            cout << path[0] << "\\n";
        } else {
            cout << "No Hamiltonian cycle exists\\n";
        }
    }
```

**Graph:**

**Time Complexity:** Best = Average = Worst = O(n!)

**Space Complexity:** O(n)

### **Practical 30. N Queens Problem**

**Problem Statement:** Place n queens on an n×n chessboard such that no two queens attack each other. Use backtracking to find a valid placement and print the board configuration.

**Algorithm of Solution:**

1. Use backtracking to place queens column by column.
2. For each column, try placing a queen in each row.
3. Check if the placement is safe (no conflicts with previously placed queens).
4. If safe, place the queen and move to the next column.
5. If a row doesn't work, backtrack and try the next row.
6. When all queens are placed, print the board; otherwise, print "No solution exists".

**Code:**

```cpp
    bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
        for (int i = 0; i < col; i++)
            if (board[row][i])
                return false;
        
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                return false;
        
        for (int i = row, j = col; i < n && j >= 0; i++, j--)
            if (board[i][j])
                return false;
        
        return true;
    }
    
    bool solveNQueens(vector<vector<int>>& board, int col, int n) {
        if (col >= n)
            return true;
        
        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 1;
                
                if (solveNQueens(board, col + 1, n))
                    return true;
                
                board[row][col] = 0;
            }
        }
        
        return false;
    }
    
    void printBoard(vector<vector<int>>& board, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j])
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << "\\n";
        }
        cout << "\\n";
    }
```

**Graph:**

**Time Complexity:** Best = Average = Worst = O(n!)

**Space Complexity:** O(n^2)
'''

P.write_text(text + new_practicals, encoding='utf-8')
print('New practicals added')
