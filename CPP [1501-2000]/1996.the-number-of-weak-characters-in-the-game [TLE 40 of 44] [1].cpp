class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) { //T.C.=O(n^2) , S.C.=O(1)
        int n=properties.size(), weak=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(properties[j][0] > properties[i][0] && properties[j][1] > properties[i][1]) //character properties[i] is weak
                {
                    weak++;
                    break;
                }
        return weak;
    }
};