class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long total = 0;
        for(int x : nums) total += x;

        int r = total % p;
        if(r == 0) return 0;

        unordered_map<int,int> mp;
        mp[0] = -1;

        long prefix = 0;
        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            int mod = prefix % p;

            int target = (mod - r + p) % p;

            if(mp.count(target))
                ans = min(ans, i - mp[target]);

            mp[mod] = i;
        }

        if(ans == nums.size()) return -1;
        return ans;
    }
};