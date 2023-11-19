#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
#include "function.h"
using namespace std;

bool isValid(vector<vector<int>> const &mat, vector<vector<bool>> &visited,
		int row, int col) {
	return (row >= 0 && row < mat.size()) && (col >= 0 && col < mat[0].size())
		&& mat[row][col] && !visited[row][col];
}
