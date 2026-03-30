class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        map<string, vector<string>> mp;

        for(string t : s){
            string word = t;
            sort(t.begin(), t.end()); 
            mp[t].push_back(word);
        }

        vector<vector<string>> result;
        for(auto element : mp) result.push_back(element.second);

        return result;
    }
};
