//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(int node, int parent, vector<bool> &visited, vector<int> &intime, vector<int> &lower, int &cnter, vector<vector<int>> &result, vector<int> adj[])
    {
        visited[node] = true;
        intime[node] = lower[node] = cnter++;
        for (auto child : adj[node])
        {
            if (child == parent)
            {
                continue;
            }

            if (visited[child])
            {
                lower[node] = min(lower[node], intime[child]);
            }
            else
            {
                dfs(child, node, visited, intime, lower, cnter, result, adj);
                lower[node] = min(lower[node], lower[child]);
                if (lower[child] > intime[node])
                {
                    result.push_back({min(node, child), max(node, child)});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int v, vector<int> adj[])
    {
        vector<bool> visited(v, false);
        vector<int> intime(v, 0), lower(v, 0);
        int cnter = 0;
        vector<vector<int>> result;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1, visited, intime, lower, cnter, result, adj);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>> ans = obj.criticalConnections(V, adj);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}
// } Driver Code Ends