class Solution {
public:
    bool Jump(vector<int>& v, vector<int>& dp, int l, int i)
    {
        if(i >= l) return true;

        if(dp[i] != -1)
            return dp[i];

        for(int step = 1; step <= v[i]; step++)
        {
            if(Jump(v, dp, l, i + step))
            {
                return dp[i] = 1;
            }
        }

        return dp[i] = 0;
    }
    bool canJump(vector<int>& nums) {
        
        vector<int> dp(nums.size(), -1);
        return Jump(nums, dp, nums.size()-1, 0);
        
    }
};