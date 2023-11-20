#include "lib/function.h"

// Below arrays detail all four possible movements from a cell


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

	pair<int, int> src;
	pair<int, int> dest;
	cout << "Введите начальные координаты" << endl;
	cin >> src.first >> src.second;
	cout << "Введите конечные координаты" << endl;
	cin >> dest.first >> dest.second;
	int min_dist = findShortestPathLength(mat, src, dest);
	if (min_dist != -1)
	{
		cout << "Наиболее короткий путь "
				"имеет длину: " << min_dist << endl;
	}
	else {
		cout << "Путь не может быть найден при заданных параметрах" << endl;
		return main();
	}

	return 0;
}
