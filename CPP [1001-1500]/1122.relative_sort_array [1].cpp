class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size(), n2=arr2.size();
        vector<int> ans;
        unordered_map<int,int> mp; //num in arr1 -> freq
        for(int i=0; i<n1; i++) //count freq of each element in arr1
            mp[arr1[i]]++;
        for(int i=0; i<n2; i++)
        {
            while(mp[arr2[i]]) //find arr2[i] in map
            {
                ans.push_back(arr2[i]); //add arr2[i] in ans freq num of times
                mp[arr2[i]]--;
            }
        }
        int index=ans.size();
        for(auto it: mp) //add the remaining elements of map into ans
            while(it.second > 0)
            {
                ans.push_back(it.first);
                it.second--;
            }
        sort(ans.begin()+index,ans.end()); //sort the elements not present in arr2
        return ans;
    }
};