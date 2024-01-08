int mazeObstaclesUtil(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp) {
    // Base cases
    if (i > 0 && j > 0 && maze[i][j] == -1) return 0; // If there's an obstacle at (i, j), return 0
    if (i == 0 && j == 0) return 1; // If we reach the destination (0, 0), return 1
    if (i < 0 || j < 0) return 0; // If we go out of bounds, return 0
    if (dp[i][j] != -1) return dp[i][j]; // If the result is already computed, return it

    // Recursive calls to explore paths from (i, j) to (0, 0)
    int up = mazeObstaclesUtil(i - 1, j, maze, dp);
    int left = mazeObstaclesUtil(i, j - 1, maze, dp);

    // Store the result in the DP table and return it
    return dp[i][j] = up + left;
}

// Main function to count paths with obstacles in a maze
int mazeObstacles(int n, int m, vector<vector<int>> &maze) {
    vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
    return mazeObstaclesUtil(n - 1, m - 1, maze, dp); // Start from the bottom-right corner
}








// space optimised
int mazeObstacles(int n, int m, vector<vector<int>> &maze) {
    vector<int> prev(m, 0); // Initialize a vector to store the previous row's path counts

    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0); // Initialize a temporary vector for the current row
        for (int j = 0; j < m; j++) {
            // Base conditions
            if (i > 0 && j > 0 && maze[i][j] == -1) {
                temp[j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
                continue;
            }
            if (i == 0 && j == 0) {
                temp[j] = 1; // If we are at the starting point, there is one path to it
                continue;
            }

            int up = 0;
            int left = 0;

            // Check if we can move up and left (if not at the edge of the maze)
            if (i > 0)
                up = prev[j]; // Number of paths from above (previous row)
            if (j > 0)
                left = temp[j - 1]; // Number of paths from the left (current row)

            // Total number of paths to reach (i, j) is the sum of paths from above and left
            temp[j] = up + left;
        }
        prev = temp; // Update the previous row with the current row
    }

    // The final result is stored in prev[m-1], which represents the destination in the last row
    return prev[m - 1];
}