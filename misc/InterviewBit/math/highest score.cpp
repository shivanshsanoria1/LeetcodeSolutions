int Solution::highestScore(vector<vector<string> > &A) {
    unordered_map<string,pair<int,int>> mp; //name -> {total marks,freq}
    for(auto it: A)
    {
        mp[it[0]].first += stoi(it[1]);
        mp[it[0]].second++;
    }
    int ans=0;
    for(auto it: mp)
        ans= max(ans, it.second.first/it.second.second);
    return ans;
}
