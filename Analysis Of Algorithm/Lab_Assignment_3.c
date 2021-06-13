/***************************************************************************************************************
   NAME : GINI CHACKO
   CLASS : SE COMPS B
   BATCH : B
   ROLL NO : 8942
   LAB ASSIGNMENT: 3 (Implementation of Fractional Knapsack - Greedy approach)
   
****************************************************************************************************************/

//CODE:

		# include<stdio.h>
		 
		void knapsack(int n, float weight[], float profit[], float capacity) {
		   float x[20], tp = 0;
		   int i, j, u;
		   u = capacity;
		 
		   for (i = 0; i < n; i++)
			  x[i] = 0.0;
		 
		   for (i = 0; i < n; i++) 
		   {
			  if (weight[i] > u)
				 break;
			  else 
			  {
				 x[i] = 1.0;
				 tp = tp + profit[i];
				 u = u - weight[i];
			  }
		   }
		 
		   if (i < n)
			  x[i] = u / weight[i];
		 
		   tp = tp + (x[i] * profit[i]);
		 
		   printf("\nThe result vector is : ");
		   for (i = 0; i < n; i++)
			  printf("%f ", x[i]);
		 
		   printf("\nMaximum profit is :  %f", tp);
		 
		}
		 
		int main() 
		{
		   float weight[20], profit[20], capacity;
		   int num, i, j;
		   float ratio[20], temp;
		 
		   printf("**********FRACTIONAL KNAPSACK - GREEDY APPROACH*********");
		   printf("\nEnter the no. of objects : ");
		   scanf("%d", &num);
		 
		   for(i=0; i < num; i++)
			{
				printf("\nEnter %d(th)  profit : ", (i+1));
				scanf("%f", &profit[i]);
				
				printf("Enter %d(th)  weight : ", (i+1));
				scanf("%f", &weight[i]);
				
				ratio[i]=profit[i]/weight[i];
			}
		   
		   printf("\nEnter the capacity of knapsack : ");
		   scanf("%f", &capacity);

		   for (i = 0; i < num; i++) 
		   {
			  for (j = i + 1; j < num; j++) 
			  {
				 if (ratio[i] < ratio[j]) 
				 {
					temp = ratio[j];
					ratio[j] = ratio[i];
					ratio[i] = temp;
		 
					temp = weight[j];
					weight[j] = weight[i];
					weight[i] = temp;
		 
					temp = profit[j];
					profit[j] = profit[i];
					profit[i] = temp;
				 }
			  }
		   }
		 
		   knapsack(num, weight, profit, capacity);
		   return(0);
		}
		
/*********************************************************************************************************************
OUTPUT :

	TEST CASE 1 :

			**********FRACTIONAL KNAPSACK - GREEDY APPROACH*********                                                                        
			Enter the no. of objects : 4                                                                                                    
																																			
			Enter 1(th)  profit : 42                                                                                                        
			Enter 1(th)  weight : 7                                                                                                         
																																			
			Enter 2(th)  profit : 12                                                                                                        
			Enter 2(th)  weight : 3                                                                                                         
																																			
			Enter 3(th)  profit : 40                                                                                                        
			Enter 3(th)  weight : 4                                                                                                         
																																			
			Enter 4(th)  profit : 25                                                                                                        
			Enter 4(th)  weight : 5                                                                                                         
																																			
			Enter the capacity of knapsack : 10                                                                                             
																																			
			The result vector is : 1.000000 0.857143 0.000000 0.000000                                                                      
			Maximum profit is :  76.000000 
				
	
	TEST CASE 2 :
	
			**********FRACTIONAL KNAPSACK - GREEDY APPROACH*********                                                                        
			Enter the no. of objects : 7                                                                                                    
																																			
			Enter 1(th)  profit : 10                                                                                                        
			Enter 1(th)  weight : 2                                                                                                         
																																			
			Enter 2(th)  profit : 5                                                                                                         
			Enter 2(th)  weight : 3                                                                                                         
																																			
			Enter 3(th)  profit : 15                                                                                                        
			Enter 3(th)  weight : 5                                                                                                         
																																			
			Enter 4(th)  profit : 7                                                                                                         
			Enter 4(th)  weight : 7                                                                                                         
																																			
			Enter 5(th)  profit : 6                                                                                                         
			Enter 5(th)  weight : 1                                                                                                         
																																			
			Enter 6(th)  profit : 18                                                                                                        
			Enter 6(th)  weight : 4                                                                                                         
																																			
			Enter 7(th)  profit : 3                                                                                                         
			Enter 7(th)  weight : 1                                                                                                         
																																			
			Enter the capacity of knapsack : 15                                                                                             
																																			
			The result vector is : 1.000000 1.000000 1.000000 1.000000 1.000000 0.666667 0.000000                                           
			Maximum profit is :  55.333332  

***********************************************************************************************************/			