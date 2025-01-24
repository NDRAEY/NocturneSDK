#include "fstream"
#include "iostream"

extern "C" {
	void printf(const char* ch, ...);
}

using namespace std;

int main() {
	__cpp_init();


	std::fstream file("T:\\test.txt", std::ios::out);

	file.write("Test: AAA_AAA_AAA", 17);

	file.seekg(10, std::ios::beg);
	
	file.write("BBB", 3);
	
	file.seekg(14, std::ios::beg);
	
	file.write("CCC", 3);

	
	file.seekg(0, std::ios::beg);

	std::string content;
	content.resize(18);

	file.read(content.data(), 17);

	std::cout << "Content is: " << content << std::endl; 

	return 0;
}
