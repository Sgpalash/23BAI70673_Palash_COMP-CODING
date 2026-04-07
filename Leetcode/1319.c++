class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1){
            return -1;
        }
        vector<vector<int>> adj(n);
        for (auto &edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);
        int components = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                components++;
                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(int neighbor : adj[node]) {
                        if(visited[neighbor] == 0) {
                            visited[neighbor] = 1;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return components - 1;
    }
};