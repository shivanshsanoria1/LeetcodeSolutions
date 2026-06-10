class Solution {
private:
    double X0 = 0, Y0 = 0;
    double R = 0;

    // generates a random number in range [0, 1] (both inclusive)
    double getRandom01() {
        return ((double)rand()) / RAND_MAX;
    }

public:
    Solution(double radius, double x_center, double y_center) {
        this->X0 = x_center;
        this->Y0 = y_center;
        this->R = radius;

        // use the current time as seed for random generator 
        srand(time(0));
    }
    
    vector<double> randPoint() {
        // generate a random number in range [0, 2*PI] (both inclusive)
        double theta = 2 * M_PI * getRandom01();
        // generate a random number in range [0, R] (both inclusive)
        double r = this->R * sqrt(getRandom01());

        double x = this->X0 + r * cos(theta);
        double y = this->Y0 + r * sin(theta);

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */