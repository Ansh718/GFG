//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// } Driver Code Ends
class Solution
{
public:
    void dfs(int start, vector<int> graph[], vector<int> &visited)
    {
        visited[start] = 1;
        for (auto s : graph[start])
        {
            if (!visited[s])
            {
                dfs(s, graph, visited);
            }
        }
    }
    int isTree(int n, int m, vector<vector<int>> &adj)
    {
        if ((n - m) != 1)
        {
            return 0;
        }
        vector<int> visited(n, 0);
        vector<int> graph[n];
        for (auto a : adj)
        {
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        dfs(0, graph, visited);
        for (auto v : visited)
        {
            if (!v)
            {
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        int m;
        scanf("%d", &m);

        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges, m, 2);

        Solution obj;
        int res = obj.isTree(n, m, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends