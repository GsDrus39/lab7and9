#include <cmath>

class Cube
{
private:
    double pr_side_len;
public:
    Cube(double side_len)
    {
        pr_side_len = side_len;
    }

    double get_diagonal()
    {
        double a = pow((pr_side_len * pr_side_len * 2), 0.5);
        return pow((a * a + pr_side_len * pr_side_len), 0.5);
    }
};