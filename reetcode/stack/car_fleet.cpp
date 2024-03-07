
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // 뒷차는 앞차를 추월할 수 없다.
        // road위에 차가 없을때까지 시뮬레이션을 해야한다.
        
        vector<pair<int,double>> road;
        // # of fleets
        int cnt = 0;
        int n = position.size();
        for(int i=0; i<n; i++) {
            double time = (target - position[i]) / (double)speed[i];
            road.push_back({position[i],time});
        }
        sort(road.begin(), road.end());
        double max_time = -1;
        for(int i=n-1; i>=0; i--) {
            double time = road[i].second;
            if(time > max_time) {
                max_time = time;
                cnt++;
            }
        }
        return (cnt);
        
    }
};