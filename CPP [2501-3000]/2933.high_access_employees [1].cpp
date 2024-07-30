class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        // name -> {access_time}
        unordered_map<string, vector<int>> mp;
        
        for(vector<string>& access_time: access_times)
        {
            string name = access_time[0];
            string time = access_time[1];

            int hh = stoi(time.substr(0, 2));
            int mm = stoi(time.substr(2));
            int mins = 60*hh + mm;

            mp[name].push_back(mins);
        }

        vector<string> ans;
        for(auto& [name, times]: mp)
        {
            sort(times.begin(), times.end());

            for(int i=1; i<times.size()-1; i++)
                if(times[i+1] - times[i-1] < 60)
                {
                    ans.push_back(name);
                    break;
                }
        }

        return ans;
    }
};