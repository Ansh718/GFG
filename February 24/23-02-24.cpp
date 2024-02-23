//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int maxProfit(vector<int> &price)
    {
        vector<int> profit(price.size(), 0);
        int maX = 0;
        maX = price[price.size() - 1];
        for (int i = price.size() - 2; i > -1; i--)
        {
            if (price[i] > maX)
            {
                maX = price[i];
            }
            profit[i] = max(profit[i + 1], maX - price[i]);
        }
        int miN = 0;
        miN = price[0];
        for (int i = 1; i < price.size(); i++)
        {
            if (price[i] < miN)
            {
                miN = price[i];
            }
            profit[i] = max(profit[i - 1], profit[i] + price[i] - miN);
        }
        return profit[price.size() - 1];
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
        vector<int> price(n);
        for (int i = 0; i < n; i++)
            cin >> price[i];
        Solution obj;
        cout << obj.maxProfit(price) << endl;
    }
}

// } Driver Code Ends