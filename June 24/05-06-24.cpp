//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int findSwapValues(int a[], int n, int b[], int m)
    {
        int suma1 = 0;
        int sumb1 = 0;
        for (int i = 0; i < n; i++)
        {
            suma1 += a[i];
        }
        for (int i = 0; i < m; i++)
        {
            sumb1 += b[i];
        }
        if ((suma1 - sumb1) % 2 != 0)
        {
            return -1;
        }
        int target1 = 0;
        target1 = (suma1 - sumb1) / 2;
        int i = 0;
        int j = 0;
        sort(a, a + n);
        sort(b, b + m);
        while (i < n && j < m)
        {
            int diff1 = 0;
            diff1 = [i] - b[j];
            if (diff1 == target1)
            {
                return 1;
            }
            else if (diff1 < target1)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends