//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    char nthCharacter(string s, int r, int n)
    {
        int l = s.length();
        for (int i = 0; i < r; i++)
        {
            string chc = s;
            for (int j = 0; j < l; j++)
            {
                if (chc[j / 2] == '1')
                {
                    s[j] = '1' - (j % 2);
                }
                else
                {
                    s[j] = '0' + (j % 2);
                }
            }
        }
        return s[n];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends