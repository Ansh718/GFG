//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int countWays(int n, string s)
    {
        int dP[n][n][2];
        const int M = 1003;
        for (int i = n - 1; i > -1; i -= 2)
        {
            for (int j = i; j < n; j += 2)
            {
                if (i == j)
                {
                    dP[i][j][1] = s[i] == 'T';
                    dP[i][j][0] = s[i] == 'F';
                }
                else
                {
                    dP[i][j][1] = dP[i][j][0] = 0;
                    for (int k = i; k < j; k += 2)
                    {
                        int chc1 = dP[i][k][1], chc = dP[i][k][0], temp1 = dP[k + 2][j][1], temp = dP[k + 2][j][0];
                        if (s[k + 1] == '|')
                        {
                            dP[i][j][1] = (dP[i][j][1] + (chc1 * temp) % M + (chc * temp1) % M + (chc1 * temp1) % M) % M;
                            dP[i][j][0] = (dP[i][j][0] + (chc * temp) % M) % M;
                        }
                        else if (s[k + 1] == '&')
                        {
                            dP[i][j][1] = (dP[i][j][1] + (chc1 * temp1) % M) % M;
                            dP[i][j][0] = (dP[i][j][0] + (chc1 * temp) % M + (chc * temp1) % M + (chc * temp) % M) % M;
                        }
                        else
                        {
                            dP[i][j][1] = (dP[i][j][1] + (chc1 * temp) % M + (chc * temp1) % M) % M;
                            dP[i][j][0] = (dP[i][j][0] + (chc1 * temp1) % M + (chc * temp) % M) % M;
                        }
                    }
                }
            }
        }

        return dP[0][n - 1][1];
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
        string s;
        cin >> s;

        Solution ob;
        cout << ob.countWays(n, s) << "\n";
    }
    return 0;
}
// } Driver Code Ends