/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"
#include<iostream>
using namespace std;
/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph & graph, Vertex start, Vertex end)
{
    map<Vertex, Vertex> mymap;
    map<Vertex,int> distance;
    vector<Vertex> intial=graph.getVertices();
	for(int i=0;i<intial.size();i++)
		 graph.setVertexLabel(intial[i], "UNEXPLORED");
    queue<Vertex> myqueue;
    distance[start]=0;
    graph.setVertexLabel(start, "VISITED");
    myqueue.push(start);
    while(!myqueue.empty())
    {
        Vertex v = myqueue.front();
        vector<Vertex> adj = graph.getAdjacent(v);
        myqueue.pop();
        for (int i = 0; i < adj.size(); i++)
        {
            Vertex w = adj[i];
            if (graph.getVertexLabel(w).compare("UNEXPLORED") == 0)
            {
                mymap[w] = v;
                distance[w]=1+distance[v];
                graph.setEdgeLabel(v, w, "DISCOVERY");
                graph.setVertexLabel(w, "VISITED");
                myqueue.push(w);
            } 
       }
    }
	int shortest=distance[end];
	//back track to shortest path
	while (end != start)
    	{
        	graph.setEdgeLabel(end, mymap[end], "MINPATH");
        	end = mymap[end];
        }

		
    return shortest ;
}

/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph & graph)
{
    Vertex start = graph.getStartingVertex();
    vector<Vertex> intial=graph.getVertices();
	for(int i=0;i<intial.size();i++)
		 graph.setVertexLabel(intial[i], "UNEXPLORED");
    vector<Edge> ch=graph.getEdges();           
    //for(int i=0;i<ch.size();i++)
	//	 graph.setEdgeLabel(ch[i], "UNEXPLORED");
   
    vector<Vertex> adjacent = graph.getAdjacent(start);
    int weight = graph.getEdgeWeight(start, adjacent[0]);
       
    Vertex minim_v;
    Vertex minim_w;
    
    //BFS
    queue<Vertex> myqueue;
    graph.setVertexLabel(start, "VISITED");
    myqueue.push(start);
    while(!myqueue.empty())
    {
        Vertex u = myqueue.front();
	myqueue.pop();
        vector<Vertex> adj = graph.getAdjacent(u);
        
        for (int i = 0; i < adj.size(); i++)
        {
            Vertex v = adj[i];
            if (graph.getVertexLabel(v).compare("UNEXPLORED") == 0)
            {
                graph.setVertexLabel(v, "VISITED");
                graph.setEdgeLabel(u, v, "DISCOVERY");
                myqueue.push(v);
            } 
            if(graph.getEdgeWeight(u, v) <= weight)
            {
                weight = graph.getEdgeWeight(u,v);
                minim_w = v;
                minim_v = u;
            }
        }
    }

    graph.setEdgeLabel(minim_v, minim_w, "MIN");

    return weight;
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort (http://www.cplusplus.com/reference/algorithm/sort/)
 *  instead of creating a priority queue.
 */
void GraphTools::findMST(Graph & graph)
{
        DisjointSets set;
        set.addelements(graph.getVertices().size());
        vector<Edge> edges = graph.getEdges();
        int i=0;
        sort(edges.begin(), edges.end());   
        while(set.no_moreDsets()!=true) //helper function in dsets class
        {
            if(set.find(edges[i].source) != set.find(edges[i].dest)) 
            {
                        graph.setEdgeLabel(edges[i].source, edges[i].dest, "MST");
                        set.setunion(set.find(edges[i].source), set.find(edges[i].dest));
            }
            i++;
        }
}
