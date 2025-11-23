class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp; //map of the form [num->freq]
        vector<vector<int>> freq_num; //vector of the form [freq->num]
        for(int i=0; i<nums.size(); i++) //add all elements and their freq in map
            mp[nums[i]]++;
        for(auto it: mp) //push the [freq,num] in vector
        {
            vector<int> temp;
            temp.push_back(it.second);
            temp.push_back(it.first);
            freq_num.push_back(temp);
        }
        sort(freq_num.begin(),freq_num.end()); //sort the vector according to freq
        for(int i=freq_num.size()-1; k>0 && i>=0; i--) //add k num of highest freq in ans
        {
            ans.push_back(freq_num[i][1]);
            k--;
        }
        return ans;
    }
};