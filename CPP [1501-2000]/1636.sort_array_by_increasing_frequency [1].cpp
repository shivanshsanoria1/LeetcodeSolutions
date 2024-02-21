class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp; //num -> freq
        priority_queue<pair<int,int>> pq; //same as max heap , freq -> num
        for(int i=0; i<n; i++)
            mp[nums[i]]++;
        for(auto it: mp)
            pq.push({-it.second,it.first}); //freq is multiplied by -1 to use max heap as min heap
        while(!pq.empty())
        {
            pair<int,int> curr=pq.top();
            pq.pop();
            int freq= -curr.first; //make freq +ive
            while(freq--) //add num to ans freq number of times
                ans.push_back(curr.second);
        }
        return ans;
    }
};