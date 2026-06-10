class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<2)
            return n;
        vector<int> vec(n+1);
        vec[0]=0;
        vec[1]=1;
        int max_num=1;
        for(int i=2; i<n+1; i++)
        {
            if(i%2==0) //even index
                vec[i]=vec[i/2];
            else //odd index
                vec[i]=vec[i/2]+vec[i/2+1];
            max_num=max(max_num,vec[i]);
        }
        return max_num;
    }
};