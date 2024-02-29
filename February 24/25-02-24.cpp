//{ Driver Code Starts
// Driver Code
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long int count(long long int n)
    {
        vector<long long int> dp(n + 1, 0);
        dp[0] = 1;
        for (long long int i = 3; i < n + 1; i++)
        {
            dp[i] += dp[i - 3];
        }
        for (long long int i = 5; i < n + 1; i++)
        {
            dp[i] += dp[i - 5];
        }
        for (long long int i = 10; i < n + 1; i++)
        {
            dp[i] += dp[i - 10];
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        Solution obj;
        cout << obj.count(n) << endl;
    }
    return 0;
}
// } Driver Code Ends