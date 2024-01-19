#include <iostream>

unsigned short static GetVolumeSquare(unsigned short side) {
	unsigned short volume = side * side * side;
	return volume;
}

int main() {
	unsigned short side;

	std::cout << "Enter the side of the square: \n";
	std::cin >> side;
	
	unsigned short volume = GetVolumeSquare(side);
	std::cout << volume << "\n";
	return 0;
}
