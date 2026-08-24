class Solution {
public:

    string encode(vector<string>& strs) {
        string encode_string = "";
        for (string s: strs){
            encode_string += to_string(s.size());
            encode_string += "#";
            encode_string += s;
        }
        return encode_string;
    }

    vector<string> decode(string s) {
        int i = 0;

        vector<string> ans;
        while (i < s.size()){ 
            int j = i;
            while (s[j] != '#'){
                j++;
            }
            int len_str = stoi(s.substr(i, j - i));
            i = j + 1;
            ans.push_back(s.substr(i, len_str));
            i += len_str;
        }
        return ans;
    }
};
