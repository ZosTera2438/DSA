// Time Complexity: O( E log(V) )
// Space Complexity: O( |E| + |V| )

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V, INT_MAX);

        result[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < result[v])
                {
                    result[v] = dis + w;
                    pq.push({dis + w, v});
                }
            }
        }
        return result;
    }
};

// for -ve weight in each iteration distance decreases, hence forms infinite loop 