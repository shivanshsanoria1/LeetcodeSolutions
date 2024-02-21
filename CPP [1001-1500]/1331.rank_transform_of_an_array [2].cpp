class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        if(n==0) //return empty vector
            return ans;
        vector<int> vec=arr; //copy the array arr into vec
        sort(vec.begin(),vec.end()); //sort vec
        unordered_map<int,int> mp;
        int rank=1;
        for(int i=0; i<n; i++)
        {
            if(mp.find(vec[i]) != mp.end()) //vec[i] present in map
                continue;
            mp[vec[i]]=rank; //add vec[i] and its rank in map
            rank++;
        }
        for(int i=0; i<n; i++) //find arr[i] in map and add its rank in ans
            ans[i]=mp[arr[i]];
        return ans;
    }
};