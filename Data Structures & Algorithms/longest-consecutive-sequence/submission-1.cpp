class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxi = INT_MIN, count = 1;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-1;i++){
            if(abs(nums[i] - nums[i+1]) == 0) continue;
            if(abs(nums[i] - nums[i+1]) == 1) count++;
            else {
                maxi = max(count, maxi);
                count = 1;
            }
        }
        maxi = max(count, maxi);
        return maxi;
    }
};
