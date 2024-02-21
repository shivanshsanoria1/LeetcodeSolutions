class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b)
    {
        return a.second==b.second ? a.first>b.first : a.second<b.second;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp; //num -> freq
        vector<pair<int,int>> vec; //num -> freq
        for(int i=0; i<n; i++) //add num and its freq in map
            mp[nums[i]]++;
        for(auto it: mp) //add num and its freq in vec
            vec.push_back(it);
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0; i<vec.size(); i++)
        {
            int f=vec[i].second; //freq of num
            while(f--) //add num to ans freq number of times
                ans.push_back(vec[i].first);
        }
        return ans;
    }
};