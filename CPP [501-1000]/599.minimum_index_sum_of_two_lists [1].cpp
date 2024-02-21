class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) { //T.C.=O(m+n) , S.C.=O(m) , m and n are size of list1 and list2
        vector<string> ans;
        unordered_map<string,int> mp; //string -> index
        for(int i=0; i<list1.size(); i++) //add string and their index from list1 into map
            mp[list1[i]] = i;
        int min_index_sum= INT_MAX;
        for(int i=0; i<list2.size(); i++)
            if(mp.find(list2[i]) != mp.end()) //string list2[i] found in map
            {
                if(i + mp[list2[i]] < min_index_sum) //new min index sum found
                {
                    min_index_sum = i + mp[list2[i]]; //update min index sum
                    ans.clear(); //clear the ans vector
                    ans.push_back(list2[i]); //push curr string in ans vector
                }
                else if(i + mp[list2[i]] == min_index_sum)
                    ans.push_back(list2[i]); //push curr string in ans vector
            }
        return ans;
    }
};