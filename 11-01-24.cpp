//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string removeKdigits(string S, int K)
    {
        pair<int, int> last = {0, K};
        int size = S.size();
        int index = 0;
        while (index < size)
        {
            if (S[index] != '0')
            {
                if (K > 0)
                {
                    K--;
                }
                else
                {
                    break;
                }
                index++;
            }
            else
            {
                while (index < size && S[index] == '0')
                {
                    index++;
                }
                last = {index, K};
            }
        }
        stack<int> st;
        int start = 0;
        start = last.first;
        K = last.second;
        for (int i = start; i < size; i++)
        {
            while (st.size() && st.top() > (S[i] - '0') && K)
            {
                K--;
                st.pop();
            }
            st.push(S[i] - '0');
        }
        while (st.size() && K--)
        {
            st.pop();
        }
        string result = "";
        while (st.size())
        {
            result += to_string(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        if (result == "")
        {
            result = "0";
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
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends