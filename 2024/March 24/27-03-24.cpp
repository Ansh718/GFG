//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool chc(int i, int j, vector<vector<int>> &mat)
    {
        if (i - 1 >= 0 && mat[i - 1][j] == 0)
        {
            return false;
        }
        if (i + 1 < mat.size() && mat[i + 1][j] == 0)
        {
            return false;
        }
        if (j - 1 >= 0 && mat[i][j - 1] == 0)
        {
            return false;
        }
        if (j + 1 < mat[0].size() && mat[i][j + 1] == 0)
        {
            return false;
        }
        return true;
    }
    int helper(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &visited, vector<vector<int>> &dP)
    {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || visited[i][j] == 1 || mat[i][j] == 0)
        {
            return INT_MAX;
        }
        if (dP[i][j] != -1)
        {
            return dP[i][j];
        }
        if (!chc(i, j, mat))
        {
            return INT_MAX;
        }
        if (j == 0)
        {
            return mat[i][0];
        }
        visited[i][j] = true;
        int l = helper(i, j - 1, mat, visited, dP);
        int u = helper(i - 1, j, mat, visited, dP);
        int d = helper(i + 1, j, mat, visited, dP);
        if (l != INT_MAX)
        {
            l += mat[i][j];
        }
        if (u != INT_MAX)
        {
            u += mat[i][j];
        }
        if (d != INT_MAX)
        {
            d += mat[i][j];
        }
        visited[i][j] = 0;
        return dP[i][j] = min(l, min(u, d));
    }
    int findShortestPath(vector<vector<int>> &mat)
    {
        int n = 0;
        n = mat.size();
        int m = 0;
        m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dP(n + 1, vector<int>(m + 1, -1));
        int result = 0;
        result = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            result = min(result, helper(i, m - 1, mat, visited, dP));
        }
        if (result == INT_MAX)
        {
            return -1;
        }
        else
        {
            return result;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends