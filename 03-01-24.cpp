//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int smallestSubstring(string S)
    {
        // set<char> st;
        // st.insert(S[0]);
        // int ans=0;
        // int flag=0;
        // for(int i=1;i<S.size();i++){
        //     if(st.size()==3){
        //         flag=1;
        //         ans=i;
        //         break;
        //     }
        //     if(S[i]!=S[i-1]){
        //         st.insert(S[i]);
        //     }
        // }
        // if(flag==1 || st.size()==3){
        //     return ans;
        // }
        // return -1;
        vector<int> position(3, -1);
        int op = INT_MAX;
        for (int i = 0; i < S.size(); ++i)
        {
            position[S[i] - '0'] = i;

            int miN = INT_MAX, maX = 0;
            for (auto itr : position)
            {
                miN = min(miN, itr);
                maX = max(maX, itr);
            }

            if (miN != -1)
                op = min(op, maX - miN + 1);
        }

        return op == INT_MAX ? -1 : op;
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
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends