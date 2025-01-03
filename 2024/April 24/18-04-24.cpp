//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// User function template for C++

class Solution
{
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int arr[], int n)
    {
        vector<int> result;
        for (int i = 0; i < n + 2; i++)
        {
            int index = 0;
            index = abs(arr[i]) - 1;
            if (arr[index] > 0)
            {
                arr[index] = -arr[index];
            }
            else
            {
                result.push_back(index + 1);
            }
        }
        result.push_back(abs(arr[result[0] - 1]));
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        int a[n + 2];

        for (int i = 0; i < n + 2; i++)
            cin >> a[i];

        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}

// } Driver Code Ends