class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        if(n==0) //return empty vector
            return ans;
        map<int,int> mp;
        for(int i=0; i<n; i++) //add elements from array to map
            mp[arr[i]]=0;
        int rank=1;
        for(auto it=mp.begin(); it!=mp.end(); it++) //give ranks to the elements in map
        {
            it->second=rank;
            rank++;
        }
        for(int i=0; i<n; i++) //add ranks of elements of array in ans 
            ans[i]=mp[arr[i]];
        return ans;
    }
};