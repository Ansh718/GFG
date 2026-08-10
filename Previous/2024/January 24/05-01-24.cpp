//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int TotalWays(int N)
    {
        const int M = 1000000007;
        if (N == 1)
        {
            return 4;
        }
        if (N == 2)
        {
            return 9;
        }
        int f1 = 2;
        int f2 = 3;
        int f3 = 0;
        for (int i = 3; i <= N; i++)
        {
            f3 = ((long long)f1 % M + (long long)f2 % M) % M;
            f1 = f2;
            f2 = f3;
        }
        return ((long long)f3 % M * (long long)f3 % M) % M;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.TotalWays(N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends