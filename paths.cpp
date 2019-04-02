#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define F(i, a, b)  for(int i = a;i < b;i++)
#define RF(i, a, b) for(int i = a-1;i >= b;i--)
#define FIT(i, v)   for(auto i: v)
#define FRIT(i, v)  for(auto &i: v)

class graph{
	int n;
	list<int> *adj;
	vi in_degree;
public:
	graph(int x):n(x+1){
		adj = new list<int> [n];
		in_degree.resize(n, 0);
	}
	~graph(){
		delete[] adj;
	}
	void add_edges(int u, int v){
		adj[u].push_back(v);
		in_degree[v]++;
	}
	int longest_path();
};

int graph::longest_path(){
	vector<int> dist(n, 0);
	queue<int> q;
	q.push(0);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(auto v: adj[u]){
			dist[v] = max(dist[v], dist[u] + 1);
			--in_degree[v];
			
			if(in_degree[v] == 0)
				q.push(v);
		}
	}

	int longest_dist = *max_element(dist.begin(), dist.end());

	return longest_dist-1;
}

int main(){
	int n, m;
	cin >> n >> m;
	int u, v;
	graph g(n);

	F(i, 0, m){
		cin >> u >> v;
		g.add_edges(u, v);
	}
	// add a fake vertex which connects all other vertices
	F(i, 1, n+1){
		g.add_edges(0, i);
	}

	cout << g.longest_path() << endl;

	return 0;
}