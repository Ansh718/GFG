//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long countWays(int N)
    {
        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < N + 1; i++)
        {
            dp[i] = (i / 2) + 1;
        }
        return dp[N];
    }
};

//{ Driver Code Starts.
int main()
{
    // taking count of testcases
    int t;
    cin >> t;

    while (t--)
    {
        // taking stair count
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends