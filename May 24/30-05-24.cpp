//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countWays(string s1, string s2)
    {
        int m = 1e9 + 7;
        int s1z = s1.size();
        int s2z = s2.size();
        vector<vector<int>> dP(s1z + 1, vector<int>(s2z + 1, 0));
        for (int i = 0; i <= s1z; ++i)
        {
            dP[i][0] = 1;
        }
        for (int i = 1; i <= s1z; ++i)
        {
            for (int j = 1; j <= s2z; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dP[i][j] = (dP[i - 1][j - 1] + dP[i - 1][j]) % m;
                }
                else
                {
                    dP[i][j] = dP[i - 1][j] % m;
                }
            }
        }
        return dP[s1z][s2z];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends