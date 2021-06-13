/***************************************************************************************************************
   NAME : GINI CHACKO
   CLASS : SE COMPS B
   BATCH : B
   ROLL NO : 8942
   LAB ASSIGNMENT: 5 (Longest Common Subsequence)
   
****************************************************************************************************************/

//IMPLEMENTATION OF THE LONGEST COMMON SUBSEQUENCE

//CODE :

	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>

	int c[10][10] = {
	  0
	}, b[10][10] = {
	  0
	};
	// initializing length array (c array) and direction array (b-array) to 0

	char x[10] = {
	  0
	}, y[10] = {
	  0
	}, sub[10] = {
	  0
	};
	/*  initializing first string(i.e.x),second string (i.e.y) and the subsequence string(i.e.sub) to zero */

	int i, j, m, n, len = 0; //length variable getting initialized to zero 

	int main() {

	  printf("ENTER THE 1ST STRING \n");
	  scanf("%s", x);
	  printf("ENTER THE 2ND STRING \n");
	  scanf("%s", y); // accepting the second string from the user 

	  m = strlen(x); // storing the length of first string in m variable 
	  n = strlen(y); // storing the length of second string in n variable 

	  for (i = 1; i <= m; i++) // i is the loop variable used for the 1st string
	  {
		for (j = 1; j <= n; j++) // j is the loop variable used for the 2nd string
		{
		  if (x[i - 1] == y[j - 1]) //last character of two strings are compared for equality 
		  {
			c[i][j] = c[i - 1][j - 1] + 1; // look at the value in diagonal direction and increment it by 1 
			b[i][j] = 1; //set direction as diagonal 
		  } else {
			if (c[i - 1][j] >= c[i][j - 1]) /*  checks and stores that value in c array and assigns the corresponding direction to b-array */ {
			  c[i][j] = c[i - 1][j];
			  b[i][j] = 2; //Top Box i.e. vertical direction 
			} else {
			  c[i][j] = c[i][j - 1];
			  b[i][j] = 3; //Horizontal Box i.e. horizontal direction 
			}
		  }
		}
	  }
	  printf("\n*****C-array*****\n");
	  for (i = 0; i <= m; i++) //loop for printing the length array 
	  {
		for (j = 0; j <= n; j++) {
		  printf("%d\t", c[i][j]);
		}
		printf("\n");
	  }
	  printf("\n*****B-array*****\n");
	  for (i = 0; i <= m; i++) // loop for printing the direction array 
	  {
		for (j = 0; j <= n; j++) {
		  printf("%d\t", b[i][j]);
		}
		printf("\n");
	  }
	  printf("\tHere,\n\t1 => Diagonal\n\t2 => Top\n\t3 => Horizontal"); // will print the directional information for the user's convenience 
	  while (1) //
	  {
		if (b[m][n] == 0) //when first column or first row is reached ( empty string)
		  break;
		else if (b[m][n] == 1) //letters at diagonal direction will give us the final subsequence 
		{
		  sub[len] = x[m - 1];
		  m = m - 1;
		  n = n - 1;
		  len++;
		} else if (b[m][n] == 2) // if vertical direction
		{
		  m = m - 1; // go the the previous row
		} else if (b[m][n] == 3) // if horizontal direction
		{
		  n = n - 1; // go to the previous column 
		}
	  }
	  printf("\n\nLONGEST COMMON SUB-SEQUENCE : ");
	  for (i = len - 1; i >= 0; i--) //loop for printing the subsequence 
		printf("%c", sub[i]);
	  printf("\n");
	  return 0;
	}

/***********************************************************

OUTPUT :

	ENTER THE 1ST STRING                                                                                                            
	adcd                                                                                                                            
	ENTER THE 2ND STRING                                                                                                            
	cadbd                                                                                                                           
																																	
	*****C-array*****                                                                                                               
	0       0       0       0       0       0                                                                                       
	0       0       1       1       1       1                                                                                       
	0       0       1       2       2       2                                                                                       
	0       1       1       2       2       2                                                                                       
	0       1       1       2       2       3                                                                                       
																																	
	*****B-array*****                                                                                                               
	0       0       0       0       0       0                                                                                       
	0       2       1       3       3       3                                                                                       
	0       2       2       1       3       1                                                                                       
	0       1       2       2       2       2                                                                                       
	0       2       2       1       2       1                                                                                       
			Here,                                                                                                                   
			1 => Diagonal                                                                                                           
			2 => Top                                                                                                                
			3 => Horizontal                                                                                                         
																																	
	LONGEST COMMON SUB-SEQUENCE : add      

************************************************************/