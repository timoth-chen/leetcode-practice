class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()){
            return false;
        }
        vector<int> s1_count(26, 0), s2_count(26, 0);
        for (int i = 0; i < s1.size(); i++){
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++){
            if(s1_count[i] == s2_count[i]){
                matches++;
            }
        }
        
        int l = 0, index;
        for (int r = s1.size(); r < s2.size(); r++){
            cout << matches << endl;
            if (matches == 26){
                return true;
            }

            index = s2[l] - 'a';
            l++;
            s2_count[index]--;
            if (s2_count[index] == s1_count[index]){
                matches++;
            }else if (s2_count[index] + 1 == s1_count[index]){
                matches --;
            }

            index = s2[r] - 'a';
            s2_count[index]++;
            if (s2_count[index] == s1_count[index]){
                matches++;
            }else if (s2_count[index] - 1 == s1_count[index]){
                matches --;
            }
            cout << matches << endl;
        }
        return matches == 26;
    }
};
