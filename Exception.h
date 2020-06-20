#pragma once
#include <exception>
#include <string>

namespace BranchAndBound
{
	class BranchAndBoundException : std::exception
	{
		std::string error;
	public:
		explicit BranchAndBoundException(const std::string& str) noexcept : error(str) {};
		const char* what() const noexcept override
		{
			return error.c_str();
		}
	};

	class FileTsException : BranchAndBoundException
	{
	public:
		explicit FileTsException(const std::string& str) noexcept : BranchAndBoundException(str) {};
	};

	class NegativeWeightException : BranchAndBoundException
	{
	public:
		explicit NegativeWeightException(const std::string& str) noexcept : BranchAndBoundException(str) {};
	};

	class MatrixIndexBbException : BranchAndBoundException
	{
	public:
		explicit MatrixIndexBbException(const std::string& str) noexcept : BranchAndBoundException(str) {};
	};
}