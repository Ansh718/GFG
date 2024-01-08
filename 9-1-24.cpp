//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> buildPrefixTable(string pattern)
    {
        int m = pattern.size();
        vector<int> prefixTable(m, 0);
        int j = 0;

        for (int i = 1; i < m;)
        {
            if (pattern[i] == pattern[j])
            {
                prefixTable[i] = j + 1;
                i++;
                j++;
            }
            else
            {
                if (j != 0)
                {
                    j = prefixTable[j - 1];
                }
                else
                {
                    prefixTable[i] = 0;
                    i++;
                }
            }
        }

        return prefixTable;
    }

    vector<int> search(string pattern, string text)
    {
        int n = text.size();
        int m = pattern.size();
        vector<int> result;
        vector<int> prefixTable;
        prefixTable = buildPrefixTable(pattern);
        int i = 0, j = 0;
        while (i < n)
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
                if (j == m)
                {
                    result.push_back(i - j + 1);
                    j = prefixTable[j - 1];
                }
            }
            else
            {
                if (j != 0)
                {
                    j = prefixTable[j - 1];
                }
                else
                {
                    i++;
                }
            }
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
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << -1 << endl;
        else
        {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends