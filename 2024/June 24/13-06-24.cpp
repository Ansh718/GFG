//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int padovanSequence(int n)
    {
        int m1 = 0;
        m1 = 1000000007;
        if (n == 0 || n == 1 || n == 2)
        {
            return 1;
        }
        int ptr11 = 0;
        int ptr21 = 0;
        int ptr31 = 0;
        int newptr1 = 0;
        ptr11 = 1;
        ptr21 = 1;
        ptr31 = 1;
        newptr1 = 1;
        for (int i = 3; i <= n; i++)
        {
            newptr1 = ((ptr21) % m1 + (ptr11) % m1) % m1;
            ptr11 = ptr21;
            ptr21 = ptr31;
            ptr31 = newptr1;
        }
        return newptr1;
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends