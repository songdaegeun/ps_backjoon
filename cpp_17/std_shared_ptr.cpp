#include <iostream>
#include <memory>

int main() {
	// std::shared_ptr<std::array<int,3>> ptr0 = std::make_shared<std::array<int,3>>();
	std::shared_ptr<int[]> ptr0(new int[3]);
	std::shared_ptr<int> ptr1(new int(5));
	
	// (*ptr0)[0] = 1;
	// (*ptr0)[1] = 2;
	// std::cout << (*ptr0)[0] << ' ' << (*ptr0)[1] << std::endl;
	ptr0[0] = 3;
	ptr0[1] = 4;
	std::cout << ptr0[0] << ' ' << ptr0[1] << std::endl;

	*ptr1 = 10;
	std::cout << ptr1.use_count() << std::endl;
	auto ptr2 = ptr1;
	std::cout << ptr1.use_count() << std::endl;
	auto ptr3(ptr1);
	ptr3.reset();
	std::cout << ptr1.use_count() << ' ' << ptr2.use_count() << ' ' << ptr3.use_count() << std::endl;
	std::cout << *ptr1 << std::endl;
}