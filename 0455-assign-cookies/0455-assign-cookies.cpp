class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int> pq;
        int ans = 0;
        sort(s.begin(), s.end());

        for(auto x : g) pq.push(x);

        for(int i = s.size()-1; i >= 0; i--){
           
           while(!pq.empty()){
              
            if(s[i] >= pq.top()) {
            ans++;
            pq.pop();
            break;
            }
            else{
                pq.pop();
            }
         
        }
        }
        return ans;
    }
};