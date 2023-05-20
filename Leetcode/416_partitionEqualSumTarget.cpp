class Solution
{
public:
    /*
    Naïve approach
       1.recursion
       2.memoization
       3.DP
   */
    // pepcoding striver
    bool targetSum(int sum, vector<int> &nums)
    {
        vector<bool> prev(sum + 1, false);
        for (int i = 0; i < nums.size() + 1; i++)
        {
            vector<bool> cur(sum + 1, false);
            for (int j = 0; j < sum + 1; j++)
            {
                if (j == 0)
                    cur[j] = true;
                else if (i == 0)
                    cur[j] = false;
                else if (j >= nums[i - 1])
                    cur[j] = prev[j] || prev[j - nums[i - 1]];
                else
                    cur[j] = prev[j];
            }
            prev = cur;
        }
        return prev[sum];
    }

    bool canPartition(vector<int> &nums)
    {
        int total = 0, n = nums.size();
        for (auto i : nums)
            total += i;
        // odd-even
        return total & 1 ? false : targetSum(total / 2, nums);
    }
};