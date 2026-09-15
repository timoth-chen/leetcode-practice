class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int t = 0, b = row - 1;
        int l = 0, r = col - 1;
        while (t <= b){
            int rmid = t + (b - t)/2;
            if (target > matrix[rmid][r]){
                t = rmid + 1;
            } else if (target < matrix[rmid][0]){
                b = rmid - 1;
            } else{
                while (l <= r){
                    int cmid = l + (r - l)/2;
                    if (target < matrix[rmid][cmid]) r = cmid - 1;
                    else if (target > matrix[rmid][cmid]) l = cmid + 1;
                    else return true;
                }
                return false;
            }
        }
        return false;
    }
};
