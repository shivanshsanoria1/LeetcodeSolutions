class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp; //num -> freq
        for(int i=0; i<tasks.size(); i++)
            mp[tasks[i]]++;
        int ans=0;
        for(auto it: mp)
        {
            if(it.second == 1)
                return -1;
            if(it.second==2 || it.second==3)
                ans += 1;
            else
                ans += (it.second-1)/3 + 1;
        }
        return ans;
    }
};