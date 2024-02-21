class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> digs(10,0); //to store freq of digits of num n
        while(n > 0)
        {
            digs[n%10]++;
            n/=10;
        }
        for(int i=0; i<31; i++)
        {
            vector<int> pows(10,0); //to store freq of digits of powers of 2
            int p=1<<i; //generates powers of 2
            while(p > 0)
            {
                pows[p%10]++;
                p/=10;
            }
            int count=0;
            for(int j=0; j<10; j++)
            {
                if(digs[j] == pows[j])
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