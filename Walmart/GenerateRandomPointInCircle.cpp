#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double radius, x_center, y_center;
    Solution(double _radius, double _x_center, double _y_center) {
        radius = _radius;
        x_center = _x_center;
        y_center = _y_center;
    }
    
    vector<double> randPoint() {
        double theta = ((double) rand()/RAND_MAX)*2*M_PI;
        double r = sqrt((double) rand()/RAND_MAX) * radius;
        double x = r * cos(theta) + x_center;
        double y = r * sin(theta) + y_center;
        return {x, y};
    }
};

int main() {
    return 0;
}