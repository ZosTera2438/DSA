vector<int> topoSort(int V, vector<int> adj[])
	{
		// 1. init indegree_arr from graph
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		// 2. push node with indegree 0 in q
		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> result;

		// 3. bfs
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			result.push_back(node);

			// indegree-- for adjacent nodes
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		// for cycle
		if( result.size !=V ) return {};
		
		return result;
	}
};


// "if result_arr has less than V elements, cycle exists"
// '.' when indegree--, for cycle node left with 1 hence cannot push in q