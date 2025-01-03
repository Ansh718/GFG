//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    int subsequenceCount(string S, string T)
    {
        int m = 0;
        m = T.length();
        int n = 0;
        n = S.length();
        if (m > n)
        {
            return 0;
        }
        int mat[m + 1][n + 1];
        for (int i = 1; i <= m; i++)
        {
            mat[i][0] = 0;
        }

        for (int j = 0; j <= n; j++)
        {
            mat[0][j] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (T[i - 1] != S[j - 1])
                {
                    mat[i][j] = mat[i][j - 1];
                }
                else
                {
                    mat[i][j] = mat[i][j - 1] + mat[i - 1][j - 1];
                }
            }
        }
        return mat[m][n];
    }
};

//{ Driver Code Starts.

//  Driver code to check above method
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        string tt;
        cin >> s;
        cin >> tt;

        Solution ob;
        cout << ob.subsequenceCount(s, tt) << endl;
    }
}
// } Driver Code Ends