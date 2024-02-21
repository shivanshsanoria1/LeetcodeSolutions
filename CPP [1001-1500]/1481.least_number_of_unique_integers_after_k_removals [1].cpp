class Solution {
private:
    typedef pair<int, int> PI;

public:
    // T.C.=O(n*logn), S.C.=O(n)
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp; // num -> freq
        for(int num: arr)
            mp[num]++;

        // min-heap {freq, num}
        priority_queue<PI, vector<PI>, greater<PI>> pq;
        for(auto [num, freq]: mp)
            pq.push({freq, num});
            
        while(k--)
        {
            auto [freq, num] = pq.top();
            pq.pop();
            freq--;
            if(freq > 0)
                pq.push({freq, num});
        }
        return pq.size();
    }
};