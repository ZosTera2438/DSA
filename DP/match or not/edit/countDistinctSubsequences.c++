// count the number of distinct subsequences of s2 in s1
const int prime = 1e9 + 7;

int countUtil(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp) {
    // Base: s2 completely matched
    if (ind2 < 0)
        return 1;
    
    // Base: s1 completely traversed but not found complete s2
    if (ind1 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;

    // match, consider two options
    if (s1[ind1] == s2[ind2]) {
        int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);

        result = (leaveOne + stay) % prime;
    } 
    // not match
    else {
        result = countUtil(s1, s2, ind1 - 1, ind2, dp);
    }

    dp[ind1][ind2] = result;
    return result;
}

int subsequenceCounting(string &s1, string &s2, int lt, int ls) {
    vector<vector<int>> dp(lt, vector<int>(ls, -1));
    return countUtil(s1, s2, lt - 1, ls - 1, dp);
}