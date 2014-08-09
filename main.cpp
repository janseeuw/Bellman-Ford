#include "graph.h"
#include <vector>

using namespace std;

template<EdgeType ET, class T>
class BellmanFord{
public:
	BellmanFord(GraphWithEdgedata<ET, T> &g, int s):g(g),wt(g.numberOfVertices()),spt(g.numberOfVertices()){
		const int INFINITY = std::numeric_limits<int>::max();
		
		// 1. Initialize weights and parents on path
		for(int i=0; i<g.numberOfVertices(); i++){
			wt[i]=INFINITY;
			spt[i]=-1;
		}
		wt[s]=0;
		
		// Place all vertices on a queue
		queue<int> q;
		for(int i=0;i<g.numberOfVertices();i++){
			q.push(i);
		}
		
		for(int i=0; i<g.numberOfVertices()-1; i++){
			// Foreach vertex check all edges
			/*for(int j=0; j<g.numberOfVertices();j++){
				map<int, int>::iterator it = g[j].begin();
				while(it != g[j].end()){
					int u=j;
					int v=it->first;
					int weight = *(g.getEdgedata(u,v));
					if (wt[u] + weight < wt[v]){
						wt[v] = wt[u] + weight;
					}
					it++;
				}
			}*/
			queue<int> q2; // queue for next round
			while(!q.empty()){
				q2.empty();
				int u = q.front();
				q.pop();
				map<int, int>::iterator it = g[u].begin();
				while(it != g[u].end()){
					int v=it->first;
					int weight = *(g.getEdgedata(u,v));
					if (wt[u] + weight < wt[v]){
						q2.push(v);
						wt[v] = wt[u] + weight;
					}
					it++;
				}
			}
			q=q2;
		}
	}
	int distance(int n){
		return wt[n];
	}
	int parent(int n){
		return spt[n];
	}
private:
	GraphWithEdgedata<ET, T> g;
	vector<int> wt;
	vector<int> spt;
};


int main()
{
	GraphWithEdgedata<DIRECTED, int> g(5);
	
	g.addEdge(0, 1, -1);
	g.addEdge(0, 2, 4);
	g.addEdge(1, 2, 3);
	g.addEdge(1, 3, 2);
	g.addEdge(1, 4, 2);
	g.addEdge(3, 1, 1);
	g.addEdge(3, 2, 5);
	g.addEdge(4, 3, -3);
	
	
	BellmanFord<DIRECTED, int> bf(g, 0);
	
	cout<<"Vertex\tDistance from Source (0)\n";
	for(int i=0; i<5; i++){
		cout<<i<<"\t"<<bf.distance(i)<<"\n";
	}
	
	return 0;
}