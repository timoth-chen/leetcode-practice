class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1.size() <= nums2.size() ? nums1 : nums2;
        vector<int>& B = nums1.size() <= nums2.size() ? nums2 : nums1;
        int m = A.size(), n = B.size();
        int total = m + n;
        int half = (total + 1)/2;

        int l = 0, r = m;
        while (l <= r){
            cout << l << " " << r << endl;
            int i = l + (r - l)/2;
            int j = half - i;

            int leftA = i > 0 ? A[i - 1] : INT_MIN;
            int rightA = i < m ? A[i] : INT_MAX;
            int leftB = j > 0 ? B[j - 1] : INT_MIN;
            int rightB = j < n ? B[j] : INT_MAX;
            
            if (leftA <= rightB && leftB <= rightA){
                if (total % 2 != 0){
                    return max(leftA, leftB);
                }
                return (max(leftA, leftB) + min(rightA, rightB))/2.0;
            } else if(leftA > rightB){
                r = i - 1;
            } else{
                l = i + 1;
            }
        }
        return - 1;
    }
};
