#include <stdio.h>
#include <stdbool.h>
#include "Graph.h"

#define MAX_NODES 1000

int visited[MAX_NODES];

bool dfsPathCheck(Graph g, Vertex v, Vertex dest) {
   Vertex w;
   if (v == dest)
      return true;
   else {
      for (w = 0; w < numOfVertices(g); w++) {
	 if (adjacent(g, v, w) && visited[w] == -1) {
	    visited[w] = v;
	    if (dfsPathCheck(g, w, dest))
	       return true;
	 }
      }
   }
   return false;
}

bool findPathDFS(Graph g, Vertex src, Vertex dest) {
   Vertex v;
   for (v = 0; v < numOfVertices(g); v++)
      visited[v] = -1;
   visited[src] = src;
   return dfsPathCheck(g, src, dest);
}

int main(void) {
  Graph g = newGraph(6);

   Edge e;
   e.v = 0; e.w = 1; insertEdge(g, e);
   e.v = 0; e.w = 4; insertEdge(g, e);
   e.v = 0; e.w = 5; insertEdge(g, e);
   e.v = 5; e.w = 4; insertEdge(g, e);
   e.v = 4; e.w = 2; insertEdge(g, e);
   e.v = 4; e.w = 3; insertEdge(g, e);
   e.v = 5; e.w = 3; insertEdge(g, e);
   e.v = 1; e.w = 2; insertEdge(g, e);
   e.v = 3; e.w = 2; insertEdge(g, e);

   int src = 0, dest = 5;
   if (findPathDFS(g, src, dest)) {
      Vertex v = dest;
      while (v != src) {
	 printf("%d - ", v);
	 v = visited[v];
      }
      printf("%d\n", src);
   }
   freeGraph(g);
   return 0;
}
