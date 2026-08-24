class Solution {
public:

    string encode(vector<string>& strs) {
        string encode_string = "";
        for (string s: strs){
            int len_string = s.size();
            encode_string = encode_string + to_string(len_string) + "#" + s;
        }
        cout << encode_string << endl;
        return encode_string;
    }

    vector<string> decode(string s) {
        int ptr = 0;
        string len_str = "";
        vector<string> ans;
        while (ptr < s.size()){ 
            len_str += s[ptr];
            cout << len_str << endl;
            cout << ptr << endl;
            if(s[ptr] == '#'){
                cout << "len: "<< len_str.substr(0, len_str.size()-1) << endl;
                cout << "str " << s.substr(ptr + 1, stoi(len_str.substr(0, len_str.size()-1))) << endl;
                ans.push_back(s.substr(ptr + 1, stoi(len_str.substr(0, len_str.size()-1))));
                ptr += stoi(len_str.substr(0, len_str.size()-1)) + 1;
                len_str = "";
                
            }else{
                ptr++;
            }
        }
        cout << s[1] << endl;
        return ans;
    }
};
