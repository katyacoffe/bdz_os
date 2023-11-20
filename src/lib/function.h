#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

// A Queue Node
struct Node
{
	// (x, y) represents matrix cell coordinates, and
	// `dist` represents their minimum distance from the source
	int x, y, dist;
};

// Below arrays detail all four possible movements from a cell
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };

bool isValid(std::vector<vector<int>> const &mat, vector<vector<bool>> &visited,
		int row, int col);

int findShortestPathLength(std::vector<vector<int>> const &mat, pair<int, int> &src,
					pair<int, int> &dest);
