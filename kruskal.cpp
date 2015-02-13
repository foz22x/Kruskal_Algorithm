#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef pair <int,pair<int,int> > edgeWeight; 
typedef priority_queue <edgeWeight, vector<edgeWeight>, greater<edgeWeight> > min_priority_queue;
vector<edgeWeight> kruskal(int n, min_priority_queue Q);
void displayEdge(edgeWeight a);

int main(){

	int vertices, edge;
	int  a, b, w;
	min_priority_queue QUEUE;

	cout << "Input vertices and edges (N, E): " << endl;
    cin >> vertices >> edge;
        
	for(int i = 0; i < edge; ++i){
        	cout << "Input edge (a, b) and weight: " << endl;
			cin >> a >> b >> w;
            QUEUE.push(make_pair(w, make_pair(a, b)));
    }
        
	vector<edgeWeight> edges(kruskal(vertices, QUEUE));
                                                        
	for (int i = 0; i < edges.size(); ++i){ 
		displayEdge(edges[i]); 
	}
 
	return 0;
}

vector<edgeWeight> kruskal(int vertices, min_priority_queue QUEUE){

	map<int,int> linked;
	vector<edgeWeight> edges;

        
	for (int i = 1; i <= vertices; ++i) { 
		linked[i]=i; 
	}

    while(!QUEUE.empty()){

      	int a = QUEUE.top().second.first;
		int b = QUEUE.top().second.second;
		int c = QUEUE.top().first;
        int aParent = linked[a]; 
        int bParent = linked[b];

	if(aParent != bParent){
        edges.push_back(make_pair(c, make_pair(a, b)));
                        
		for (int i = 1; i <= vertices; ++i){
            if(linked[i] == aParent){
                linked[i] = bParent;
            }
        }
    }
    QUEUE.pop();
    }
	return edges;
}

void displayEdge(edgeWeight a){

	cout << a.second.first << " -> ";
	cout << a.second.second << " : ";
	cout << a.first << "\n";

	return;
}
