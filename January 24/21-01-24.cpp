//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int next(int x)
    {
        unsigned s, r, ns, o;
        if (x == 0)
        {
            return 0;
        }
        s = (x & -x);
        r = x + s;
        ns = (r & -r);
        o = ((ns / s) >> 1) - 1;
        return r | o;
    }

    bool isCoverValid(int bits, int n, const vector<pair<int, int>> &edges)
    {
        int current = (1 << bits) - 1;
        while (current < (1 << n))
        {
            int m = edges.size();
            for (auto edge : edges)
            {
                int x, y;
                tie(x, y) = edge;
                --x;
                --y;
                if (((current >> x) & 1) or ((current >> y) & 1))
                {
                    --m;
                }
            }
            if (m == 0)
            {
                return true;
            }
            current = next(current);
        }
        return false;
    }

    int vertexCover(int n, vector<pair<int, int>> &edges)
    {
        int ans = 20;
        int l = 0;
        int h = n;
        while (l < h - 1)
        {
            int m = l + (h - l) / 2;
            if (isCoverValid(m, n, edges))
            {
                h = m;
            }
            else
            {
                l = m;
            }
        }
        return h;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edges;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            edges.push_back({a, b});
        }
        Solution s;
        cout << s.vertexCover(n, edges) << endl;
    }
    return 0;
}
// } Driver Code Ends