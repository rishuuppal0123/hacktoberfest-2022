#include <bits/stdc++.h>
using namespace std;

#define row 5
#define col 5


int isSafe(int M[][col], int r, int c, bool visited[][col])
{
	return (r >= 0) && (r < row) && (c >= 0) && (c < col) && (M[r][c] && !visited[r][c]);
}


void DFS(int M[][col], int r, int c, bool visited[][col])
{
	static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	visited[r][c] = true;

	for (int k = 0; k < 8; ++k)
		if (isSafe(M, r + rowNbr[k], c + colNbr[k], visited))
			DFS(M, r + rowNbr[k], c + colNbr[k], visited);
}

int count(int M[][col])
{
	bool visited[row][col];
	memset(visited, 0, sizeof(visited));

	int c = 0;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)

			if (M[i][j] && !visited[i][j]) {
				DFS(M, i, j, visited);
				++c;
			}

	return c;
}

int main()
{
	int M[][col] = { { 1, 1, 0, 0, 0 },
					{ 0, 1, 0, 0, 1 },
					{ 1, 0, 0, 1, 1 },
					{ 0, 0, 0, 0, 0 },
					{ 1, 0, 1, 0, 1 } };

	cout << "Total Number of islands is: " << count(M);

	return 0;
}

