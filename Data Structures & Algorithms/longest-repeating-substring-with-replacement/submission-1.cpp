class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> count;
        int l = 0, max_freq = 0, longest_char = 0;
        for (int r = 0; r < s.size(); r++){
            count[s[r]]++;
            max_freq = max(max_freq, count[s[r]]);
            while ((r - l + 1) - max_freq > k){
                count[s[l]]--;
                l++;
            }
            longest_char = max(r - l +1, longest_char);
        }
        return longest_char;

    }
};
