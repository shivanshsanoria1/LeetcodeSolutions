class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0, c10=0, c20=0; //store count of 5,10,20 bills
        for(int i=0; i<bills.size(); i++)
        {
            if(bills[i]==20) //curr bill is of 20
            {
                if(c10>=1 && c5>=1) //return 1 bill of 10 and 1 bill of 5 (if possible)
                {
                    c20++;
                    c10--;
                    c5--;
                }
                else if(c5>=3) //return 3 bills of 5 (if possible)
                {
                    c20++;
                    c5-=3;
                }
                else
                    return false;
            }
            else if(bills[i]==10) //curr bill is of 10
            {
                if(c5>=1) //return 1 bill of 5 (if possible)
                {
                    c10++;
                    c5--;
                }
                else
                    return false;
            }
            else //curr bill is of 5
                c5++;
        }
        return true;
    }
};