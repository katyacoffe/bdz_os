#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <unistd.h>

using namespace std;

// A Queue Node
struct Node
{
	// (x, y) represents matrix cell coordinates, and
	// `dist` represents their minimum distance from the source
	int x, y, dist;
};

bool isValid(std::vector<vector<int>> const &mat, vector<vector<bool>> &visited,
		int row, int col);

int findShortestPathLength(std::vector<vector<int>> const &mat, pair<int, int> &src,
					pair<int, int> &dest);

void monitoring();
