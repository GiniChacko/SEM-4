/***************************************************************************************************************
   NAME : GINI CHACKO
   CLASS : SE COMPS B
   BATCH : B
   ROLL NO : 8942
   LAB ASSIGNMENT: 6 
					  Implementation of 1. N Queen Problem
										2. Sum of Subsets
										3. Graph Coloring
   
****************************************************************************************************************/

//IMPLEMENTATION OF N QUEEN PROBLEM

//CODE :

	#include<stdio.h>

	#include<math.h>

	int board[20], count;

	int main() {
	  int n, i, j;
	  void queen(int row, int n);

	  printf("*********N Queens Problem Using Backtracking************");
	  printf("\n\nEnter number of Queens : ");
	  scanf("%d", & n);
	  queen(1, n);
	  return 0;
	}

	//function for printing the solution
	void print(int n) {
	  int i, j;
	  printf("\n\nSolution %d : \n\n", ++count);

	  for (i = 1; i <= n; ++i)
		printf("\t%d", i);

	  for (i = 1; i <= n; ++i) {
		printf("\n\n%d", i);
		for (j = 1; j <= n; ++j) //for nxn board
		{
		  if (board[i] == j)
			printf("\tQ"); //queen at i,j position
		  else
			printf("\t-"); //empty slot
		}
	  }
	}

	/*funtion to check conflicts
	If no conflict for desired postion returns 1 otherwise returns 0*/
	int place(int row, int column) {
	  int i;
	  for (i = 1; i <= row - 1; ++i) {
		//checking column and digonal conflicts
		if (board[i] == column)
		  return 0;
		else
		if (abs(board[i] - column) == abs(i - row))
		  return 0;
	  }

	  return 1; //no conflicts
	}

	//function to check for proper positioning of queen
	void queen(int row, int n) {
	  int column;
	  for (column = 1; column <= n; ++column) {
		if (place(row, column)) {
		  board[row] = column; //no conflicts so place queen
		  if (row == n) //dead end
			print(n); //printing the board configuration
		  else //try queen with next position
			queen(row + 1, n);
		}
	  }
	}
	
/*******************************************************************
OUTPUT :

	*********N Queens Problem Using Backtracking************                                                                        
																																	
	Enter number of Queens : 4                                                                                                      
																																	
																																	
	Solution 1 :                                                                                                                    
																																	
			1       2       3       4                                                                                               
																																	
	1       -       Q       -       -                                                                                               
																																	
	2       -       -       -       Q                                                                                               
																																	
	3       Q       -       -       -                                                                                               
																																	
	4       -       -       Q       -                                                                                               
																																	
	Solution 2 :                                                                                                                    
																																	
			1       2       3       4                                                                                               
																																	
	1       -       -       Q       -                                                                                               
																																	
	2       Q       -       -       -                                                                                               
																																	
	3       -       -       -       Q                                                                                               
																																	
	4       -       Q       -       -        



********************************************************************/

/*=====================================================================================================*/

//IMPLEMENTATION OF SUM OF SUBSETS

//CODE :

	#include<stdio.h>

	int w[10] = {
	  0
	};
	int n, s = 0, sol[10] = {
	  0
	}, tot_pl = 0, count = 0;

	int promising(int l, int wsf, int tpl) //to check whether the node is promising
	{
	  if (wsf + w[l + 1] <= s && wsf + tpl >= s) //check the required two conditions
	  {
		return 1;
	  }
	  return 0;
	}

	void sum_of_subsets(int l, int wsf, int tpl) {
	  int i;
	  if (wsf == s) {
		count++;
		printf("\nSolution Vector : %d", count); //print the solution vector
		printf("\n");
		for (i = 1; i <= n; i++) {
		  printf("%d\t", sol[i]);
		}
		printf("\n");
	  } else if (promising(l, wsf, tpl)) //check whether the node is promising
	  {
		sol[l + 1] = 1;
		sum_of_subsets(l + 1, wsf + w[l + 1], tpl - w[l + 1]);
		sol[l + 1] = 0;
		sum_of_subsets(l + 1, wsf, tpl - w[l + 1]);
	  }
	}

	int main() {
	  int i;
	  printf("Enter the number of distinct items: "); //number of items
	  scanf("%d", & n);
	  printf("\n");
	  for (i = 1; i <= n; i++) {
		printf("Enter the weight of the Item Number %d: ", (i)); //enter weight
		scanf("%d", & w[i]);
		tot_pl = tot_pl + w[i]; //Calulating total profit
	  }
	  printf("\nEnter the Maximum allowed weight : "); //maximum weight
	  scanf("%d", & s);
	  sum_of_subsets(0, 0, tot_pl); // call to sum of subset method
	  return 0;
	}
	
/*******************************************************************
OUTPUT :

	Enter the number of distinct items: 5                                                                                           
																																	
	Enter the weight of the Item Number 1: 1                                                                                        
	Enter the weight of the Item Number 2: 2                                                                                        
	Enter the weight of the Item Number 3: 3                                                                                        
	Enter the weight of the Item Number 4: 4                                                                                        
	Enter the weight of the Item Number 5: 5                                                                                        
																																	
	Enter the Maximum allowed weight : 10                                                                                           
																																	
	Solution Vector : 1                                                                                                             
	1       1       1       1       0                                                                                               
																																	
	Solution Vector : 2                                                                                                             
	1       0       0       1       1                                                                                               
																																	
	Solution Vector : 3                                                                                                             
	0       1       1       0       1         

********************************************************************/

/*=====================================================================================================*/

//IMPLEMENTATION OF GRAPH COLOURING

//CODE :

	#include<stdio.h>

	int n, sol[10] = {
	  0
	}, count = 0, adj[11][11] = {
	  0
	}, m;

	int can_color(int node, int c) {
	  int j;
	  for (j = 1; j <= node - 1; j++) {
		if (adj[j][node] == 1 && sol[j] == c) //check whether the adjacent node's colour is same as c
		  return 0;
	  }
	  return 1;
	}

	void m_color(int node) {
	  int i, j;
	  for (i = 1; i <= m; i++) {
		if (can_color(node, i)) //check whether the node can be coloured with i
		{
		  sol[node] = i;
		  if (node == n) //print solution vector
		  {
			count++;
			printf("\n********** Solution Vector : %d **********", count);
			printf("\n");
			for (j = 1; j <= n; j++) {
			  if (sol[j] == 1) //Changing 1 to Red
				printf("RED\t");
			  else if (sol[j] == 2) //Changing 2 to Green
				printf("GREEN\t");
			  else if (sol[j] == 3) //Changing 3 to Blue
				printf("BLUE\t");
			  else if (sol[j] == 4) //Changing 4 to Yellow
				printf("YELLOW\t");
			  else if (sol[j] == 5) //Changing 5 to Violet
				printf("VIOLET\t");
			}
			printf("\n");
		  } else
			m_color(node + 1); //Call to m_color method
		}
	  }
	}

	int main() {
	  int i, s, e, d, deg;
	  printf("\nEnter the degree of the graph : "); //degree of the graph
	  scanf("%d", & deg);
	  m = deg + 1;
	  printf("\nEnter no of vertices : ");
	  scanf("%d", & n);
	  printf("\nEnter no of edges :  ");
	  scanf("%d", & e);
	  for (i = 1; i <= e; i++) //enter the graph
	  {
		printf("\nFor Relation No:%d", i);
		printf("\nEnter source node :");
		scanf("%d", & s);
		if (s > n || s == 0) {
		  printf("\nInvalid source Node\nEnter again ");
		  i--;
		  continue;
		}
		printf("Enter destination node :");
		scanf("%d", & d);
		if (d > n || s == 0) {
		  printf("\nInvalid destination Node\nEnter again ");
		  i--;
		  continue;
		}
		adj[s][d] = 1; //Undirected Graph
		adj[d][s] = 1;
	  }
	  m_color(1);
	}

/*******************************************************************
OUTPUT :

	Enter the degree of the graph : 2                                                                                               
																																	
	Enter no of vertices : 4                                                                                                        
																																	
	Enter no of edges :  4                                                                                                          
																																	
	For Relation No:1                                                                                                               
	Enter source node :1                                                                                                            
	Enter destination node :3                                                                                                       
																																	
	For Relation No:2                                                                                                               
	Enter source node :2                                                                                                            
	Enter destination node :4                                                                                                       
																																	
	For Relation No:3                                                                                                               
	Enter source node :3                                                                                                            
	Enter destination node :1                                                                                                       
																																	
	For Relation No:4                                                                                                               
	Enter source node :4                                                                                                            
	Enter destination node :3              

	********** Solution Vector : 1 **********                                                                                       
	RED     RED     GREEN   BLUE                                                                                                    
																																	
	********** Solution Vector : 2 **********                                                                                       
	RED     RED     BLUE    GREEN                                                                                                   
																																	
	********** Solution Vector : 3 **********                                                                                       
	RED     GREEN   GREEN   RED                                                                                                     
																																	
	********** Solution Vector : 4 **********                                                                                       
	RED     GREEN   GREEN   BLUE                                                                                                    
																																	
	********** Solution Vector : 5 **********                                                                                       
	RED     GREEN   BLUE    RED                                                                                                     
																																	
	********** Solution Vector : 6 **********                                                                                       
	RED     BLUE    GREEN   RED                                                                                                     
																																	
	********** Solution Vector : 7 **********                                                                                       
	RED     BLUE    BLUE    RED                                                                                                     
																																	
	********** Solution Vector : 8 **********                                                                                       
	RED     BLUE    BLUE    GREEN                                                                                                   
																																	
	********** Solution Vector : 9 **********                                                                                       
	GREEN   RED     RED     GREEN 

	********** Solution Vector : 10 **********                                                                                      
	GREEN   RED     RED     BLUE                                                                                                    
																																	
	********** Solution Vector : 11 **********                                                                                      
	GREEN   RED     BLUE    GREEN                                                                                                   
																																	
	********** Solution Vector : 12 **********                                                                                      
	GREEN   GREEN   RED     BLUE                                                                                                    
																																	
	********** Solution Vector : 13 **********                                                                                      
	GREEN   GREEN   BLUE    RED                                                                                                     
																																	
	********** Solution Vector : 14 **********                                                                                      
	GREEN   BLUE    RED     GREEN                                                                                                   
																																	
	********** Solution Vector : 15 **********                                                                                      
	GREEN   BLUE    BLUE    RED                                                                                                     
																																	
	********** Solution Vector : 16 **********                                                                                      
	GREEN   BLUE    BLUE    GREEN                                                                                                   
																																	
	********** Solution Vector : 17 **********                                                                                      
	BLUE    RED     RED     GREEN                                                                                                   
																																	
	********** Solution Vector : 18 **********                                                                                      
	BLUE    RED     RED     BLUE  

	********** Solution Vector : 19 **********                                                                                      
	BLUE    RED     GREEN   BLUE                                                                                                    
																																	
	********** Solution Vector : 20 **********                                                                                      
	BLUE    GREEN   RED     BLUE                                                                                                    
																																	
	********** Solution Vector : 21 **********                                                                                      
	BLUE    GREEN   GREEN   RED                                                                                                     
																																	
	********** Solution Vector : 22 **********                                                                                      
	BLUE    GREEN   GREEN   BLUE                                                                                                    
																																	
	********** Solution Vector : 23 **********                                                                                      
	BLUE    BLUE    RED     GREEN                                                                                                   
																																	
	********** Solution Vector : 24 **********                                                                                      
	BLUE    BLUE    GREEN   RED  

********************************************************************/
