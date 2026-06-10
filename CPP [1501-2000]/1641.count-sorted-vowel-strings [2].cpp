class Solution {
public:
    int countVowelStrings(int n) { //T.C.=O(n) , S.C.=(1)
        if(n==1)
            return 5;
        vector<int> vow= {5,4,3,2,1}; //a,e,i,o,u values for n=2
        int sum=15;
        n=n-2;
        while(n--)
        {
            int temp= vow[0]; //take a copy of vow[0]
            vow[0]= sum; //update vow[0] with prev sum
            for(int i=1; i<5; i++)
            {
                int temp2= vow[i]; //take a copy of vow[i]
                vow[i]= vow[i-1]-temp; //update vow[i]
                temp= temp2; //update temp with old vow[i]
                sum += vow[i]; //add new vow[i] to sum
            }
        }
        return sum;
    }
};
// value of n |  a  |  e  |  i  |  o  |  u  |  sum
//          1 |  1  |  1  |  1  |  1  |  1  |   5
//          2 |  5  |  4  |  3  |  2  |  1  |  15
//          3 | 15  | 10  |  6  |  3  |  1  |  35
//          4 | 35  | 20  | 10  |  4  |  1  |  70
//          5 | 70  | 35  | 15  |  5  |  1  | 126