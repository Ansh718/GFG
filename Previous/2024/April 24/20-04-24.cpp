//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        if (arr1[0] > arr2[0])
        {
            return findUnion(arr2, arr1, m, n);
        }
        vector<int> result = {arr1[0]};
        int ptr1 = 0;
        ptr1 = 1;
        int ptr2 = 0;
        while (ptr1 < n && ptr2 < m)
        {
            if (arr1[ptr1] < arr2[ptr2])
            {
                if (result.back() != arr1[ptr1])
                {
                    result.push_back(arr1[ptr1]);
                }
                ptr1++;
            }
            else
            {
                if (result.back() != arr2[ptr2])
                {
                    result.push_back(arr2[ptr2]);
                }
                ptr2++;
            }
        }
        while (ptr1 < n)
        {
            if (result.back() != arr1[ptr1])
            {
                result.push_back(arr1[ptr1]);
            }
            ptr1++;
        }
        while (ptr2 < m)
        {
            if (result.back() != arr2[ptr2])
            {
                result.push_back(arr2[ptr2]);
            }
            ptr2++;
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        int N, M;
        cin >> N >> M;

        int arr1[N];
        int arr2[M];

        for (int i = 0; i < N; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < M; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        vector<int> ans = ob.findUnion(arr1, arr2, N, M);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends