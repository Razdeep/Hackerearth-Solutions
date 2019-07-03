//  https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define pb push_back
using namespace std;
int main()
{
	int no_of_vertices;
	cin >> no_of_vertices;
	int no_of_edges = no_of_vertices - 1;
	map<int, vector<int>> graph;
	queue<int> myqueue;
	for (int i = 0; i < no_of_edges; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	int query_level;
	cin >> query_level;
	vector<int> level(no_of_vertices + 1, 0);
	vector<bool> visited(no_of_vertices + 1, false);
	myqueue.push(1);
	visited[1] = true;
	level[1] = 1;
	while(!myqueue.empty())
	{
		int parent = myqueue.front();
		myqueue.pop();
		for (int connected: graph[parent])
		{
			if (!visited[connected])
			{
				visited[connected] = true;
				myqueue.push(connected);
				level[connected] = level[parent] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < int(level.size()); ++i)
		ans += (level[i] == query_level);
	cout << ans << endl;
	return 0;
}
