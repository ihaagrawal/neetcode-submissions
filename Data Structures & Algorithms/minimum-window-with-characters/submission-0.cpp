class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return "";

        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;

        int i = 0, j = 0;
        int required = m;
        int minLen = INT_MAX, start = 0;

        while (j < n) {
            if (mp[s[j]] > 0) required--;
            mp[s[j]]--;

            while (required == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] > 0) required++;
                i++;
            }

            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};