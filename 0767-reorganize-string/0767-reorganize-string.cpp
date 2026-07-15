class Solution {
public:
    string reorganizeString(string s) {

        int n = s.size();
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> f;
        string res = ""; 
        int seat = 0;
  
//   first step get freq by storingthemin hashmap
        for(int i = 0; i < n; i++){
            f[s[i]]++;
        }
// make pairs then store in heap
        for(auto x: f){
            int freq = x.second;
            char letter = x.first;

            pair<int, char> curr = { freq, letter };
            pq.push(curr);
        }

        while(!pq.empty()){
            pair<int, char> p1 = pq.top();
            pq.pop();
            if(seat == 0 || res[seat-1] != p1.second){
             res.push_back(p1.second);
             p1.first--;
             seat++;
             if(p1.first > 0) pq.push(p1);
            }
            else{
                if(pq.empty()) return "";
                pair<int,char> p2 = pq.top();
                pq.pop();
                res.push_back(p2.second);
                p2.first--;
                seat++;
                if(p2.first > 0) pq.push(p2);
                pq.push(p1);
            }
        }
        if (res.size() != n) return "";
        return res;
    }
};