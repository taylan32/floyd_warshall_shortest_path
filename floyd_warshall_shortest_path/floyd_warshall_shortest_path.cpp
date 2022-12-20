#include <stdio.h>

#define NUMBER_OF_VERTICES 5
#define INF 99999999

void printMatrix(int matrix[][NUMBER_OF_VERTICES]);
void floydWarshall(int graph[][NUMBER_OF_VERTICES]);

int main(void) {

	// directed graph (cift yönlü)
	int graph1[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES] = {
		{0, 3, INF, 5, 3},
		{2, 0, INF, 4, INF},
		{INF, 1, 0, INF, 2},
		{INF, INF, 2, 0, INF},
		{INF, 2, 1, INF, 0}
	};

	// directed graph. (tek yönlü)
	int graph2[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES] = {
		{0,   5,  INF, 10, 8},
		{INF,  0,  3,  INF, 5},
		{INF, INF, 0,   1, INF},
		{INF, INF, INF, 0, 4},
		{1, 4, 6, 2, 0}
	};

	// undirected graph
	int graph3[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES] = {
		{0, 10, INF, 5, INF },
		{10, 0, 5, 5, 10},
		{INF, 5, 0, INF, INF},
		{5, 5, INF, 0, 20},
		{INF, 10, INF, 20, 0}
	};

	int graph4[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES] = {
		{0, 4, 2, INF, INF},
		{INF, 0, INF, INF, INF},
		{INF, 6, 0, 4, INF},
		{INF, INF, INF, 0, INF},
		{8, INF, 3, 4, 0}
	};

	//floydWarshall(graph1);
	//floydWarshall(graph2);
	//floydWarshall(graph3);
	floydWarshall(graph4);

	return 0;
}


void floydWarshall(int graph[][NUMBER_OF_VERTICES]) {
	int matrix[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES], i, j, k;

	for (i = 0; i < NUMBER_OF_VERTICES; i++) {
		for (j = 0; j < NUMBER_OF_VERTICES; j++) {
			matrix[i][j] = graph[i][j];
		}
	}

	for (k = 0; k < NUMBER_OF_VERTICES; k++) {
		for (i = 0; i < NUMBER_OF_VERTICES; i++) {
			for (j = 0; j < NUMBER_OF_VERTICES; j++) {
				if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}

			}
		}
	}

	printMatrix(matrix);

}


void printMatrix(int matrix[][NUMBER_OF_VERTICES]) {
	for (int i = 0; i < NUMBER_OF_VERTICES; i++) {
		for (int j = 0; j < NUMBER_OF_VERTICES; j++) {
			if (matrix[i][j] == INF) {
				printf("%4s", "INF");
			}
			else {
				printf("%4d", matrix[i][j]);
			}
		}
		printf("\n");
	}
}