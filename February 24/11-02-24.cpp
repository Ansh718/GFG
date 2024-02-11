//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> recamanSequence(int n)
    {
        unordered_set<int> s;
        if (n == 1)
        {
            return {0};
        }
        vector<int> res;
        res.push_back(0);
        s.insert(0);
        int prev = 0;
        for (int i = 1; i < n; i++)
        {
            int curr = prev - i;
            if (curr < 0 || s.find(curr) != s.end())
            {
                curr = prev + i;
            }
            s.insert(curr);
            res.push_back(curr);
            prev = curr;
        }
        return res;
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

        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends