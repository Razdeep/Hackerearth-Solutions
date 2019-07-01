// https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-at-the-graph-factory/

/**
 * Explanation:
 *	Sum of Degrees for a graph = 2 x Number of edges of the graph
 *
 * Similarly,
 * 	Sum of Degrees of tree = 2 x (number of edges - 1)
 *
 */
#include <iostream>
#include <vector>
bool isTree(int no_of_vertices, int sum_of_degrees)
{
	return (sum_of_degrees == 2 * (no_of_vertices - 1));
}
using namespace std;
int main()
{
	int no_of_vertices;
	cin >> no_of_vertices;
	vector<int> degrees(no_of_vertices);
	int sum_of_degrees = 0;
	for (int i = 0; i < no_of_vertices; ++i)
	{
		cin >> degrees[i];
		sum_of_degrees += degrees[i];
	}
	cout << (isTree(no_of_vertices, sum_of_degrees) ? "Yes" : "No") << endl;
	return 0;
}
