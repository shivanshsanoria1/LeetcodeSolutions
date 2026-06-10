class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        double remainingIncome = income;
        for(int i=0; i<brackets.size(); i++)
        {
            int upperLimit = i-1 >= 0 ? brackets[i][0] - brackets[i-1][0] : brackets[i][0];
            double percent = brackets[i][1];
            if(remainingIncome > upperLimit)
            {
                remainingIncome -= upperLimit;
                tax += upperLimit * percent / 100;
            }
            else
            {
                tax += remainingIncome * percent / 100;
                break;
            }
        }
        return tax;
    }
};