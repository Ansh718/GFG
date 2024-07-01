//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long ExtractNumber(string sentence)
    {
        long long result = -1;
        string number = "";
        for (char ch : sentence)
        {
            if (isdigit(ch))
            {
                number += ch;
            }
            else
            {
                if (!number.empty() && number.find('9') == string::npos)
                {
                    long long num = stoll(number);
                    result = max(result, num);
                }
                number = "";
            }
        }
        if (!number.empty() && number.find('9') == string::npos)
        {
            long long num = stoll(number);
            result = max(result, num);
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends