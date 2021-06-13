/***************************************************************************************************************
   NAME : GINI CHACKO
   CLASS : SE COMPS B
   BATCH : B
   ROLL NO : 8942
   LAB ASSIGNMENT: 4 (Implementation of Dijkstra's algorithm to find single source shortest path
                      or Implantation of Prims algorithm to find Minimum spanning tree)
   
****************************************************************************************************************/

//CODE:
// Dijkstra's Algorithm 


	#include <stdio.h>
	#define INFINITY 9999
	#define MAX 10

	void Dijkstra(int Graph[MAX][MAX], int n, int start)
	 {
	  int cost[MAX][MAX], distance[MAX], pred[MAX];
	  int visited[MAX], count, mindistance, nextnode, i, j;

	  // Creating cost matrix
	  for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		  if (Graph[i][j] == 0)
			cost[i][j] = INFINITY;
		  else
			cost[i][j] = Graph[i][j];

	  for (i = 0; i < n; i++)
	  {
		distance[i] = cost[start][i];//initially distance is cost of the edge from source to that node
		pred[i] = start;//predecessor is the source node
		visited[i] = 0;//node not visited
	  }

	  //beginning from source node
	  distance[start] = 0;//distance of source node from itself is 0
	  visited[start] = 1;//mark source node as visited
	  count = 1;

	  while (count < n - 1)
	  {
		mindistance = INFINITY;

		for (i = 0; i < n; i++)
		  if (distance[i] < mindistance && !visited[i])
		  {
			mindistance = distance[i];
			nextnode = i;
		  }

		visited[nextnode] = 1;
		for (i = 0; i < n; i++)
		  if (!visited[i])
			if (mindistance + cost[nextnode][i] < distance[i])
			{
			  distance[i] = mindistance + cost[nextnode][i];
			  pred[i] = nextnode;
			}
		count++;
	  }

	  // Printing the distance
	  for (i = 0; i < n; i++)
		if (i != start) {
		  printf("\nDistance from source to %d: %d", i, distance[i]);
		}
		printf("\n");
	}
	int main() {
	  int Graph[MAX][MAX], i, j, n, u;

	  printf("\n*************DIJKSTRA'S ALGORITHM*************\n");
	  printf("\n Enter the number of nodes in the Graph : ");
	  scanf("%d",&n);
	 
	  printf("\n Enter the adjacency matrix of the Graph : \n");
	  for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d",&Graph[i][j]);

	  u = 0;
	  Dijkstra(Graph, n, u);
	  return 0;
	}
/*****************************************************************************
OUTPUT :

		*************DIJKSTRA'S ALGORITHM*************                                                                                  
																																		
		Enter the number of nodes in the Graph : 6                                                                                     
																																		
		Enter the adjacency matrix of the Graph :                                                                                      
		0 6 0 0 0 1                                                                                                                     
		3 4 6 0 0 3                                                                                                                     
		6 7 1 0 4 0                                                                                                                     
		0 0 0 5 0 0                                                                                                                     
		4 7 0 8 0 5                                                                                                                     
		1 0 0 2 0 0                                                                                                                     
																																		
		Distance from source to 1: 6                                                                                                    
		Distance from source to 2: 12                                                                                                   
		Distance from source to 3: 3                                                                                                    
		Distance from source to 4: 16                                                                                                   
		Distance from source to 5: 1    
		
******************************************************************************/

//CODE:

//Prims algorithm to find Minimum spanning tree

#include<stdio.h>
#include<stdlib.h>

#define infinity 9999
#define MAX 20

int prims(int G[MAX][MAX],int spanning[MAX][MAX],int n)
{
	int cost[MAX][MAX];
	int u,v,min_distance,distance[MAX],from[MAX];
	int visited[MAX],no_of_edges,i,min_cost,j;


	//create cost[][] matrix,spanning[][]
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
		{
			if(G[i][j] == 0)
				cost[i][j] = infinity;
			else
				cost[i][j] = G[i][j];
				spanning[i][j] = 0;
		}

	//initialize visited[],distance[] and from[]
	distance[0] = 0;
	visited[0] = 1;

	for(i = 1; i < n; i++)
	{
		distance[i] = cost[0][i];
		from[i] = 0;
		visited[i] = 0;
	}

	min_cost = 0;		//cost of spanning tree
	no_of_edges = n - 1;		//no. of edges to be added

	while(no_of_edges > 0)
	{
		//find the vertex at minimum distance from the tree
		min_distance = infinity;
		for(i = 1; i < n; i++)
			if(visited[i] == 0 && distance[i] < min_distance)
			{
				v = i;
				min_distance = distance[i];
			}

		u = from[v];

		//insert the edge in spanning tree
		spanning[u][v] = distance[v];
		spanning[v][u] = distance[v];
		no_of_edges--;
		visited[v] = 1;

		//updated the distance[] array
		for(i = 1; i < n; i++)
			if(visited[i] == 0 && cost[i][v] < distance[i])
			{
				distance[i] = cost[i][v];
				from[i] = v;
			}

		min_cost = min_cost + cost[u][v];
	}

	return(min_cost);
}

int main()
{
	int i,j,total_cost;
	int G[MAX][MAX],spanning[MAX][MAX],n;
	printf("\n**************PRIM'S ALGORITHM - MINIMUM SPANNING TREE**********\n");
	printf(" Enter the number of nodes in the Graph : ");
	scanf("%d",&n);

	printf("\n Enter the adjacency matrix of the Graph : \n");

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);

	total_cost=prims(G,spanning,n);
	printf("\n The Minimum Spanning Tree Matrix is : \n");

	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d\t",spanning[i][j]);
	}
    
	printf("\n Total cost of spanning tree = %d",total_cost);
	return 0;
}
/***********************************************************************************
OUTPUT :

		**************PRIM'S ALGORITHM - MINIMUM SPANNING TREE**********                                                                
		Enter the number of nodes in the Graph : 6                                                                                     
																																		
		Enter the adjacency matrix of the Graph :                                                                                      
		1 2 0 0 6 1                                                                                                                     
		2 0 3 4 2 1                                                                                                                     
		0 0 0 2 9 0                                                                                                                     
		2 0 3 0 5 1                                                                                                                     
		4 0 9 4 0 0                                                                                                                     
		0 0 0 2 3 0                                                                                                                     
																																		
		The Minimum Spanning Tree Matrix is :                                                                                          
																																		
		0       0       0       0       0       1                                                                                       
		0       0       0       0       0       1                                                                                       
		0       0       0       2       0       0                                                                                       
		0       0       2       0       4       1                                                                                       
		0       0       0       4       0       0                                                                                       
		1       1       0       1       0       0 

		Total cost of spanning tree = 10010                                                                                            
                                  
*************************************************************************************/