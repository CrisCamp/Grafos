#include<iostream>
#include <list>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"

using namespace std;
using namespace sf;

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V; //Numero de vertices
    list<int>* adj; //arreglo de listas de adyacencia
    bool* visited; //matriz de visitados.
public:
    Graph(int V); //Constructor
    void addEdge(int v, int w); //GRAFO Dirigido de v -> w
    void DFS(int v); //DFS iniciando de v
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
    this->visited = new bool[this->V];
    for (int i = 0; i < this->V; i++) this->visited[i] = false;
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); //agrega w a la posicion v
    adj[w].push_back(v); //si fuera no dirigido 
}
void Graph::DFS(int v) {
    this->visited[v] = true; //marca el nodo actual como visitado e imprimelo
    cout << v << " ";

    list<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); ++it) { //nodos adyacentes
        if (!this->visited[*it]) {
            DFS(*it);
        }
    }
}
int main() {
    int V = 9;
    Graph G(V);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(0, 3);
    G.addEdge(1, 0);
    G.addEdge(1, 4);
    G.addEdge(2, 0);
    G.addEdge(2, 4);
    G.addEdge(2, 7);
    G.addEdge(3, 0);
    G.addEdge(3, 5);
    G.addEdge(4, 1);
    G.addEdge(4, 2);
    G.addEdge(4, 6);
    G.addEdge(5, 3);
    G.addEdge(5, 8);
    G.addEdge(6, 4);
    G.addEdge(7, 2);
    G.addEdge(8, 5);

    int src = 0;
    cout << "La DFS de G es (iniciando de el vertice 2): " << endl << endl;
    G.DFS(src);
    /**
    Si el grafo fuera disconexo:
        for(int i=0;i<V;i++){
            G.DFS(i);
        }
    */
    return 0;
}