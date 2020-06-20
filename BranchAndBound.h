#pragma once
#include <string>
#include "Matrix.h"
#include <vector>

namespace BranchAndBound
{
	class BranchAndBound
	{
		int count;
		double bestScore;

		std::vector<bool> visited;
		std::vector<int> solution;
		std::vector<int> tmp;

		Math::Matrix<double> cost;

		void recursiveSearch(double current, double current_distance, int number);
	public:
		explicit BranchAndBound(const std::string& path);
		~BranchAndBound() = default;

		BranchAndBound() = delete;
		BranchAndBound(const BranchAndBound& other) = delete;
		BranchAndBound(BranchAndBound&& other) = delete;

		BranchAndBound& operator = (const BranchAndBound& other) = delete;
		BranchAndBound& operator = (BranchAndBound&& other) = delete;

		void search();
	};
}
