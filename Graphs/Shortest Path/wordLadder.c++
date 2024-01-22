int wordLadderLength(string startWord, string targetWord, vector<string> &wordList){
    // queue {word, level}.
    queue<pair<string, int>> q;

    q.push({startWord, 1});

    // Push all values of wordList into a set to make deletion from it easier and in less time complexity.
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);
    
    while (!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == targetWord)
            return steps;

        for (int i = 0; i < word.size(); i++){ 
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                // check if it exists in the set and push it in the queue.
                if (st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    // If there is no transformation sequence possible
    return 0;
}