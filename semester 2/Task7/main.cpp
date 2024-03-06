#include <Vector.hpp>
int main()
{  
	my::Vector<bool> vec(1);
	vec.push_back(true);
	vec.push_back(false);
	vec.push_back(true);
	vec.push_back(true);
	vec.push_back(false);
	vec.push_back(true);
	vec.push_back(true);
	vec.push_back(false);
	vec.push_back(false);
	vec.push_back(true);
	vec.push_back(true);
	vec.push_back(true);
	vec.push_back(true);
	vec.push_back(false);
	vec.push_back(true);
	vec.push_back(true);
	vec.push_back(false);

	vec.insert(8, true);
	std::cout << "Size: " << vec.size() << std::endl;
	for (int i = 0; i < vec.size(); i++)
		std::cout << (i) << ") " << vec[i] << std::endl;
	std::cout << std::endl;

	vec.erase(8);
	std::cout << "Size: " << vec.size() << std::endl;
	for (int i = 0; i < vec.size(); i++)
		std::cout << (i) << ") " << vec[i] << std::endl;
	
}