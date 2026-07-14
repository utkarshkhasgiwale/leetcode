class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) const {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> f;

        for (int i = 0; i < n; i++)
            f[words[i]]++;

        for (auto x : f) {
            string OneWord = x.first;
            int freq = x.second;

            pair<int, string> curr = {freq, OneWord};

            if (pq.size() < k) {
                pq.push(curr);
            } else {
                if (curr.first > pq.top().first ||
                    (curr.first == pq.top().first &&
                     curr.second < pq.top().second)) {
                    pq.pop();
                    pq.push(curr);
                }
            }
        }
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};