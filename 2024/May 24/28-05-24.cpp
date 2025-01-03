//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    int minimumCost(int n, int w, vector<int> &cost)
    {
        int INF = 1e9;
        vector<int> dp(w + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= w; ++i)
        {
            for (int k = 1; k <= n; ++k)
            {
                if (k <= i && cost[k - 1] != -1)
                {
                    dp[i] = min(dp[i], dp[i - k] + cost[k - 1]);
                }
            }
        }
        return dp[w] == INF ? -1 : dp[w];
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

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends