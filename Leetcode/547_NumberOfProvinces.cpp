class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto i : adj[node])
            if (!vis[i])
                dfs(i, vis, adj);
    }

public:
    // adjacency matrix to adjacency list
    // striver
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> adj[n];
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
            if (!vis[i])
            {
                dfs(i, vis, adj);
                count++;
            }

        return count;
    }
};