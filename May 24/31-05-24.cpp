//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int swapNibbles(int n)
    {
        int lowerNibble = n & 0x0F;
        int upperNibble = n & 0xF0;
        lowerNibble = lowerNibble << 4;
        upperNibble = upperNibble >> 4;
        return (lowerNibble | upperNibble);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends