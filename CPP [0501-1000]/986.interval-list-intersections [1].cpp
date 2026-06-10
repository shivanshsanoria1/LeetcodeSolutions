class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& list1, vector<vector<int>>& list2) {
        int n1=list1.size(), n2=list2.size();
        vector<vector<int>> ans;
        int i=0, j=0;
        while(i < n1 && j < n2)
        {
            int s1 = list1[i][0], e1 = list1[i][1]; // ith interval start and end in list1
            int s2 = list2[j][0], e2 = list2[j][1]; // jth interval start and end in list2
            if(s2 > e1) // discard (s1, e1)
                i++;
            else if(s1 > e2) // discard (s2, e2)
                j++;
            else if(s1 <= s2 && s2 <= e1) // s2 lies in (s1, e1)
            {
                if(e2 <= e1) // discard (s2, e2)
                {
                    ans.push_back({s2, e2});
                    j++;
                }
                else // discard (s1, e1)
                {
                    ans.push_back({s2, e1});
                    i++;
                }
            }
            else if(s2 <= s1 && s1 <= e2) // s1 lies in (s2, e2)
            {
                if(e1 <= e2) // discard (s1, e1)
                {
                    ans.push_back({s1, e1});
                    i++;
                }
                else // discard (s2, e2)
                {
                    ans.push_back({s1, e2});
                    j++;
                }
            }
        }
        return ans;
    }
};