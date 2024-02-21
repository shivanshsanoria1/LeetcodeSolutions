class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        if(n==0) //return empty vector
            return ans;
        set<int> s(arr.begin(),arr.end()); //add elements of arr into set s
        unordered_map<int,int> mp;
        int rank=1;
        for(auto it: s) //add elements of set and their ranks into map 
            mp[it]=rank++;
        for(int i=0; i<n; i++) //find arr[i] in map and add its rank in ans
            ans[i]=mp[arr[i]];
        return ans;
    }
};