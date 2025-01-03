//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool helper(int chc, string &s, int n)
    {
        if (chc >= n)
        {
            return true;
        }
        int v1 = 0;
        int v2 = 0;
        for (int i = chc; i < n; ++i)
        {
            v1 = v1 * 10 + (s[i] - '0');
            v2 = 0;
            for (int j = i + 1; j < n; ++j)
            {
                v2 = v2 * 10 + (s[j] - '0');
                string x = to_string(v1 + v2);
                if (x.size() <= n - j - 1)
                {
                    if (x == s.substr(j + 1, x.size()))
                    {
                        if (helper(j + x.size() + 1, s, n))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool isAdditiveSequence(string n)
    {
        return helper(0, n, n.size());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends