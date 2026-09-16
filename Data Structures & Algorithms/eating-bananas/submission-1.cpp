class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int min_speed = r;

        while (l <= r){
            int mid = l + (r - l)/2;
            long long cur_h = 0;
            for (int pile: piles)
                cur_h += ceil(static_cast<double>(pile)/mid);
            
            if (cur_h > h){
                l = mid + 1;
            }else{
                min_speed = mid;
                r = mid - 1;
            }
        }
        return min_speed;
    }
};
