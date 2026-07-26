class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> ans;

        for (auto& point : points) {
            int dist = point[0] * point[0] + point[1] * point[1];
            pq.push({dist, point});

            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};