#include "BranchAndBound.h"
#include <fstream>

namespace BranchAndBound
{
	BranchAndBound::BranchAndBound(const std::string& path)
	{
        std::ifstream file(path);
        if (!file.is_open())
        {
            throw FileTsException("Branch And Bound Exception: File Open Error ");
        }

        file >> count;
        cost.set_size(count);

        for (int i = 0; i < count; ++i)
        {
            for (int j = 0; j < count; ++j)
            {
                file >> cost[i][j];
                if (cost[i][j] < 0)
                {
                    throw NegativeWeightException("Branch And Bound Exception: Bad Input Data Error");
                }
            }
        }

        visited.resize(count);
        solution.resize(count);
        tmp.resize(count);
        for (int i = 0; i < count; ++i)
        {
            visited[i] = false;
        }

        bestScore = 0;
        bestScore = std::numeric_limits<int>::max();
	}

	void BranchAndBound::search()
	{
        recursiveSearch(0, 0, 0);

        std::cout << "The best way: ";
        for (int i = 0; i < count; ++i)
        {
            std::cout << solution[i] + 1 << " -> ";
        }
        std::cout << solution[0] + 1 << "\nThe best score: " << bestScore;
	}

    void BranchAndBound::recursiveSearch(double current, double current_distance, int number)
    {
        if (bestScore <= current_distance)
        {
            return;
        }
        if (current == 0)
        {
            if (number == 0)
            {
                tmp[number] = current;
                for (int i = 1; i < count; ++i)
                {
                    if (!visited[i])
                    {
                        recursiveSearch(i, current_distance + cost[current][i], number + 1);
                    }
                }
            }
            if (number == count)
            {
                if (current_distance < bestScore)
                {
                    bestScore = current_distance;
                    for (int i = 0; i < count; ++i)
                    {
                        solution[i] = tmp[i];
                    }
                }
                return;
            }
        }
        else
        {
            visited[current] = true;
            tmp[number] = current;
            for (int i = 0; i < count; ++i)
            {
                if (!visited[i])
                {
                    recursiveSearch(i, current_distance + cost[current][i], number + 1);
                }
            }
            visited[current] = false;
        }
    }
}