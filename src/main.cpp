#include "BranchAndBound.h"
#include <fstream>
#include <ctime>

int main(int argc, const char* argv[]) 
{
	try
	{
		unsigned int start = clock();
		BranchAndBound::BranchAndBound test("../tests/test.txt");
		test.search();
		unsigned int end = clock();
		std::cout << std::endl << "Working time: " << (double)(end - start) / 1000;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}