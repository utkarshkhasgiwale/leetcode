class Solution {
public:
    int leastInterval(vector<char>& tasks, int gap) {
        int n = tasks.size();
         unordered_map<char, int> freq;
         unordered_map<char, int> free;
          priority_queue<pair<int, char>> pq;
          int seat = 0;
         
          for(int i = 0; i < n; i++) {
            freq[tasks[i]]++;
            free[tasks[i]] = 0;
            }

          for(auto x : freq)
           pq.push( {x.second, x.first} );

          while(!pq.empty()){
            vector<pair<int,char>> pulled;
            while(!pq.empty()){
                pair<int,char> p = pq.top();
                pq.pop();

                int times = p.first;
                char letter = p.second;

                if(free[letter] <= seat){

                    if(p.first > 1) pq.push( {p.first-1, p.second} );

                free[p.second] = seat + gap + 1;
                break;

                }

                else pulled.push_back(p);
            }
            for(auto x : pulled) pq.push(x);
            seat++;
          }

        return seat;
    }
};