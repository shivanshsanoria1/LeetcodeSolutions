class Solution {
public:
    static bool cmp(vector<int>&v1, vector<int>&v2) //for each pair (x,y) sort in increasing order of x values. 
    {                                               //if x values are equal then sort in decreasing order of y values
        return v1[0]==v2[0] ? v1[1]>v2[1] : v1[0]<v2[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) { //T.C.=O(nlogn) , S.C.=O(1)
        int n=properties.size(), weak=0;
        //sorts in increasing order of attacks and if attacks are equal then sorts in decreasing order of defences
        sort(properties.begin(),properties.end(),cmp);
        int max_def= properties[n-1][1]; //assume defence of last pair as max defence
        for(int i=n-2; i>=0; i--) //iterate array in reverse staring from 2nd last pair
        {
            int curr_def= properties[i][1];
            if(curr_def < max_def) //weak pair found
                weak++;
            else //update max defence
                max_def= curr_def;
        }
        return weak;
    }
};