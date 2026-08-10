class Solution
{
public:
    int countSubarrays(vector<int> &arr, int k)
    {
        unordered_map<int, int> ump;
        ump[0] = 1;
        int s = 0;
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            s += arr[i];
            if (ump.find(s - k) != ump.end())
            {
                cnt += ump[s - k];
            }
            ump[s]++;
        }
        return cnt;
    }
};