class Solution {
public:
    // T.C.=O(n^3), S.C.=O(n)
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_set<string> triplets;

        int n=nums.size();
        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
                for(int k=j+1; k<n; k++)
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        string hash = to_string(nums[i]) + "#" + to_string(nums[j]) + "#" + to_string(nums[k]);
                        triplets.insert(hash);
                    }
        
        vector<vector<int>> ans;
        for(string triplet: triplets)
        {
            int idx1 = -1, idx2 = -1;
            for(int i=0; i<triplet.size(); i++)
            {
                if(triplet[i] != '#')
                    continue;

                if(idx1 == -1)
                    idx1 = i;
                else
                    idx2 = i;
            }

            int a = stoi(triplet.substr(0, idx1));
            int b = stoi(triplet.substr(idx1 + 1, idx2 - idx1));
            int c = stoi(triplet.substr(idx2 + 1));

            ans.push_back({a, b, c});
        }

        return ans;
    }
};