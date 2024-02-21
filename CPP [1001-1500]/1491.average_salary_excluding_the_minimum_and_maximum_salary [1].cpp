class Solution {
public:
    double average(vector<int>& salary) {
        int maxSalary = 0, minSalary = INT_MAX;
        for(int sal: salary)
        {
            maxSalary = max(maxSalary, sal);
            minSalary = min(minSalary, sal);
        }
        int sum = 0, count = 0;
        for(int sal: salary)
            if(sal > minSalary && sal < maxSalary)
            {
                sum += sal;
                count++;
            }
        return (double)sum/count;
    }
};