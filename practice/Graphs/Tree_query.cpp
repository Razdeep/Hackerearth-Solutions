// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/tree-query/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int no_of_vertices, no_of_edges;
	cin >> no_of_vertices >> no_of_edges;
	map<int, vector<int>> graph1;
	map<int, vector<int>> graph2;
	for (int i = 0; i < no_of_edges; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph1[u].push_back(v);
		graph2[v].push_back(u);
	}
	int count_sink_graph1, count_sink_graph2;
	count_sink_graph1 = count_sink_graph2 = 0;
	for (int i = 1; i <= no_of_vertices; ++i)
	{
		count_sink_graph1 += (graph1[i].size() == 0);
		count_sink_graph2 += (graph2[i].size() == 0);
	}
	cout << max(count_sink_graph1, count_sink_graph2) << endl;
	return 0;
}
