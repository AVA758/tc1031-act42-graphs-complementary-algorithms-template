#ifndef ACTIVITY_H
#define ACTIVITY_H

// =========================================================
// File: actitivy.h
// Author:
// Date:
// =========================================================

#include "ugraph.h"
#include <queue>
#include <stack>
#include <set>


template <class Vertex>
void dfs2(Vertex u, const UnweightedGraph<Vertex>* graph, std::set<Vertex> &reached, std::stack<Vertex> &TS) {

  std::set<Vertex> visited;
  Vertex v;
  typename std::set<Vertex>::iterator itr;
  
  visited.insert(u); 
  std::set<Vertex> connected = graph->getConnectionFrom(u);
  for (itr = connected.begin(); itr != connected.end(); itr++) {
    if (visited.find(u) == visited.end()) {
      v =  connected(itr); 
      dfs2(v, graph, reached, TS); 
      } 
  }
  TS.push(u);
}

template <class Vertex>
std::string topologicalSort(const UnweightedGraph<Vertex>* graph) {
  
  typename std::vector<Vertex>::iterator itr;
  std::stringstream aux;
  std::set<Vertex> Reached;
  std::stack<Vertex> TS;

  for (int i=0;graph->getVertexes() > i; i++ ){
    if (visited.find(u) == visited.end()) { 
      dfs2(u, graph, reached, TS); 
      } 

  }

  while (!TS.empty()){
    aux.insert(TS.top());
    TS.pop();
  }

  return aux.str();

}

template <class Vertex>
bool isBipartite(const UnweightedGraph<Vertex>* graph) {

  typename std::vector<Vertex>::iterator itr;
  typename std::set<Vertex>::iterator j;
  typename std::queue<Vertex> q;
  typename std::array<Vertex> color;
  bool isBipartite;
  std::set<Vertex> vert = graph->getVertexes();

  for (int i = vert.begin(); i != vert.end(); i++){
    color[i] = -1;
  }

  isBipartite = TRUE;

  Vertex v = vert.begin();
  
 color[v] = 1;

 q.enqueue(v);
 
 while(!q.empty()){
  
 }

  return isBipartite;
}

template <class Vertex>
bool isCyclic(Vertex v, const UnweightedGraph<Vertex>* graph,
  std::set<Vertex> &reached, Vertex parent) {
  typename std::set<Vertex>::iterator itr;

  return false;
}

template <class Vertex>
bool isTree(const UnweightedGraph<Vertex>* graph) {
  typename std::vector<Vertex>::iterator itr;

  return false;
}



#endif /* ACTIVITY_H */
