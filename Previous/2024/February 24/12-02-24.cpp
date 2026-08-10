//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    long long M = 1000000007;

public:
    // long long helper(int n, long long &result, long long current)
    // {
    //     long long i;
    //     long long curr = 1;
    //     if (current == n + 1)
    //     {
    //         return 0;
    //     }
    //     else
    //     {
    //         for (i = result; i < result + current; i++)
    //         {
    //             curr *= i;
    //         }
    //         return ((curr) + helper(n, i, current + 1));
    //     }
    // }
    long long sequence(int n)
    {
        // long long result = 1;
        // return helper(n, result, 1) % M;
        long long p = 1;
        long long answer = 0;

        for (int i = 1; i < n + 1; i++)
        {
            long long value = 1;

            for (int j = 0; j < i; j++)
            {
                value = (value * (p++)) % M;
            }

            answer = (answer + value) % M;
        }

        return answer;
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
        cout << ob.sequence(N) << endl;
    }
    return 0;
}
// } Driver Code Ends