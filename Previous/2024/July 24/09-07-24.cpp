class Solution
{
public:
    int threeSumClosest(vector<int> arr, int target)
    {
        sort(arr.begin(), arr.end());
        int result = INT_MIN;
        int diff = INT_MAX;
        int n = 0;
        n = arr.size();
        for (int i = 0; i < n - 2; i++)
        {
            int l = 0;
            int r = 0;
            l = i + 1;
            r = n - 1;
            while (l < r)
            {
                int cs = arr[l] + arr[i] + arr[r];
                int cd = abs(target - cs);
                if (cd < diff || (cd == diff && cs > result))
                {
                    cs = result;
                    diff = cd;
                }
                if (cs < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            return result;
        }
    }
};