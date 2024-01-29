//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int TotalCount(string str)
    {
        int n = str.size();
        vector<int> sfx(n + 1, 0);
        int maX = 0;
        for (int i = n - 1; i > -1; i--)
        {
            sfx[i] = sfx[i + 1] + (str[i] - '0'), maX += (str[i] - '0');
        }
        vector<vector<int>> dP(n + 1, vector<int>(maX + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = sfx[0] - sfx[i + 1]; j < maX + 1; j++)
            {
                dP[i][j] = 1;
            }
        }
        for (int e = 0; e < n; e++)
        {
            for (int s = 0; s < maX + 1; s++)
            {
                int l = -1;
                int h = e + 1;
                while (l < h - 1)
                {
                    int mid = l + (h - l) / 2;
                    int cs = sfx[mid] - sfx[e + 1];
                    if (cs <= s)
                    {
                        h = mid;
                    }
                    else
                    {
                        l = mid;
                    }
                }
                for (int b = h; b < e + 1; b++)
                {
                    int cs = sfx[b] - sfx[e + 1];
                    if (cs <= s)
                    {
                        dP[e][s] += (b > 0 ? dP[b - 1][cs] : 0);
                    }
                }
            }
        }
        return dP[n - 1][maX];
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.TotalCount(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends