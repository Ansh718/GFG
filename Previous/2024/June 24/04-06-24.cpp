//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string binaryNextNumber(string s)
    {
        reverse(s.begin(), s.end());
        int carry1 = 1;
        for (int i = 0; i < s.length() && carry1 == 1; i++)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
                carry1 = 0;
            }
            else
            {
                s[i] = '0';
                carry1 = 1;
            }
        }
        if (carry1)
        {
            s = s + '1';
        }
        reverse(s.begin(), s.end());
        int idx1 = 0;
        while (s[idx1] == '0')
        {
            idx1++;
        }
        int n1 = s.length();
        return s.substr(idx1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends