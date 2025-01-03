//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dP(n + 1, vector<int>(total + 1, 0));
        for (int i = n - 1; i > -1; i--)
        {
            for (int j = 0; j < total + 1; j++)
            {
                int t = 0;
                int nt = 0;

                nt = dP[i + 1][j];

                if (cost[i] <= j)
                {
                    int remaining = 0;
                    remaining = j - cost[i] + (cost[i] * 9) / 10;
                    t = 1 + dP[i + 1][remaining];
                }

                dP[i][j] = max(t, nt);
            }
        }
        return dP[0][total];
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
        int k;
        cin >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.max_courses(n, k, arr) << endl;
    }
}
// } Driver Code Ends