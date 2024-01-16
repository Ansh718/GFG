//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int numberSequence(int m, int n)
    {
        vector<vector<int>> dP(n, vector<int>(m + 1, 0));
        for (int i = 1; i < m + 1; i++)
        {
            dP[n - 1][i] = 1;
        }

        for (int i = n - 2; i > -1; i--)
        {
            for (int j = 1; j < m + 1; j++)
            {
                for (int k = 2 * j; k < m + 1; k++)
                {
                    dP[i][j] += dP[i + 1][k];
                }
            }
        }
        return accumulate(dP[0].begin(), dP[0].end(), 0);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        Solution ob;
        cout << ob.numberSequence(m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends