class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size(), ans=0;
        map<pair<int,int>,int> mp;
        for(int i=0; i<n; i++)
        {
            if(dominoes[i][0] > dominoes[i][1]) //converts pairs (b,a) into (a,b) where a<b
                swap(dominoes[i][0],dominoes[i][1]);
            mp[make_pair(dominoes[i][0],dominoes[i][1])]++;
        }
        for(auto it: mp)
            if(it.second > 1)
                ans+=((it.second-1)*it.second)/2;
        return ans;
    }
};