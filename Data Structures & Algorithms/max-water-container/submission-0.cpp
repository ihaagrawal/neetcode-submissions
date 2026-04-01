class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        int maxi = INT_MIN;

        while(i < j){
            int area = min(nums[i], nums[j]) * (j - i);
            maxi = max(maxi, area);

            if(nums[i] >= nums[j]) j--;
            else i++;  
        }

        return maxi;
    }
};
