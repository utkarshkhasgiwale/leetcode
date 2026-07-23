class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        stations.push_back({target, 0});
        int n = stations.size();
        priority_queue<int> pq;
        int prev = 0;
        int stop = 0;
        int fuel = startFuel;

        for(int i = 0; i < n; i++){
        int stationPosition = stations[i][0];
        int stationFuel = stations[i][1];

        int distance = stationPosition - prev;

        fuel -= distance;

        while(fuel < 0){
            if(pq.empty()) return -1;
            fuel += pq.top();
            pq.pop();
            stop++;
        }
        pq.push(stationFuel);
        prev = stationPosition;
        }
        return stop;
    }
};