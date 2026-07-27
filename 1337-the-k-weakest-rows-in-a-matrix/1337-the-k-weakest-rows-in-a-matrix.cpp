class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        priority_queue<pair<int, int>> pq;
        vector<int> res;

        for(int i = 0; i<n; i++){

            int count = 0;
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1) count++;
            }
            pq.push( {count, i } );

            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){

        res.push_back(pq.top().second);
        pq.pop();
      }
      reverse(res.begin(), res.end());
      return res;
    } 
};