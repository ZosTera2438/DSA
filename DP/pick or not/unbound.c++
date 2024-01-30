int knapsackUtil(vector<int>& wt, vector<int>& val, int item, int W, vector<vector<int>>& dp) {
    // Base case: if we're at the first item
    if (item == 0) {
        // Calculate and return the maximum value for the given weight limit
        return (W / wt[0]) * val[0];
    }
    
    if (dp[item][W] != -1)
        return dp[item][W];
        
    // Calculate without taking current item
    int notTaken = 0 + knapsackUtil(wt, val, item - 1, W, dp);
    
    // Calculate by taking current item
    int taken = INT_MIN;
    if (wt[item] <= W)
        taken = val[item] + knapsackUtil(wt, val, item, W - wt[item], dp);
        
    return dp[item][W] = max(notTaken, taken);
}

// Function to solve the unbounded knapsack problem
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    
    return knapsackUtil(wt, val, n - 1, W, dp);
}









int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<int> cur(W + 1, 0);

    // Base Condition: for first item
    for (int i = wt[0]; i <= W; i++) {
        cur[i] = (i / wt[0]) * val[0];
    }

    for (int item = 1; item < n; item++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = cur[cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[item] <= cap)
                taken = val[item] + cur[cap - wt[item]]; // Maximum value by taking the current item

            cur[cap] = max(notTaken, taken);
        }
    }

    return cur[W];
}