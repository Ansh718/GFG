//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long int PowMod(long long int num1, long long int num2, long long int M)
    {
        long long int result = 0;
        result = 1;
        while (num2 > 0)
        {
            if (num2 & 1)
            {
                result = ((result % M) * (num1 % M)) % M;
                num2--;
            }
            num1 = ((num1 % M) * (num1 % M)) % M;
            num2 >>= 1;
        }
        return (result % M);
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long int x, n, m;
        cin >> x >> n >> m;
        Solution ob;
        long long int ans = ob.PowMod(x, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends