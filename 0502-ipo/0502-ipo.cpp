class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects;
        for(int i = 0; i < n; i++) projects.push_back({ capital[i], profits[i] });
        priority_queue<int> pq;
        sort(projects.begin(), projects.end());
        int i = 0;
        while(k--){
          while(i < n){
                if(projects[i].first > w) break;
                pq.push(projects[i].second);
                i++;
            }
            if(pq.empty()) return w;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};