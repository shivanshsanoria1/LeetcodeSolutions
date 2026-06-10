class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp; //num -> freq
        unordered_set<int> s;
        for(int i=0; i<n; i++) //add num and their freq in map
            mp[arr[i]]++;
        for(auto it: mp) //add all the freq to a set
            s.insert(it.second);
        return s.size()==mp.size() ? true : false;
    }
};