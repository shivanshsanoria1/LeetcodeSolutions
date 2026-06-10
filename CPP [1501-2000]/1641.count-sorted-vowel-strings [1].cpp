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
            vector<int> vow2(5); //create a temp vowel vector for each iteration
            vow2[0]= sum; //0th element of temp vowel vector is prev sum
            for(int i=1; i<5; i++) //fill the temp vowel vector
            {
                vow2[i]= vow2[i-1] - vow[i-1];
                sum += vow2[i];
            }
            for(int i=0; i<5; i++) //update the original vowel vector with temp vowel vector
                vow[i]= vow2[i];
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