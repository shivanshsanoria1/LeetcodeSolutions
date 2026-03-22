class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) { //T.C.=O(k*logN), S.C.=O(n)
        unordered_map<int,int> mp; // num -> freq
        priority_queue<pair<int,int>> pq; // max heap
        vector<int> ans;
        for(auto num: nums) // add nums and their freq in map
            mp[num]++;
        for(auto it: mp) // build a max heap according to the freq of each pair in map
            pq.push({it.second,it.first});
        while(k--) // pop out k pairs from the max heap
        {
            int top_num = pq.top().second;
            ans.push_back(top_num);
            pq.pop();
        }
        return ans;
    }
};