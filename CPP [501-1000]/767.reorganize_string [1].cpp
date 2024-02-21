class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        // find freq of each char
        for(char ch: s)
            freq[ch - 'a']++;
        priority_queue<pair<int, char>> pq; // max-heap
        // push each {freq, char} in heap
        for(int i=0; i<26; i++)
            if(freq[i] > 0)
                pq.push({freq[i], i + 97});
        string ans = "";
        while(!pq.empty())
        {
            // curr freq and char
            auto [freq, ch] = pq.top();
            pq.pop();
            // ans string is empty or last char of ans is diff from curr char
            if(ans.length() == 0 || ans.back() != ch)
            {
                ans += ch;
                // decrement the freq and push the {freq, char} in heap (if non-zero)
                if(freq - 1 > 0)
                    pq.push({freq - 1, ch});
            }
            // last char of ans matches with the curr char, so take out 
            // another {freq, char} from heap (if possible)
            else if(!pq.empty())
            {
                auto [freq2, ch2] = pq.top();
                pq.pop();
                ans += ch2;
                // decrement the 2nd freq and push the 2nd {freq, char} in heap (if non-zero)
                if(freq2 - 1 > 0)
                    pq.push({freq2 - 1, ch2});
                // push the 1st {freq, char} in heap
                pq.push({freq, ch});
            }
            // last char of ans matches with the curr char and heap is empty so ans is not possible
            else
                return "";
        }
        return ans;
    }
};