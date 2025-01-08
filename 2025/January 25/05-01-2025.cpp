class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        int n = 0;
        n = arr.size();
        int cnt = 0;
        sort(arr.begin(), arr.end());
        int left = 0;
        int right = 0;
        right = n - 1;
        while (left < right)
        {
            int s = 0;
            s = arr[left] + arr[right];
            if (s < target)
            {
                cnt += right - left;
                left++;
            }
            else
            {
                right--;
            }
        }
        return cnt;
    }
};