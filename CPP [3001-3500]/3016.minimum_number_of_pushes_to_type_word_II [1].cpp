class Solution {
public:
    // T.C.=O(n), S.C.=O(26)
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char ch: word)
            freq[ch - 'a']++;
        
        // max-heap, {freq, char}
        priority_queue<pair<int, char>> pq;
        for(int i=0; i<26; i++)
            if(freq[i] > 0)
                pq.push({freq[i], i + 'a'});
        
        // index i: (i+2)th button
        // buttonPushes[i]: num of chars mapped to (i+2)th button
        vector<int> buttonPushes(8, 0);
        int i = 0;
        int totalPushes = 0;
        while(!pq.empty())
        {
            int freq = pq.top().first;
            pq.pop();
            buttonPushes[i]++;
            totalPushes += freq * buttonPushes[i];
            i = (i+1) % 8;
        }
        return totalPushes;
    }
};