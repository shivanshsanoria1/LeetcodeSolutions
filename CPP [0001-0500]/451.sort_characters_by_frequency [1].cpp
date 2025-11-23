class Solution {
public:
    // T.C.=O(n), S.C.=O(62)
    string frequencySort(string s) {
        unordered_map<char, int> mp; // char -> freq
        priority_queue<pair<int, char>> pq; // max-heap
        for(char ch: s)
            mp[ch]++;
        for(auto [ch, freq]: mp)
            pq.push({freq, ch});
        
        string ans = "";
        while(!pq.empty())
        {
            auto [freq, ch] = pq.top();
            pq.pop();
            while(freq--)
                ans += ch;
        }
        return ans;
    }
};