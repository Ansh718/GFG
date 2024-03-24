//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> Series(int n)
    {
        vector<int> result;
        if (n == 1)
        {
            result.push_back(0);
            result.push_back(1);
            return result;
        }
        if (n == 2)
        {
            result.push_back(0);
            result.push_back(1);
            result.push_back(1);
            return result;
        }
        result.push_back(0);
        result.push_back(1);
        int m = 0;
        m = 1000000007;
        int f0 = 0;
        int f1 = 0;
        f1 = 1;
        int f2 = 0;
        for (int i = 2; i <= n; i++)
        {
            f2 = ((f1) % m + (f0) % m) % m;
            f0 = f1;
            f1 = f2;
            result.push_back(f2);
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends