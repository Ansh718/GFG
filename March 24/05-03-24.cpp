//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n)
    {
        vector<int> left(n);
        vector<int> right(n);
        int result = -1;
        left[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = min(left[i - 1], a[i]);
        }
        right[n - 1] = a[n - 1];
        for (int i = n - 2; i > -1; i--)
        {
            right[i] = max(right[i + 1], a[i]);
        }
        int ptr1 = 0;
        int ptr2 = 0;
        while (ptr2 < n && ptr1 < n)
        {
            if (left[ptr1] <= right[ptr2])
            {
                result = max(result, ptr2 - ptr1);
                ptr2 += 1;
            }
            else
            {
                ptr1 += 1;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    // testcases
    cin >> T;
    while (T--)
    {
        int num;
        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;
    }
    return 0;
}
// } Driver Code Ends