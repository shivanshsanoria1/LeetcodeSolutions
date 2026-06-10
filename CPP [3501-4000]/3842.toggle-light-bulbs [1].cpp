class Solution {
public:
    // T.C.=O(n + 100), S.C.=O(100)
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> freq(101, 0);
        for(int bulb: bulbs)
            freq[bulb]++;

        vector<int> ans;
        for(int i = freq.size()-1; i>=0; i--)
            if(freq[i] % 2 == 1)
                ans.push_back(i);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// odd freq: finally ON
// even freq: finally OFF