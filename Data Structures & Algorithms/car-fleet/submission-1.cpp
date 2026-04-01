class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        int n = p.size();
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - p[i]) / s[i];
            cars.push_back({p[i], time});
        }

        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lastTime = 0;

        for (auto &car : cars) {
            if (car.second > lastTime) {
                fleets++;
                lastTime = car.second;
            }
        }

        return fleets;
    }
};