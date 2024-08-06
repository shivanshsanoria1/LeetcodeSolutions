class Solution {
public:
    // T.C.=O(n + 26*log(26)), S.C.=O(26)
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char ch: word)
            freq[ch - 'a']++;
        
        // max-heap; {freq, char}
        priority_queue<pair<int, char>> pq;
        for(int i=0; i<26; i++)
            if(freq[i] > 0)
                pq.push({freq[i], i + 'a'});
        
        int presses = 0;
        // index of the key being pressed, 
        // varies in range [0,7] in a circular manner
        int idx = 0;
        while(!pq.empty())
        {
            auto [freq, ch] = pq.top();
            pq.pop();

            presses += freq * (idx/8 + 1);
            idx++;
        }

        return presses;
    }
};