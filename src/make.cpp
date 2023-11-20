#include "lib/function.h"


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
