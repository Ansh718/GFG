class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        int n = arr.size();
        int start = 0, end = 0;
        long long currentSum = 0;

        while (end < n)
        {
            currentSum += arr[end];
            while (currentSum > target && start <= end)
            {
                currentSum -= arr[start];
                start++;
            }
            if (currentSum == target)
            {
                return {start + 1, end + 1};
            }
            end++;
        }
        return {-1};
    }
};