class Solution {

    class Node{
        public:
        int value;
        int row;
        int col;

    Node(int v, int r, int c){
        value = v;
        row = r;
        col = c;
    }
    };
    struct cmp{
        bool operator()(const Node& a, const Node& b){
            return a.value > b.value;
        }
    };
    public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Node, vector<Node>, cmp> pq;
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;

        for(int i = 0; i < n; i++){
            pq.push( {matrix[i][0], i, 0} );
        }

        while(k--){
            Node curr = pq.top();
            pq.pop();

            int v = curr.value;
            int r = curr.row;
            int c = curr.col;
            
            res = v;
            if (c + 1 < m)
            pq.push( {matrix[r][c + 1], r, c + 1} );
        }

       return res;
    }
};