class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l <= r){
            char l_s = toupper(s[l]);
            char r_s = toupper(s[r]);
            if (!isalnum(l_s)){
                l++;
            }else if (!isalnum(r_s)){
                r--;
            }else if (l_s != r_s){
                return false;
            }else{
                l++;
                r--;
            }
        }
        return true;
    }
};
