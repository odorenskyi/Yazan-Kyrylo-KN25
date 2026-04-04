#include <cmath>

using namespace std;



double s_calculation(double x, double y, double z) {
    return M_PI * x + pow(exp(1.0), abs(y)) - sqrt(abs(pow(z, 2) - y));
}
