class Solution {
public:
    int countSetBits(int n)
    {
        int c=0;
        while(n)
        {
            if((n & 1) == 1)
                c++;
            n=n>>1;
        }
        return c;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        sort(arr.begin(),arr.end());
        map<int, vector<int>> mp; //set bits count -> vector of num
        for(int i=0; i<arr.size(); i++)
            mp[countSetBits(arr[i])].push_back(arr[i]);
        for(auto it: mp)
            for(auto it2: it.second)
                ans.push_back(it2);
        return ans;
    }
};