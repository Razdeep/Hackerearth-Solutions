// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define deb(x) cerr << #x << " -> " << x << endl;
#define pb push_back
using namespace std;
void bfs(map<int, vector<int>>& graph)
{
	int no_of_vertices = int(graph.size());
	vector<bool> visited(no_of_vertices + 1, false);
	queue<int> myqueue;
	myqueue.push(1);
	visited[1] = true;
	vector<int> came_from(no_of_vertices + 1, 0);
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
				came_from[connected] = parent;
			}
		}
	}
	vector<int> path;
	int destination = no_of_vertices;
	int now = destination;
	path.pb(now);
	while(now != 1)
	{
		now = came_from[now];
		path.pb(now);
	}
	cout << path.size() - 1 << endl;
}
int main()
{
	int testcase;
	cin >> testcase;
	while(testcase--)
	{
		int no_of_vertices, no_of_edges;
		cin >> no_of_vertices >> no_of_edges;
		map<int, vector<int>> graph;
		for(int i = 0; i < no_of_edges; ++i)
		{
			int u, v;
			cin >> u >> v;
			graph[u].pb(v);
			graph[v].pb(u);
		}
		bfs(graph);
	}
	return 0;
}
