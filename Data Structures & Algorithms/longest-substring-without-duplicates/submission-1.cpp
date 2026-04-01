class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        map<char, int> mp;

        int i = 0, j = 1, res = 1;
        mp[s[i]] = i;

        while(j < n){
            if(mp.find(s[j]) != mp.end()){
                i = max(i, mp[s[j]] + 1);
            }
            mp[s[j]] = j;
            res = max(res, j - i + 1);
            j++;
        }
        
        return res;
    }
};
