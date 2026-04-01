class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> f(26, 0);

        for(int i = 0; i < n; i++) f[s1[i] - 'a']++;

        for(int i = 0; i + n <= m; i++){   
            bool flag = true;
            vector<int> freq = f;

            for(int j = i; j < i + n; j++){   
                if(freq[s2[j] - 'a'] > 0) freq[s2[j] - 'a']--;
                else{
                    flag = false;
                    break;
                }
            }

            if(flag) return true;
        }

        return false;
    }
};