class Solution
{
public:
    int countTriplets(vector<int> &arr, int target)
    {
        int n = arr.size();
        int cnt = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == target)
                {
                    if (arr[j] == arr[k])
                    {
                        int count = k - j + 1;
                        cnt += (count * (count - 1)) / 2;
                        break;
                    }
                    else
                    {
                        int leftCount = 1, rightCount = 1;
                        while (j + 1 < k && arr[j] == arr[j + 1])
                        {
                            leftCount++;
                            j++;
                        }
                        while (k - 1 > j && arr[k] == arr[k - 1])
                        {
                            rightCount++;
                            k--;
                        }
                        cnt += leftCount * rightCount;
                        j++;
                        k--;
                    }
                }
                else if (sum < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return cnt;
    }
};