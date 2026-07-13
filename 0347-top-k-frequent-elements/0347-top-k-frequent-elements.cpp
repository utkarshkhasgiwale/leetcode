class Solution {
public:

        // Min heap on first, Min on second

   struct cmp {
       bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
           if(a.first == b.first)
               return a.second > b.second;   
           return a.first > b.first;        
       }
   };
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;


    
    int n = nums.size();
    unordered_map<int,int> f;

    for(int i = 0; i < n; i++)
       f[nums[i]]++;
       
    for(auto x: f){
        int element = x.first;
        int freq = x.second;

         pair<int,int> curr = {freq, element};

        if(pq.size() < k) pq.push(curr);
        else{
            if(pq.top().first > curr.first) 
                continue;
            pq.pop();
            pq.push(curr);
        }
    }
    vector<int> res;
    while(!pq.empty()){
      res.push_back(pq.top().second);
      pq.pop();
    }
    return res;
    }
};