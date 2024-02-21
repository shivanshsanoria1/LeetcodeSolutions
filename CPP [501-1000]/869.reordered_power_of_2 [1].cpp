class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<vector<int>> vec(31,vector<int> (10,0)); //to store freq of digits of powers of 2 from 2^0 to 2^30
        for(int i=0; i<31; i++)
        {
            int p=pow(2,i);
            while(p > 0)
            {
                vec[i][p%10]++;
                p/=10;
            }
        }
        vector<int> digs(10,0); //to store freq of digits of num n
        while(n > 0)
        {
            digs[n%10]++;
            n/=10;
        }
        for(int i=0; i<31; i++)
        {
            int count=0;
            for(int j=0; j<10; j++)
            {
                if(vec[i][j] == digs[j])
                    count++;
                else
                    break;
            }
            if(count==10)
                return true;
        }
        return false;
    }
};