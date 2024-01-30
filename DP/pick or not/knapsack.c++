int knapsackUtil(vector<int>& wt, vector<int>& val, int item, int W, vector<vector<int>>& dp) {
    if (item == 0 || W == 0) {
        return 0;
    }

    if (dp[item][W] != -1) {
        return dp[item][W];
    }

    // Calculate the maximum value by excluding the current item
    int notTaken = knapsackUtil(wt, val, item - 1, W, dp);
    int taken = 0;

    // include current item without exceeding the knapsack's capacity
    if (wt[item] <= W) {
        taken = val[item] + knapsackUtil(wt, val, item - 1, W - wt[item], dp);
    }

    return dp[item][W] = max(notTaken, taken);
}

// Function to solve the 0/1 Knapsack problem
int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return knapsackUtil(wt, val, n - 1, W, dp);
}











int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<int> prev(W + 1, 0);

    // Base condition: Fill in 'prev' for weight of first item
    for (int i = wt[0]; i <= W; i++) {
        prev[i] = val[0];
    }

    for (int item = 1; item < n; item++) {
        for (int cap = W; cap >= 0; cap--) { // loop always in reverse 
            // Calculate excluding the current item
            int notTaken = prev[cap];
            int taken = INT_MIN;

            // include current item without exceeding the knapsack's capacity
            if (wt[item] <= cap) {
                taken = val[item] + prev[cap - wt[item]];
            }

            prev[cap] = max(notTaken, taken);
        }
    }

    return prev[W];
}