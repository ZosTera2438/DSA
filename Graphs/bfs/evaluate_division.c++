double evaluate(unordered_map<string, vector<pair<string, double>>> &graph, vector<string> &query) {
    auto startNode = query[0];
    auto endNode = query[1];
    
    if (graph.find(startNode) == graph.end()) {
        return -1;
    }
    
    if (graph.find(endNode) == graph.end()) {
        return -1;
    }
    
    queue<pair<string, double>> que;
    unordered_set<string> visited;
    
    que.push({startNode, 1});
    visited.insert(startNode);
    
    while (!que.empty()) {
        auto frontItem = que.front();
        que.pop();
        
        auto currNode = frontItem.first;
        auto currValue = frontItem.second;
        
        if (currNode == endNode) {
            return currValue;
        }
        
        for (auto nodeObj: graph[currNode]) {
            auto node = nodeObj.first;
            auto weight = nodeObj.second;
            if (visited.insert(node).second) {
                que.push({node, currValue * weight});
            }
        }
    }
    
    return -1;
}

public:
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    
    unordered_map<string, vector<pair<string, double>>> graph;
    for (int i = 0; i < equations.size(); i++) {
        auto fromNode = equations[i][0];
        auto toNode = equations[i][1];
        double weight = values[i];
        
        graph[fromNode].push_back({toNode, weight});
        graph[toNode].push_back({fromNode, 1 / weight});
    }
    
    vector<double> answers;
    
    for (auto query: queries) {
        answers.push_back(evaluate(graph, query));
    }
    
    return answers;
}