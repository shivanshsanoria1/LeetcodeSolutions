class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp; // group size -> {person id}
        for(int i=0; i<groupSizes.size(); i++)
            mp[groupSizes[i]].push_back(i);

        vector<vector<int>> ans;
        for(auto [groupSize, personIds]: mp)
        {
            vector<int> temp;
            for(int personId: personIds)
            {
                temp.push_back(personId);
                if(temp.size() == groupSize)
                {
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};