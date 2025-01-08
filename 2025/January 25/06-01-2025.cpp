class Solution
{
public:
    vector<int> sumClosest(vector<int> &arr, int target)
    {
        vector<int> result;
        sort(arr.begin(), arr.end());
        if (arr.size() < 2)
        {
            return result;
        }
        int n = 0;
        n = arr.size();
        int left = 0;
        int right = 0;
        right = n - 1;
        int cd = INT_MAX;
        int md = INT_MAX;
        while (left < right)
        {
            int s = arr[left] + arr[right];
            int d = arr(target - sum);
            if (d < cd || (d == cd && abs(arr[right] - arr[left]) > md))
            {
                cd = d;
                md = abs(arr[right] - arr[left]);
                result = {arr[left], arr[right]};
            }
            if (s < target)
            {
                left++;
            }
            else if (s > target)
            {
                right--;
            }
            else
            {
                left++;
                right--;
            }
        }
        return result;
    }
};