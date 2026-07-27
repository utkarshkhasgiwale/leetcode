class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int,int>> pq;
        vector<int> res;

        for(auto nums: arr){
            int dist  = abs(nums - x);
            pq.push( {dist, nums} );

            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){

       res.push_back(pq.top().second);
       pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};