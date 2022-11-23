#include <cmath>

class Cube
{
private:
    double m_side_len;
public:
    Cube(double side_len)
    {
        m_side_len = side_len;
    }

    double get_diagonal()
    {
        double a = pow((m_side_len * m_side_len * 2), 0.5);
        return pow((a * a + m_side_len * m_side_len), 0.5);
    }
};
