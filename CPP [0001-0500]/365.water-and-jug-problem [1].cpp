class Solution {
public:
    int gcd(int a, int b)
    {
        while(a != b)
        {
            if(a >= b)
                a=a-b;
            else
                b=b-a;
        }
        return a;
    }
    
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) { //Math soln.
        if(targetCapacity > jug1Capacity + jug2Capacity) //targetCapacity cannot be greater than
            return false; //the sum of capacities of jug1 and jug2
        if(targetCapacity % gcd(jug1Capacity,jug2Capacity) == 0) //return true if targetCapacity
            return true; //is a multiple of gcd of jug1Capacity and jug2Capacity
        return false;
    }
};