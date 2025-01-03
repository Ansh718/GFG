//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int maxOccured(int n, int l[], int r[], int maxx)
    {
        vector<int> arr(maxx + 2, 0);
        for (int i = 0; i < n; i++)
        {
            arr[l[i]] += 1;
            arr[r[i] + 1] -= 1;
        }
        int maxCount = arr[0];
        int result = 0;
        for (int i = 1; i <= maxx; i++)
        {
            arr[i] += arr[i - 1];
            if (arr[i] > maxCount)
            {
                maxCount = arr[i];
                result = i;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++)
        {

            cin >> r[i];
            if (r[i] > maxx)
            {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends