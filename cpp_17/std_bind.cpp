#include <functional>
#include <iostream>
#include <string>

class A
{
    public:
    void addAndPrint(int a, int b)
    {
        int sum = a + b;
        std::cout << "sum: " << sum << "\n";
    }

    void bindFunction(std::function<void(int, int)>& dest)
    {
        dest = std::bind(&A::addAndPrint, this, std::placeholders::_1, std::placeholders::_2);
    }
};

int main() {
	A test;
	std::function<void(int, int)> func4;
	test.bindFunction(func4);
	func4(100, 200);
}