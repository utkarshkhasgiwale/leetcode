class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        // int res = 0;

        for(auto x: stones) pq.push(x);

        while(pq.size() > 1){
           int p1 = pq.top();
            pq.pop();
           int p2 = pq.top();
            pq.pop();
           if(p1 == p2) continue;
           int p3 = p1 - p2;
           pq.push(p3);
        }
       return pq.empty() ? 0 : pq.top();
    }
};