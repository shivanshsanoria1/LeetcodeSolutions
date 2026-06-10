class Solution {
public:
    double average(vector<int>& salary) {
        int maxSalary = 0, minSalary = INT_MAX;
        int sum = 0;
        for(int sal: salary)
        {
            maxSalary = max(maxSalary, sal);
            minSalary = min(minSalary, sal);
            sum += sal;
        }
        return (double)(sum - maxSalary - minSalary)/(salary.size()-2);
    }
};