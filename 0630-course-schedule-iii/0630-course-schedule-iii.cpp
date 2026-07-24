class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(),[](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });
      int totalTime = 0;
      int res = 0;
      priority_queue<int> pq;
      for(auto &course : courses){
        totalTime += course[0];
        pq.push(course[0]);
        if(totalTime > course[1]){
            int longest = pq.top();
            pq.pop();
            totalTime -= longest;
        }
      }
     while(!pq.empty()){
        pq.pop();
        res += 1;
     }
     return res;
    }
};