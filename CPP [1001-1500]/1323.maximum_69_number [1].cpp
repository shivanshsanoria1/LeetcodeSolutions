class Solution {
public:
    int maximum69Number (int num) {
        int n=num;
        vector<int> vec;
        while(n>0) //push all the digits from LSB to MSB in a vector
        {
            vec.push_back(n%10);
            n/=10;
        }
        for(int i=vec.size()-1; i>=0; i--) //change the 1st 6 to 9 starting from MSB to LSB
        {
            if(vec[i]==6)
            {
                vec[i]=9;
                break;
            }
        }
        int ans=0, mul=1;
        for(int i=0; i<vec.size(); i++) //iterate from LSB to MSB to form the ans
        {
            ans+=vec[i]*mul;
            mul*=10;
        }
        return ans;
    }
};