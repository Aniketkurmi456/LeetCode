class Solution {
public:
    int n;

    int solve(vector<int>& nums, int target, int sum, int i) {
        if (i == n) {
            return sum == target;
        }

        int add = solve(nums, target, sum + nums[i], i + 1);
        int sub = solve(nums, target, sum - nums[i], i + 1);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        int sum = 0;
        for (int x : nums) {
            sum += x;
        }

        if (target > sum || target < -sum) {
            return 0;
        }

        return solve(nums, target, 0, 0);
    }
};
