//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int isPossible(vector<vector<int>> paths)
    {
        int n = paths.size();
        vector<int> indegree(n, 0), visited(n, 0);
        vector<vector<int>> grid(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (paths[i][j])
                {
                    grid[i].push_back(j);
                    ++indegree[j];
                }
            }
        }
        int odD = 0;
        int c = 0;
        dfs(0, visited, grid, indegree, odD, c);
        return c == n && !odD;
    }

private:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &grid, vector<int> &indegree, int &odD, int &c)
    {
        visited[node] = 1;
        odD = odD || (indegree[node] & 1);
        ++c;
        for (auto child : grid[node])
        {
            if (!visited[child])
                dfs(child, visited, grid, indegree, odD, c);
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> paths(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> paths[i][j];
        }
        Solution obj;
        int ans = obj.isPossible(paths);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends