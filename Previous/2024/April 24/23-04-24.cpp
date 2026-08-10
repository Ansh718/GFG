//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int firstElement(int n)
    {
        if (n == 1 || n == 2)
        {
            return 1;
        }
        int m = 0;
        m = 1000000007;
        int f1 = 0;
        int f2 = 0;
        f1 = 1;
        f2 = 1;
        int f3 = 0;
        for (int i = 3; i <= n; i++)
        {
            f3 = ((f1) % m + (f2) % m) % m;
            f1 = f2;
            f2 = f3;
        }
        return f3;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends