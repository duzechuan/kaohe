#include <iostream>
#include <cmath>
using namespace std;
class Vector {
private:
    double x;
    double y;

public:
    // 构造函数
    Vector(double xVal, double yVal) : x(xVal), y(yVal) {}

    // 向量相加方法
    Vector add(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }

    // 打印向量分量方法
    void print() const {
        std::cout << "向量之和: x=" << x << ", y=" << y << "" << std::endl;
    }

    // 求取并打印向量模长的方法
    void dir() const {
        double magnitude = std::sqrt(x * x + y * y);
        std::cout << "向量的模长为: " << magnitude << std::endl;
    }
};
int main() {
    double v1x, v1y, v2x, v2y;
    cin >> v1x >> v1y >> v2x >> v2y;
    Vector v1(v1x, v1y);
    Vector v2(v2x, v2y);
    // 向量相加并打印结果向量的分量和模长
    Vector sum = v1.add(v2);
    sum.print();
    sum.dir();

    return 0;
}