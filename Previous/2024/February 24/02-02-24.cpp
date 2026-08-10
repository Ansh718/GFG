//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int atoi(string s)
    {
        if (s.size() == 1)
        {
            if (s[0] >= '0' && s[0] <= '9')
            {
                return s[0] - '0';
            }
            else if (s[0] == '-')
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            if (s[0] != '-' && (s[0] < '0' || s[0] > '9'))
            {
                return -1;
            }
            else
            {
                if (s[0] == '-')
                {
                    long long int cnt = 0;
                    long long int temp = s.size() - 1;
                    long long int a = 0;
                    for (long long int i = 1; i < s.size(); i++)
                    {
                        if (s[i] >= '0' && s[i] <= '9')
                        {
                            cnt++;
                        }
                        a += (s[i] - '0') * pow(10, temp);
                        temp--;
                    }
                    if (cnt == s.size() - 1)
                    {
                        return -(a / 10);
                    }
                    else
                    {
                        return -1;
                    }
                }
                else
                {
                    long long int cnt = 0;
                    long long int temp = s.size();
                    long long int a = 0;
                    for (long long int i = 0; i < s.size(); i++)
                    {
                        if (s[i] >= '0' && s[i] <= '9')
                        {
                            cnt++;
                        }
                        a += (s[i] - '0') * pow(10, temp);
                        temp--;
                    }
                    if (cnt == s.size())
                    {
                        return a / 10;
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
        }
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
        cout << ob.atoi(s) << endl;
    }
}
// } Driver Code Ends