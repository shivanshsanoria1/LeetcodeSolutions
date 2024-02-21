class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // time needed to collect metal, paper, glass garbage respectively
        int timeM = 0, timeP = 0, timeG = 0;
        // last index of the house that has metal, paper, glass garbage respectively
        int idxM = -1, idxP = -1, idxG = -1;
        
        for(int i=garbage.size()-1; i>=0; i--)
            for(char ch: garbage[i])
            {
                if(ch == 'M')
                {
                    timeM++;
                    if(idxM == -1)
                        idxM = i;
                }
                else if(ch == 'P')
                {
                    timeP++;
                    if(idxP == -1)
                        idxP = i;
                }
                else if(ch == 'G')
                {
                    timeG++;
                    if(idxG == -1)
                        idxG = i;
                }
            }

        for(int i=0; i<idxM; i++)
            timeM += travel[i];
        for(int i=0; i<idxP; i++)
            timeP += travel[i];
        for(int i=0; i<idxG; i++)
            timeG += travel[i];

        return timeM + timeP + timeG;
    }
};
// T.C.=O(n*k), S.C.=O(1), k: max length of garbage[i]