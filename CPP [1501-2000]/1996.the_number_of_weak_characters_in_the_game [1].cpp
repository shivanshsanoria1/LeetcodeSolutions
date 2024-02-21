class Solution {
public:
    static bool cmp(vector<int>&v1, vector<int>&v2) //for each pair (x,y) sort in increasing order of x values. 
    {                                               //if x values are equal then sort in decreasing order of y values
        return v1[0]==v2[0] ? v1[1]>v2[1] : v1[0]<v2[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) { //T.C.=O(nlogn) , S.C.=O(n)
        int weak=0;
        //sorts in increasing order of attacks and if attacks are equal then sorts in decreasing order of defences
        sort(properties.begin(),properties.end(),cmp);
        stack<pair<int,int>> st;
        for(auto it: properties)
        {
            while(!st.empty() && it[1] > st.top().second) //keep popping pairs while curr defence > stack top defence
            {//(no need to check for attacks since we have sorted in increasing order of attacks), ie, keep popping the weak pairs
                weak++;
                st.pop();
            }
            st.push({it[0],it[1]}); //push the curr pair in stack
        }
        return weak;
    }
};