class Solution {
public:
    int arrangeCoins(int n) { //math soln.
        long int num=n;                     //k(k+1)/2 <= n
        return (floor(sqrt(8*num+1))-1)/2;  //k(k+1) <= 2n 
    }                                       //(k+1/2)^2-1/4 <= 2n
};                                          //(k+1/2)^2 <= 2n+1/4
                                            //k+1/2 <= sqrt(2n+1/4)
                                            //k+1/2<=sqrt((8n+1)/4)
                                            //k+1/2<=(sqrt(8n+1))/2
                                            //for max value of k: k+1/2=floor(sqrt(8n+1))/2
                                            //k=(floor(sqrt(8n+1))-1)/2