class Solution {
public:

    bool isAnagram(string s, string t){
        int n = s.size(), m = t.size();
        if(n != m) return false;

        vector<int> f(26, 0);
        for(int i=0;i<n;i++){
            f[s[i] - 'a']++;
            f[t[i] - 'a']--;
        }

        for(int i=0;i<26;i++){
            if(f[i] != 0) return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        vector<vector<string>> result;

        int i = 0;
        while(!s.empty()){
            string t = s[0];
            vector<string> temp;
            temp.push_back(t);
            
            for(int j=1;j<s.size();j++){
                if(isAnagram(t, s[j])){
                    temp.push_back(s[j]);
                    s.erase(s.begin() + j);
                    j--;
                }
            }
            s.erase(remove(s.begin(), s.end(), t), s.end());
            result.push_back(temp);
        }

        return result;
    }
};
