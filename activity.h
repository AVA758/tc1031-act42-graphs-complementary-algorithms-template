#ifndef ACTIVITY_H
#define ACTIVITY_H

// =========================================================
// File: actitivy.h
// Author: Ricardo Navarro & Alain Vicencio
// Date: 15/11/2022
// =========================================================

#include "ugraph.h"
#include <queue>
#include <stack>
#include <set>
#include <vector>


template <class Vertex>

//==============================================================
// Uses nodes u and v to find adacencies, and in that adjacence,
// if the v node hadn't been explored, the function will call 
// itself recursively, and if it is visited, it will be added to
// the TS set of type vertex.
//
// COMPLEXITY: O(log(n))
//==============================================================
void dfs2(Vertex u, const UnweightedGraph<Vertex>* graph, std::set<Vertex> &reached, std::stack<Vertex> &TS) {
  
  typename std::set<Vertex>::iterator itr; 
  std::set<Vertex> connected = graph->getConnectionFrom(u);
  reached.insert(u);

  for (itr = connected.begin(); itr != connected.end(); itr++) {
    if (reached.find(*itr) == reached.end()) {
      dfs2(*itr, graph, reached, TS); 
      } 
  }

  TS.push(u);
}


//==============================================================
// Runs through each vertex node in the grah.
// If the vertex has not been visited, dfs2 is called.
// If it is visited, it adds it to the TS set and prints it. 
// Returns stringstream. 
//
// COMPLEXITY: O(n)
//==============================================================
template <class Vertex>
std::string topologicalSort(const UnweightedGraph<Vertex>* graph) {
  
  typename std::vector<Vertex>::iterator itr;
  std::stringstream aux;
  std::set<Vertex> reached;
  std::stack<Vertex> TS;

  bool* visited = new bool[graph->getVertexes().size()];

  std::vector<Vertex> vertex = graph->getVertexes();

  for (itr = vertex.begin(); itr != vertex.end(); itr++ ){
    if (reached.find(*itr) == reached.end()) { 
      dfs2(*itr, graph, reached, TS); 
      } 

  }

  aux << "[";
  while (!TS.empty()){
    aux << TS.top() << " ";
    TS.pop();
  }

  aux.seekp(-1, std::ios_base::end);
  aux << "]";

  return aux.str();

}


//==============================================================
// Returns a boolean result. 
// Compares positions u and v in an array.
// Returns false if, after enqueuing vertexes, the vertex
// index values in the arrays are equal.
// Returns true if the v index of the array is -1 or if otherwise. 
//
// COMPLEXITY: O(n)
//==============================================================
template <class Vertex>
bool isBipartite(const UnweightedGraph<Vertex>* graph) {

  typename std::vector<Vertex>::iterator itr;
  typename std::set<Vertex>::iterator j;
  
  std::vector<Vertex> vert = graph->getVertexes();
  std::set<Vertex> visited;
  std::set<Vertex> g1;
  std::set<Vertex> g2;
  std::stack<Vertex> pend;

  for (itr = vert.begin(); itr != vert.end(); itr++){
    if (visited.find(*itr) == visited.end()){
      pend.push(*itr);
      g1.insert(*itr);

      while (!pend.empty()){
        Vertex v = pend.top();
        pend.pop();

        if (visited.find(v) == visited.end()){
          visited.insert(v);
          std::set<Vertex> connect = graph->getConnectionFrom(v);

          for (j = connect.begin(); j != connect.end(); j++){
            if (visited.find(*j) == visited.end()){
              pend.push(*j);
              
              if (g1.find(v) != g1.end()){
                g2.insert(*j);
              }
              else{
                g1.insert(*j);
              }
            }
            else{
              if (g1.find(v) != g1.end()){
                if (g1.find(*j) != g1.end()){
                  return false;
                }
              }
              else {
                if (g2.find(*j) != g2.end()) {
                  return false;
                }
              }
            }
          }
        }
      }
    }
  }

  return true;
}


//==============================================================
// Returns boolean value. 
// Searches for adjacencies. When found, if not visited, return 
// true if the function has been called recursively.
// Returns true if the vertex of the adjacence is out 
// of the parent class. Returns false if otherwise.
//
// COMPLEXITY: O(log(n))
//==============================================================
template <class Vertex>
bool isCyclic(Vertex u, const UnweightedGraph<Vertex>* graph,
  std::set<Vertex> &reached, Vertex parent) {
  typename std::set<Vertex>::iterator itr;

  if (reached.find(u) != reached.end()) {
    return true;
  }

  reached.insert(u);
  std::set<Vertex> connected = graph->getConnectionFrom(u);

  for (itr = connected.begin(); itr != connected.end(); itr++) {
    if (*itr != parent) {
      if (isCyclic(*itr, graph, reached, u)){
        return true;
      }
    } 
  }

  return false;
}


//==============================================================
// Returns boolean value.
// Returns false if the isCyclic() function is called.
// Returns false if there are no vertexes marked as 'Reached'
// Returns true otherwise.
//
// COMPLEXITY: O(n)
//==============================================================
template <class Vertex>
bool isTree(const UnweightedGraph<Vertex>* graph) {
  typename std::vector<Vertex>::iterator itr;
  std::vector<Vertex> vertex = graph->getVertexes();

  for (itr = vertex.begin(); itr != vertex.end(); itr++) {
    std::set<Vertex> reached;
    if (isCyclic(*itr, graph, reached, *itr)) {
      return false;
    }
  }

  return true;
}



#endif /* ACTIVITY_H */
