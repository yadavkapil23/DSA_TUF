#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Recursive function to explore all possible paths in the maze
void solve(int i, int j, vector<vector<int>> &maze, int n, string path,
           vector<vector<int>> &visited, vector<string> &paths) {
    
    // ✅ Base Case: If destination (bottom-right cell) is reached
    if (i == n - 1 && j == n - 1) {
        paths.push_back(path); // Store the current valid path
        return;
    }

    // Mark the current cell as visited (to avoid revisiting)
    visited[i][j] = 1;

    // ✅ Move Down (D)
    if (i + 1 < n && maze[i + 1][j] == 1 && visited[i + 1][j] == 0) {
        solve(i + 1, j, maze, n, path + "D", visited, paths);
    }

    // ✅ Move Up (U)
    if (i - 1 >= 0 && maze[i - 1][j] == 1 && visited[i - 1][j] == 0) {
        solve(i - 1, j, maze, n, path + "U", visited, paths);
    }

    // ✅ Move Left (L)
    if (j - 1 >= 0 && maze[i][j - 1] == 1 && visited[i][j - 1] == 0) {
        solve(i, j - 1, maze, n, path + "L", visited, paths);
    }

    // ✅ Move Right (R)
    if (j + 1 < n && maze[i][j + 1] == 1 && visited[i][j + 1] == 0) {
        solve(i, j + 1, maze, n, path + "R", visited, paths);
    }

    // Unmark current cell before backtracking (so other paths can use it)
    visited[i][j] = 0;
}

// Function to find all paths from (0,0) to (n-1,n-1)
vector<string> findPath(vector<vector<int>> &maze, int n) {
    vector<string> paths; // To store all valid paths
    vector<vector<int>> visited(n, vector<int>(n, 0)); // To track visited cells

    // If starting cell is blocked, no path exists
    if (maze[0][0] == 0) {
        return paths;
    }

    // Start exploring paths from top-left corner (0,0)
    solve(0, 0, maze, n, "", visited, paths);
    return paths;
}

int main() {
    int n;
    cout << "Enter size of maze (N): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter the maze (0 = blocked, 1 = open):\n";
    
    // Input the maze grid
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    // Call function to find all possible paths
    vector<string> result = findPath(maze, n);

    // Output results
    if (result.empty()) {
        cout << "No paths found.\n";
    } else {
        cout << "Possible paths:\n";
        for (auto &p : result)
            cout << p << endl;
    }

    return 0;
}


// i : int	Current row index of the rat in the maze.
// j : int	Current column index of the rat in the maze.
// maze : vector<vector<int>> &	The 2D maze grid itself where 1 = open path, 0 = blocked. Passed by reference so it’s not copied every time.
// n : int	The size of the maze (N × N).
// path : string	A sequence of moves (like "DRRUL") that represents the current path the rat has taken so far.
// visited	: vector<vector<int>> & : A 2D matrix of 0s and 1s marking whether a cell is visited.
// paths : vector<string> & : Stores all successful paths that reach the destination (n−1,n−1). It’s updated only when a valid path is found.