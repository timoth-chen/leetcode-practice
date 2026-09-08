class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parentheses_map = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };
        vector<char> seen;
        for (char c: s){
            if (parentheses_map.contains(c)){
                seen.push_back(c);
            } else {
                if (seen.empty() || parentheses_map[seen.back()] != c){
                    return false;
                }
                seen.pop_back();
            }
        }
        return seen.empty();
    }
};
