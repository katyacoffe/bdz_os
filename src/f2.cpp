#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
#include "function.h"
using namespace std;

int findShortestPathLength(vector<vector<int>> const &mat, pair<int, int> &src,
					pair<int, int> &dest)
{
	// base case: invalid input
	if (mat.size() == 0 || mat[src.first][src.second] == 0 ||
			mat[dest.first][dest.second] == 0) {
		return -1;
	}

	// `M × N` matrix
	int M = mat.size();
	int N = mat[0].size();

	// construct a `M × N` matrix to keep track of visited cells
	vector<vector<bool>> visited;
	visited.resize(M, vector<bool>(N));

	// create an empty queue
	queue<Node> q;

	// get source cell (i, j)
	int i = src.first;
	int j = src.second;

	// mark the source cell as visited and enqueue the source node
	visited[i][j] = true;
	q.push({i, j, 0});

	// stores length of the longest path from source to destination
	int min_dist = INT_MAX;

	// loop till queue is empty
	while (!q.empty())
	{
		// dequeue front node and process it
		Node node = q.front();
		q.pop();

		// (i, j) represents a current cell, and `dist` stores its
		// minimum distance from the source
		int i = node.x, j = node.y, dist = node.dist;

		// if the destination is found, update `min_dist` and stop
		if (i == dest.first && j == dest.second)
		{
			min_dist = dist;
			break;
		}

		// check for all four possible movements from the current cell
		// and enqueue each valid movement
		for (int k = 0; k < 4; k++)
		{
			// check if it is possible to go to position
			// (i + row[k], j + col[k]) from current position
			if (isValid(mat, visited, i + row[k], j + col[k]))
			{
				// mark next cell as visited and enqueue it
				visited[i + row[k]][j + col[k]] = true;
				q.push({ i + row[k], j + col[k], dist + 1 });
			}
		}
	}

	if (min_dist != INT_MAX) {
		return min_dist;
	}

	return -1;
}
