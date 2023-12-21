#include <functional>
#include <iostream>
#include <string>

class A {
	int c;	

	public:
	A(int c) : c(c) {}
	int some_func() {
	std::cout << "비상수 함수: " << ++c << std::endl;
	return c;
	}

	int some_const_function() const {
	std::cout << "상수 함수: " << c << std::endl;
	return c;
	}
};

class B {
public:
	void operator()(char c) { std::cout << "Func2 호출! " << c << std::endl; }
};

int main() {
	std::function<void(char)> f1 = B();
	std::function<int(A&)> f2 = &A::some_func;
	std::function<int(const A&)> f3 = &A::some_const_function;
	
	A a(5);

	f1('c');
	f2(a);
	f3(a);
  
}