class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        priority_queue<int> pq; // map-heap
        for(int i=0; i<26; i++)
            if(freq[i] > 0)
                pq.push(freq[i]);
        int count = 0;
        while(!pq.empty())
        {
            int freq = pq.top();
            pq.pop();
            // keep popping from heap, decrementing the freq and pushing into the heap 
            // until curr freq and heap's top freq are not equal 
            while(!pq.empty() && pq.top() == freq)
            {
                int freq2 = pq.top();
                pq.pop();
                count++;
                freq2--;
                if(freq2 > 0)
                    pq.push(freq2);
            }
        }
        return count;
    }
};