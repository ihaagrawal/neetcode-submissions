class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pdt = 1;
        int zeroCount = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0) pdt *= nums[i];
            else zeroCount++;
        }

        vector<int> result(n, 0);

        for(int i = 0; i < n; i++){
            if(zeroCount > 1) result[i] = 0;
            else if(zeroCount == 1){
                if(nums[i] == 0) result[i] = pdt;
                else result[i] = 0;
            }
            else result[i] = pdt / nums[i];
        }

        return result;
    }
};