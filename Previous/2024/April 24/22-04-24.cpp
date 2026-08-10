//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minRow(int n, int m, std::vector<std::vector<int>> &a)
    {
        int minCount = INT_MAX;
        int pos = 0;
        for (int i = 0; i < n; i++)
        {
            int current = 0;
            for (int j = 0; j < m; j++)
            {
                current += a[i][j];
            }
            pos = (current < minCount) ? i + 1 : (current == minCount) ? std::min(pos, i + 1)
                                                                       : pos;
            minCount = (current < minCount) ? current : minCount;
        }
        return pos;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends