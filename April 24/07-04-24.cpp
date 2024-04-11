//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int maxDotProduct(int n, int m, int a[], int b[])
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = i; j < n + 1; j++)
            {
                dp[i][j] = max((dp[i - 1][j - 1] + a[j - 1] * b[i - 1]), (dp[i][j - 1]));
            }
        }
        return dp[m][n];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.maxDotProduct(n, m, a, b) << "\n";
    }
    return 0;
}

// } Driver Code Ends