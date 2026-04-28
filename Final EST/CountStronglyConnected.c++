class Solution {
    void dfs1(int u, vector<int> adj[], vector<int>& vis, stack<int>& st){
        vis[u]=1;
        for(int v:adj[u]) if(!vis[v]) dfs1(v,adj,vis,st);
        st.push(u);
    }

    void dfs2(int u, vector<int> rev[], vector<int>& vis){
        vis[u]=1;
        for(int v:rev[u]) if(!vis[v]) dfs2(v,rev,vis);
    }

public:
    int kosaraju(int V, vector<vector<int>>& edges) {
        vector<int> adj[V], rev[V], vis(V);
        stack<int> st;

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            rev[e[1]].push_back(e[0]);
        }

        for(int i=0;i<V;i++)
            if(!vis[i]) dfs1(i,adj,vis,st);

        fill(vis.begin(),vis.end(),0);
        int cnt=0;

        while(!st.empty()){
            int u=st.top(); st.pop();
            if(!vis[u]){
                dfs2(u,rev,vis);
                cnt++;
            }
        }
        return cnt;
    }
};