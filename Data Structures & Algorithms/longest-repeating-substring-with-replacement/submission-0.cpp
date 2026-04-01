class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> f;
        int res = 0;

        int i = 0, j = 1, maxf = 0;
        f[s[i]] = 1;

        while(j < n){
            f[s[j]]++;
            maxf = max(maxf, f[s[j]]);
            while((j - i + 1) - maxf > k){
                f[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }

        return res;
    }
};
