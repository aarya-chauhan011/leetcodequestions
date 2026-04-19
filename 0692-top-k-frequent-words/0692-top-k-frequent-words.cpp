class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (int i = 0; i < words.size(); i++) {
            freq[words[i]]++;
        }
        struct comp {
            bool operator()(pair<string,int> &a, pair<string,int> &b) {
                if (a.second == b.second)
                    return a.first < b.first; 
                return a.second > b.second; 
            }
        };
        priority_queue<pair<string,int>, vector<pair<string,int>>, comp> pq;
        unordered_map<string,int>::iterator it;
        for (it = freq.begin(); it != freq.end(); it++) {
            pq.push({it->first, it->second});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
