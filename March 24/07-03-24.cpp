//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string longestSubstring(string s, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        string result;
        int result_length = 0;
        int ind = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = i + 1; j < n + 1; j++)
            {
                if (s[i - 1] == s[j - 1] &&
                    dp[i - 1][j - 1] < (j - i))
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > result_length)
                    {
                        result_length = dp[i][j];
                        ind = max(i, ind);
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        if (result_length > 0)
        {
            for (int i = ind - result_length + 1; i < ind + 1; i++)
            {
                result.push_back(s[i - 1]);
            }
        }
        return result.empty() ? "-1" : result;
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
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends