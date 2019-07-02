// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#define pb push_back
using namespace std;

// Returns proximity vector by using bfs
vector<int> getProximity(map<int, vector<int>> graph, int no_of_countries)
{
	vector<int> proximity(no_of_countries + 1, INT_MAX);
	proximity[1] = 0;
	vector<bool> visited(no_of_countries + 1, false);
	queue<int> myqueue;
	myqueue.push(1);
	visited[1] = true;
	while(!myqueue.empty())
	{
		int parent = myqueue.front();
		myqueue.pop();
		for (int connected: graph[parent])
		{
			if (!visited[connected])
			{
				visited[connected] = true;
				proximity[connected] = proximity[parent] + 1;
				myqueue.push(connected);
			}
		}
	}
	return proximity; 
}
int main()
{
	int no_of_countries;
	cin >> no_of_countries;
	int no_of_roads = no_of_countries - 1;
	map<int, vector<int>> graph;
	for (int i = 0; i < no_of_roads; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	int queries;
	cin >> queries;
	set<int> girl_set;
	for (int i = 0; i < queries; ++i)
	{
		int this_girl_address;
		cin >> this_girl_address;
		girl_set.insert(this_girl_address);
	}
	vector<int> proximity = getProximity(graph, no_of_countries);
	int best_proximity = INT_MAX, best_girl;
	for (int i = 1; i < int(proximity.size()); ++i)
	{
		if (girl_set.find(i) != girl_set.end()) // i-th girl exists
		{
			if (proximity[i] < best_proximity)
			{
				best_proximity = proximity[i];
				best_girl = i;
			}
		}
	}
	cout << best_girl << endl;
	return 0;
}
