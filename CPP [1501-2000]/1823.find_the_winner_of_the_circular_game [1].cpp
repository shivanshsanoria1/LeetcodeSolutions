class Solution {
public:
    int last;
    int findTheWinner(int n, int k) { // JOSEPHUS problem
        vector<int> vec(n);
        for(int i=0; i<n; i++) // array of persons
            vec[i]=i+1;
        solve(vec,k,0);
        return last;
    }
    
    void solve(vector<int> vec, int k, int index)
    {
        int len=vec.size();
        if(len==1)
        {
            last=vec[0];
            return;
        }
        index = (index + k-1) % len; // find the correct index corresponding to current index
        vec.erase(vec.begin() + index); // remove the correct index corresponding to current index
        solve(vec,k,index);
    }
};