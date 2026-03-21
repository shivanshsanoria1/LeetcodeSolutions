class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int fuelUsed = 0;
        while(mainTank >= 5)
        {
            mainTank -= 5;
            fuelUsed += 5;
            if(additionalTank >= 1)
            {
                additionalTank--;
                mainTank++;
            }
        }
        return (fuelUsed + mainTank) * 10;
    }
};