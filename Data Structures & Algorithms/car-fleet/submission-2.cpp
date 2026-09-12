class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
        vector<pair<int, int>> car;
        for (int i = 0; i < position.size(); i++){
            car.push_back({position[i], speed[i]});
        }

        sort(car.begin(), car.end(), [](const auto& a, const auto& b) {
            return a.first > b.first; 
        });

        int fleets = 0; 
        double prev_time = 0;
        for (int i = 0; i < car.size(); i++){
            double time = (double)(target - car[i].first)/car[i].second;
            if (time > prev_time){
                prev_time = time;
                fleets++;
            }
        }

        return fleets;
    }
};
