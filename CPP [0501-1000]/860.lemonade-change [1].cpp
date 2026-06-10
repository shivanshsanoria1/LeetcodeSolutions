class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Greedy
    bool lemonadeChange(vector<int>& bills) {
        // count of 5, 10, 20 bills
        int c5 = 0, c10 = 0, c20 = 0; 

        for(int bill: bills)
        {
            if(bill == 20)
            {
                // return 1 bill of 10 and 1 bill of 5 (if possible)
                if(c10 >= 1 && c5 >= 1) 
                {
                    c20++;
                    c10--;
                    c5--;
                }
                // return 3 bills of 5 (if possible)
                else if(c5 >= 3) 
                {
                    c20++;
                    c5 -= 3;
                }
                // cannot return the change 
                else
                    return false;
            }
            else if(bill == 10) 
            {
                // return 1 bill of 5 (if possible)
                if(c5 >= 1) 
                {
                    c10++;
                    c5--;
                }
                // cannot return the change 
                else
                    return false;
            }
            else // bill == 5
                c5++;
        }

        return true;
    }
};