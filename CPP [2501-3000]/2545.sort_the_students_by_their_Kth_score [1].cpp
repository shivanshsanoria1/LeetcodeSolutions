class Solution {
private:
    static int static_k;

    static bool cmp(vector<int>& a, vector<int>& b){
        return a[static_k] > b[static_k];
    }

public:
    // T.C.=O(m*log(m)), S.C.=O(1)
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        static_k = k;
        sort(score.begin(), score.end(), cmp);

        return score;
    }
};
int Solution::static_k = -1;

/*
# the variables declared as static are initialized only once 
  as they are allocated space in separate static storage so, 
  the static variables in a class are shared by the objects
# there can not be multiple copies of the same static variables for different objects
# because of this reason static variables can not be initialized using constructors
# a static variable inside a class should be initialized explicitly by the user 
  using the class name and scope resolution operator outside the class
*/