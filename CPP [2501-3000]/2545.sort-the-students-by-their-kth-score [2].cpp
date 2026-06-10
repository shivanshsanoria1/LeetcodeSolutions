class Solution {
public:
    // T.C.=O(m*log(m)), S.C.=O(1)
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [k](vector<int>& a, vector<int>& b){
            return a[k] > b[k];
        });

        return score;
    }
};