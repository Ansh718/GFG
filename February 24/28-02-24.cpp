//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int DivisibleByEight(string s)
    {
        int n = s.length();
        if (n < 3)
        {
            int num = stoi(s);
            return (num % 8 == 0) ? 1 : -1;
        }
        int num = stoi(s.substr(n - 3));
        return (num % 8 == 0) ? 1 : -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.DivisibleByEight(S) << "\n";
    }
}
// } Driver Code Ends