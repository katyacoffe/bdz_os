#include "lib/function.h"
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };

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
	
	vector<vector<int>> mat2 = mat;
	
	
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
		
		if (mat[i][j]!=0 ){
			mat2[i][j] = dist;
		}

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
	cout<<"Begin matrix"<<endl;
	for (int p = 0; p<M; p++ )
	{
		for (int t = 0; t<N; t++ )
			cout<<mat[p][t]<< "\t";
		cout<<""<<endl;
	}
	cout<<"Matrix with pathes"<<endl;
	for (int p = 0; p<M; p++ )
	{
		for (int t = 0; t<N; t++ )
			cout<<mat2[p][t]<< "\t";
		cout<<""<<endl;
	}

	if (min_dist != INT_MAX) {
		int ii = dest.first;
		int jj = dest.second;
		int min = min_dist;
		int dlina_i = abs(src.first - dest.first);
		int dlina_j = abs(src.second - dest.second);
		mat2[ii][jj] = 102;
		while (dlina_i >0 || dlina_j>0){
			if (mat2[ii][jj-1] == min - 1 && jj>=1){
				dlina_j -=1;
				mat2[ii][jj-1] = 101;
				jj-=1;
			}
			else if (mat2[ii][jj+1] == min - 1 && jj<=N-1){
				dlina_j -=1;
				mat2[ii][jj+1] = 101;
				jj+=1;
			}
			else if (mat2[ii-1][jj] == min - 1 && ii>=1){
				dlina_i -=1;
				mat2[ii-1][jj] = 101;
				ii-=1;
			}
			else if (mat2[ii+1][jj] == min - 1 && ii<=M-1){
				dlina_i -=1;
				mat2[ii+1][jj] = 101;
				ii+=1;
			}
			min-=1;
		}
		mat2[ii][jj] = 100;
		cout<<"Matrix, where our path = 101\nBegin = 100\nEnd = 102"<<endl;
		for (int p = 0; p<M; p++ )
		{
			for (int t = 0; t<N; t++ )
				cout<<mat2[p][t]<< "\t";
			cout<<""<<endl;
		}

		return min_dist;
	}

	return -1;
}
