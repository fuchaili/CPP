#include <iostream>
#include <stack>
using namespace std;

const int MAXN = 100; // Maximum number of vertices in the graph

int adjMat[MAXN][MAXN]; // Adjacency matrix representing the graph
bool visited[MAXN]; // Array to keep track of visited vertices
  int n, m; // n = number of vertices, m = number of edges

void dfs(int start) {
    stack<int> st; // Stack to keep track of visited vertices
    st.push(start); // Push the starting vertex onto the stack

    while (!st.empty()) {
        int cur = st.top(); // Get the top vertex on the stack
        st.pop(); // Pop the top vertex from the stack

        if (!visited[cur]) {
            visited[cur] = true; // Mark the vertex as visited
            cout << cur << " "; // Print the vertex

            // Add the unvisited neighbors of the current vertex to the stack
            for (int i = 0; i < n; i++) {
                if (adjMat[cur][i] && !visited[i]) {
                    st.push(i);
                }
            }
        }
    }
}

int main() {
  
    cin >> n >> m;

    // Initialize the adjacency matrix to all zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMat[i][j] = 0;
        }
    }

    // Read in the edges of the graph and update the adjacency matrix
    for (int i = 0; i < m; i++) {
        int u, v; // u and v are the endpoints of an edge
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1; // If the graph is undirected
    }

    // Perform a depth-first search starting from vertex 0
    dfs(0);

    return 0;
}