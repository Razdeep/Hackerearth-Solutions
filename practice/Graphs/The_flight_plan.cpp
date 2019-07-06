/**
 * @author: Rajdeep Roy Chowdhury
 *
 */

// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/traffic-light-2-ee27ba45/

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#define all(v) v.begin(), v.end()
#define deb(x) cerr << #x << " -> " << x << endl;
#define pb push_back

using namespace std;

void printPath(map<int, vector<int>>& graph, int source, int destination)
{
	queue<int> myqueue;
	myqueue.push(source);
	vector<bool> visited(graph.size() + 1, false);
	vector<int> came_from(graph.size() + 1, 0);
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
	int now = destination;
	vector<int> path;
	path.pb(now);
	while(now != source)
	{
		now = came_from[now];
		path.pb(now);
	}
	reverse(all(path));
	cout << path.size() << endl;
	for (int i = 0; i < int(path.size()); ++i)
		cout << path[i] << " ";
	cout << endl;
}
int main()
{
	int no_of_cities, no_of_routes, switching_interval, journey_time;
	cin >> no_of_cities >> no_of_routes >> switching_interval >> journey_time;
	map<int, vector<int>> graph;
	for (int i = 0; i < no_of_routes; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	for (int i = 0; i < int(graph.size()); ++i)
		sort(all(graph[i]));
	int source, destination;
	cin >> source >> destination;
	printPath(graph, source, destination);
	return 0;
}
