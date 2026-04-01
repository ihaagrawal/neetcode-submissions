class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        int i = 0, j = 0;
        int maxi = INT_MIN, index = -1;

        while (j < k) {
            if (nums[j] >= maxi) {
                maxi = nums[j];
                index = j;
            }
            j++;
        }

        res.push_back(maxi);

        while (j < n) {
            i++; 

            if (index < i) { 
                maxi = INT_MIN;
                for (int l = i; l <= j; l++) {
                    if (nums[l] >= maxi) {
                        maxi = nums[l];
                        index = l;
                    }
                }
            } else if (nums[j] >= maxi) {
                maxi = nums[j];
                index = j;
            }

            res.push_back(maxi);
            j++;
        }

        return res;
    }
};