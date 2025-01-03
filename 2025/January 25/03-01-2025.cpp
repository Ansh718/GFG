class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        unordered_map<int, int> ump;
        ump[0] = 1;
        int xoR = 0;
        int cnt = 0;
        int n = 0;
        n = arr.size();
        for (int i = 0; i < n; i++)
        {
            xoR ^= arr[i];
            if (ump.find(xoR ^ k) != ump.end())
            {
                cnt += ump[xoR ^ k];
            }
            ump[xoR]++;
        }
        return cnt;
    }
};