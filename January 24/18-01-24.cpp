//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int, int>> range;
        for (int i = 0; i < n; i++)
        {
            if (gallery[i] > -1)
            {
                range.push_back({i - gallery[i], i + gallery[i]});
            }
        }
        sort(range.begin(), range.end());
        int maXRight = 0;
        int result = 0;
        int ptr = 0;
        while (maXRight < n)
        {
            if (ptr == range.size() || range[ptr].first > maXRight)
            {
                return -1;
            }
            int currentMax = 0;
            currentMax = range[ptr].second;
            while ((ptr + 1) < range.size() && range[ptr + 1].first <= maXRight)
            {
                ptr += 1;
                currentMax = max(currentMax, range[ptr].second);
            }
            if (currentMax < maXRight)
            {
                return -1;
            }
            result++;
            maXRight = currentMax + 1;
            ptr++;
        }
        return result;
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

        int gallery[n];
        for (int i = 0; i < n; i++)
            cin >> gallery[i];
        Solution obj;
        cout << obj.min_sprinklers(gallery, n) << endl;
    }
    return 1;
}

// } Driver Code Ends