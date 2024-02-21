class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp; //num -> freq
        int max_num=INT_MIN;
        for(int i=0; i<arr.size(); i++)
            mp[arr[i]]++;
        for(auto it: mp)
            if(it.first == it.second) //num is equal to its freq (lucky num found)
                max_num= max(max_num,it.first); //max lucky num
        return max_num==INT_MIN ? -1 : max_num;
    }
};