//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define d 256
class Solution
{
public:
    vector<int> search(string pattern, string text)
    {
        vector<int> result;
        int M = pattern.size();
        int N = text.size();
        int i, j;
        int p = 0;
        int t = 0;
        int h = 1;
        int q = 0;
        q = INT_MAX;
        for (i = 0; i < M - 1; i++)
        {
            h = (h * d) % q;
        }
        for (i = 0; i < M; i++)
        {
            p = (d * p + pattern[i]) % q;
            t = (d * t + text[i]) % q;
        }
        for (i = 0; i <= N - M; i++)
        {
            if (p == t)
            {
                for (j = 0; j < M; j++)
                {
                    if (text[i + j] != pattern[j])
                    {
                        break;
                    }
                }
                if (j == M)
                {
                    result.push_back(i + 1);
                }
            }
            if (i < N - M)
            {
                t = (d * (t - text[i] * h) + text[i + M]) % q;
                if (t < 0)
                {
                    t = (t + q);
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
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends