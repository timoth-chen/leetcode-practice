class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> char_seen;
        int longest_substring = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++){
            while(char_seen.find(s[r]) != char_seen.end()){
                char_seen.erase(s[l]);
                l++;
            }
            char_seen.insert(s[r]);
            longest_substring = max(longest_substring, r - l + 1);
        }
        return longest_substring;
    }
};
