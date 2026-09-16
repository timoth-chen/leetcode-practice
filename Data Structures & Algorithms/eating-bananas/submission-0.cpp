class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_pile = 0;
        for (int pile: piles)
            max_pile = max(max_pile, pile);

        int min_speed = INT_MAX;
        int l = 1, r = max_pile;
        while (l <= r){
            int mid = l + (r - l)/2;
            int cur_h = 0;
            for (int pile: piles)
                cur_h += (pile + mid - 1)/mid;
            
            if (cur_h > h){
                l = mid + 1;
            }else{
                min_speed = min(min_speed, mid);
                r = mid - 1;
            }
        }
        return min_speed;
    }
};
