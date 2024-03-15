class Solution {
public:
    // T.C.=O(n1*logn1 + n2logn2), S.C.=O(1)
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int n1=players.size(), n2=trainers.size();
        int i = 0, j = 0;
        int count = 0;
        while(i < n1 && j < n2)
        {
            if(players[i] <= trainers[j])
            {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};