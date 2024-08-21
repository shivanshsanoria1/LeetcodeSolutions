class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        // num -> freq
        unordered_map<int, int> mp;
        for(int barcode: barcodes)
            mp[barcode]++;
        
        // max-heap; {freq, num}
        priority_queue<pair<int, int>> pq;
        for(auto [num, freq]: mp)
            pq.push({freq, num});
        
        vector<int> ans;
        while(pq.size() >= 2)
        {
            auto [freq1, num1] = pq.top();
            pq.pop();
            auto [freq2, num2] = pq.top();
            pq.pop();

            ans.push_back(num1);
            ans.push_back(num2);

            freq1--;
            freq2--;

            if(freq1 > 0)
                pq.push({freq1, num1});
            if(freq2 > 0)
                pq.push({freq2, num2});
        }

        if(pq.size() == 1)
            ans.push_back(pq.top().second);

        return ans;
    }
};