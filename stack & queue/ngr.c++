// for circular array
vector<int> nextGreaterElements(vector<int> &nums){
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st;
    
    for (int i = 2 * n - 1; i >= 0; i--){

        // pop elements from stack less than curr
        while (!st.empty() && st.top() <= nums[i % n]){
            st.pop();
        }

        if (i < n){
            // if stack is not empty put ans else put -1
            if (!st.empty())
                nge[i] = st.top();
        }

        // push curr element  
        st.push(nums[i % n]);
    }
    return nge;
}