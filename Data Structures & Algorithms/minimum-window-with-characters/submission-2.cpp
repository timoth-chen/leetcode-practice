class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()){
            return "";
        }

        unordered_map<char, int> window, t_map;
        for (char c: t){
            t_map[c]++;
        }

        int have = 0, need = t_map.size();
        pair<int, int> str_pos;
        int min_len = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.size(); r++){
            char key = s[r];
            window[key]++;

            if (t_map.contains(key) && t_map[key] == window[key]){
                have++;
            }

            while (have == need){
                if ((r - l + 1) < min_len){
                    str_pos = {l, r};
                    min_len = r - l + 1;
                }

                key = s[l];
                window[key]--;
                if (t_map.contains(key) && t_map[key] > window[key]){
                    have--;
                }
                l++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(str_pos.first, min_len);
    }
};
