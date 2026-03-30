class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m) return false;

        vector<int> a(26, 0);
        int i = 0, j = 0;
        while(i < n){
            a[s[i++] - 'a']++;
            a[t[j++] - 'a']--;
        }

        for(i=0;i<26;i++){
            if(a[i] != 0) return false;
        }

        return true;
    }
};
