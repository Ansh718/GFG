//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long MOD1 = 1e9 + 7;
    long long power1(long long a1, long long b1)
    {
        long long ans1 = 1;
        while (b1 > 0)
        {
            if (b1 & 1)
            {
                ans1 *= a1;
                ans1 %= MOD1;
            }
            a1 *= a1;
            a1 %= MOD1;
            b1 >>= 1;
        }
        return ans1;
    }

    int numberOfConsecutiveOnes(int n)
    {
        vector<int> a1(n);
        vector<int> b1(n);
        a1[0] = 1;
        b1[0] = 1;
        for (int i = 1; i < n; i++)
        {
            a1[i] = (a1[i - 1] + b1[i - 1]) % MOD1;
            b1[i] = a1[i - 1];
        }
        return (power1(2, n) + MOD1 - (a1[n - 1] + b1[n - 1]) % MOD1) % MOD1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends