int Solution::solve(vector<int> &arr) {
    unordered_map<int,int> mp; //num -> freq
    for(int i=0; i<arr.size(); i++)
        mp[arr[i]]++;
    int c=0;
    for(auto it: mp)
        c+= (it.second)/2;
    return c;
}
