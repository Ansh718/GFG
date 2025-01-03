//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int kPalindrome(string str, int n, int k)
    {
        vector<vector<int>> dP(n, vector<int>(n, 0));
        for (int g = 1; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (str[i] == str[j])
                {
                    dP[i][j] = dP[i + 1][j - 1];
                }
                else
                {
                    dP[i][j] = min(dP[i + 1][j], dP[i][j - 1]) + 1;
                }
            }
        }
        return dP[0][n - 1] <= k;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;

        Solution ob;
        cout << ob.kPalindrome(str, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends