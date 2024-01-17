class Solution
{
public:
    void helper(int t, vector<int> &arr, vector<int> &v1, vector<int> &v2, vector<vector<int>> &result)
    {
        if (t == arr.size())
        {
            result.push_back(v1);
            return;
        }

        vector<int> v3(11, 0);

        for (int i = 0; i < arr.size(); i++)
        {
            if (!v2[i] && !v3[arr[i]])
            {
                v3[arr[i]] = 1;
                v2[i] = 1;
                v1.push_back(arr[i]); 
                helper(t + 1, arr, v1, v2, result);
                v1.pop_back();
                v2[i] = 0;
            }
        }
    }

    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        vector<vector<int>> result;
        vector<int> v1;
        vector<int> v2(n, 0);
        helper(0, arr, v1, v2, result);
        sort(result.begin(), result.end());
        return result;
    }
};
