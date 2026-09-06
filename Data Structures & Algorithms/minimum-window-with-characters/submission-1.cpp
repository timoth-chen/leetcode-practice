class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()){
            return "";
        }

        unordered_map<char, int> window, t_map;
        for (char c : t){
            t_map[c]++;
        }

        int have = 0, need = t_map.size();
        pair<int, int> substring;
        int min_window = INT_MAX, l =0;

        for (int r = 0; r < s.size(); r++){
            char key = s[r];
            window[key]++;
            if (t_map.contains(key) && window[key] == t_map[key]){
                have++;
            }

            while(have == need){
                if ((r - l + 1) < min_window){
                    substring = {l, r};
                    min_window = r - l + 1;
                }

                key = s[l];
                window[key]--;
                if(t_map.contains(key) && window[key] < t_map[key]){
                    have--;
                }
                l++;
            }
        }
        return min_window == INT_MAX ? "" : s.substr(substring.first, min_window );
    }
};
