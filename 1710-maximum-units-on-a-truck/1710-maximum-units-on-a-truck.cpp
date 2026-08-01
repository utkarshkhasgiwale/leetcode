class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        struct Compare {
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        int totalBoxes = 0;

        for (const auto &x : boxTypes) {
           pq.push({x[0], x[1]});
        }
        while (!pq.empty() && truckSize > 0) {
            int boxes = pq.top().first;
            int noOfUnitsPerBox = pq.top().second;
            pq.pop();

           int take = min(boxes, truckSize);
            
            totalBoxes += take * noOfUnitsPerBox;

            truckSize -= take;

        }
        return totalBoxes;
    }
};