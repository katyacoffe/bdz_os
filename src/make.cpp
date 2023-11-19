#include "function.h"
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

int main()
{
	vector<vector<int>> mat =
	{
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
	};

	pair<int, int> src = make_pair(0, 0);
	pair<int, int> dest = make_pair(4, 3);

	int min_dist = findShortestPathLength(mat, src, dest);
	if (min_dist != -1)
	{
		cout << "The shortest path from source to destination "
				"has length " << min_dist;
	}
	else {
		cout << "Destination cannot be reached from a given source";
	}

	return 0;
}
