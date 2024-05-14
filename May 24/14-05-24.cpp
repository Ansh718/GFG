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
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
    {
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> effort(rows, vector<int>(columns, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        effort[0][0] = 0;
        while (!pq.empty())
        {
            pair<int, pair<int, int>> p = pq.top();
            int current_effort = p.first;
            pair<int, int> pos = p.second;
            pq.pop();
            int x = pos.first, y = pos.second;
            if (x == rows - 1 && y == columns - 1)
            {
                return current_effort;
            }
            for (auto dir : directions)
            {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && ny >= 0 && nx < rows && ny < columns)
                {
                    int next_effort = max(current_effort, abs(heights[x][y] - heights[nx][ny]));
                    if (next_effort < effort[nx][ny])
                    {
                        effort[nx][ny] = next_effort;
                        pq.push({next_effort, {nx, ny}});
                    }
                }
            }
        }
        return effort[rows - 1][columns - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends