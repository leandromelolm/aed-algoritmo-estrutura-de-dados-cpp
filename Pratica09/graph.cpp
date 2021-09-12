
#include "graph.h"
#include "heap.h"

#include <queue>

using namespace std;

// Cria array do tipo T com tamanho "size" e inicializa com valor "def"
template <class T>
T * array(int size, T def) {
	T * arr = new T[size];
	for (int i = 0; i < size; i++) arr[i] = def;
	return arr;
}

Graph::Graph(int nVert) {
	this->nVert = nVert;
	this->adj = new list<Edge>[nVert];
}

Graph::~Graph() {
	delete [] adj;
}

int Graph::size() {
	return nVert;
}

// Criação da aresta src --> dst
void Graph::edge(int src, int dst, int w) {
	// TODO
}

int Graph::degree(int src) {
	// TODO
	return -1;
}

list<int> Graph::neighbors(int src) {
	// TODO
	list<int> vertices;

	return vertices;
}


int Graph::weight(int src, int dst) {
	// TODO

	return  -1;
}

void Graph::print() {
	for (int i = 0; i < this->size(); i++) {
		int d = this->degree(i);

		cout << i << "(" << d << "): ";

		list<int> nei = this->neighbors(i);
		for (int dst : nei) {
			int w = this->weight(i, dst);
			cout << dst << "[" << w << "]; ";
		}

		cout << endl;
	}
}

// -------- PRAT 10 --------------//

// Busca em profundidade
list<int> Graph::dfs(int src) {
	list<int> result;
	int * visited = array(nVert, 0);

	DFS(src, visited, result);

	delete [] visited;
	return result;
}

// Busca em profundidade
void Graph::DFS(int src, int * visited, list<int> &result) {
	// TODO
}

// Busca em largura
list<int> Graph::bfs(int src) {
	list<int> result;
	int * visited = array(nVert, 0);

	BFS(src, visited, result);

	delete [] visited;
	return result;
}

// Busca em largura
void Graph::BFS(int src, int * visited, list<int> &result) {
	// TODO
}

list<int> Graph::spf(int src, int dst) {
	int * dist = array(nVert, 99999);		// array de distâncias acumuladas; 99999 = INF
	int * prev = array(nVert, -1);			// array de vértices anteriores
											//   contém menores caminhos
	dist[src] = 0;

	// Cria o heap (mínimo) baseado na distância
	Heap<int> pq(nVert, dist);

	while(!(pq.empty())) {
		int node = pq.dequeue();	// pega nó com menor distância acumulada

		for (Edge e : adj[node]) {
			int v = e.dst;				// nó vizinho
			int w = e.weight;			// peso da aresta

			int D = dist[node] + w;			// nova distância

			if (D < dist[v]) {				// menor que antiga?
				prev[v] = node;				// atualize anterior
				dist[v] = D;				// atualize distância
				pq.decrease(v);				// atualize o heap (PQ)
			}
		}
	}

	list<int> result;						// menor caminho

	path(dst, prev, result);				// extrair caminho em result

	delete [] dist;
	delete [] prev;

	return result;
}

void Graph::path(int dst, int * prev, list<int> &result) {
	// TODO
}


