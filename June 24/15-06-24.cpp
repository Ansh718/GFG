//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long getCount(int n)
    {
        if (n == 1)
        {
            return 10;
        }
        vector<vector<int>> moves = {
            {0, 8},
            {1, 2, 4},
            {2, 1, 3, 5},
            {3, 2, 6},
            {4, 1, 5, 7},
            {5, 2, 4, 6, 8},
            {6, 3, 5, 9},
            {7, 4, 8},
            {8, 0, 5, 7, 9},
            {9, 6, 8}};
        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
        for (int d = 0; d <= 9; ++d)
        {
            dp[1][d] = 1;
        }
        for (int len = 2; len <= n; ++len)
        {
            for (int d = 0; d <= 9; ++d)
            {
                dp[len][d] = 0;
                for (int prev : moves[d])
                {
                    dp[len][d] += dp[len - 1][prev];
                }
            }
        }
        long long result = 0;
        for (int d = 0; d <= 9; ++d)
        {
            result += dp[n][d];
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends