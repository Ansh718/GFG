//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int gMin(int x, int y)
    {
        return (x < y) ? x : y;
    }
    int largestSubsquare(int n, vector<vector<char>> a)
    {
        int maX = 0;
        vector<vector<int>> horizontal(n, vector<int>(n, 0));
        vector<vector<int>> vertical(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 'O')
                {
                    vertical[i][j] = horizontal[i][j] = 0;
                }
                else
                {
                    horizontal[i][j] = (j == 0) ? 1 : horizontal[i][j - 1] + 1;
                    vertical[i][j] = (i == 0) ? 1 : vertical[i - 1][j] + 1;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int small = 0;
                small = gMin(horizontal[i][j], vertical[i][j]);
                while (small > maX)
                {
                    if (vertical[i][j - small + 1] >= small && horizontal[i - small + 1][j] >= small)
                    {
                        maX = small;
                    }
                    small -= 1;
                }
            }
        }
        return maX;
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
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends