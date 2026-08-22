class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> filtered;
        for (string str : strs){
            string temp_str = str;
            sort(temp_str.begin(), temp_str.end());
            filtered[temp_str].push_back(str);
        }

        vector<vector<string>> ans;
        for (const auto &[key, value]: filtered){
            ans.push_back(value);
        }
        return ans;
    }
};
