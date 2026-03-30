class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<vector<int>> f(n+1);

        for (int x : nums)  freq[x]++;
        for (auto& ele : freq) f[ele.second].push_back(ele.first);

        vector<int> result;
        int i = n;
        bool flag = false;
        while (i >= 0) {
            if(f[i].size() > 0){
                for(auto& ele : f[i]){
                    result.push_back(ele);
                    k--;
                    if(k == 0){
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
            i--;
        }

        return result;
    }
};