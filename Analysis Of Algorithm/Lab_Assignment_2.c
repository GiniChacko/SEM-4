/***************************************************************************************************************
   NAME : GINI CHACKO
   CLASS : SE COMPS B
   BATCH : B
   ROLL NO : 8942
   LAB ASSIGNMENT: 2
				   Implementation of
					1. linear search using iteration and recursive method
					2. binary search using iteration and recursive method
					3. FInd minimum and maximum in an array using divide and conquer approach
					
*****************************************************************************************************************/
/* 1. LINEAR SEARCH USING ITERATION AND RECURSIVE METHOD*/

/* A. LINEAR SEARCH USING ITERATION METHOD*/
//CODE:
		#include <stdio.h>
		int LSearch(int arr[], int n, int x)
		{
			int i;
			for (i = 0; i < n; i++)
				if (arr[i] == x)
					return i;
			return -1;
		}
		 
		int main()
				{
					int n, element, found_index,  array[100];
					printf("Enter the total elements in the array : ");
					scanf("%d", &n);
				 
					printf("Enter the array elements : \n");
					for (int i = 0; i < n; i++)
					{
						scanf("%d", &array[i]);
					}
				 
					printf("Enter the element to search : ");
					scanf("%d", &element);
				 
					found_index =  LSearch(array, n, element);
					if (found_index == -1)
					{
						printf("Element %d is not found in the array",element);
					}
					else
					{
						printf("Element %d is found at index %d ",  element,found_index);
					}
					return 0;
				} 

/********************************************************************************
OUTPUT:

	TEST CASE 1:
			Enter the total elements in the array : 5                                                                                     
			Enter the array elements :                                                                                                    
			11  22  33  44  55                                                                                                            
			Enter the element to search : 44                                                                                              
			Element 44 is found at index 3

	TEST CASE 2:
			Enter the total elements in the array : 4                                                                                       
			Enter the array elements :                                                                                                      
			67  11  23  6                                                                                                                   
			Enter the element to search : 77                                                                                                
			Element 77 is not found in the array     

************************************************************************************/			
                                     
/* B. LINEAR SEARCH USING RECURSIVE METHOD*/
//CODE:
		#include <stdio.h>
				int recSearch(int arr[], int n, int x) 
				{ 
					 if (n == 0) 
						return -1; 
					 else if (arr[n] == x) 
						return n; 
					 else 
						return recSearch(arr, n-1, x); 
				} 	
				
		int main()
					{
							int n, element, found_index,  array[100];
							printf("Enter the total elements in the array : ");
							scanf("%d", &n);
						 
							printf("Enter the array elements : \n");
							for (int i = 0; i < n; i++)
							{
								scanf("%d", &array[i]);
							}
						 
							printf("Enter the element to search : ");
							scanf("%d", &element);
						 
							found_index =  recSearch(array,n, element);
							if (found_index == -1)
							{
								printf("Element %d is not found in the array",element);
							}
							else
							{
								printf("Element %d is found at index %d ",  element,found_index);
							}
							return 0;
						} 


/**********************************************************************
OUTPUT:

	TEST CASE 1:
			Enter the total elements in the array : 5                                                                                       
			Enter the array elements :                                                                                                      
			11  43  78  25  4                                                                                                               
			Enter the element to search : 25                                                                                                
			Element 25 is found at index 3   
			
	TEST CASE 2:
			Enter the total elements in the array : 3                                                                                     
			Enter the array elements :                                                                                                    
			78  19  5                                                                                                                     
			Enter the element to search : 10                                                                                              
			Element 10 is not found in the array  
			
****************************************************************************************************/			
			
/*=====================================================================================================================================*/

/*2. BINARY SEARCH USING ITERATION AND RECURSIVE METHOD*/

/* A. BINARY SEARCH USING ITERATION METHOD*/
//CODE:
		#include <stdio.h>
		int iterativeBinarySearch(int array[], int start_index, int end_index, int element)
		{
		   while (start_index <= end_index)
		   {
			  int middle = start_index + (end_index- start_index )/2;
			  
			  if (array[middle] == element)
				 return middle;
				 
			  if (array[middle] < element)
				 start_index = middle + 1;
				 
			  else
				 end_index = middle - 1;
		   }
		   return -1;
		}

		int main()
		{
			int n, element, found_index, m = 0, array[100];
			printf("Enter the total elements in the array : ");
			scanf("%d", &n);
		 
			printf("Enter the array elements : \n");
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &array[i]);
			}
		 
			printf("Enter the element to search : ");
			scanf("%d", &element);
		 
			found_index =  iterativeBinarySearch(array, 0, n-1, element);
			if (found_index == -1)
			{
				printf("Element %d is not found in the array",element);
			}
			else
			{
				printf("Element %d is found at index %d ",  element,found_index);
			}
			return 0;
		}

/************************************************************
OUTPUT:

	TEST CASE 1: 
			Enter the total elements in the array : 4                                                                                       
			Enter the array elements :                                                                                                      
			11  22  33  44                                                                                                                  
			Enter the element to search : 44                                                                                                
			Element 44 is found at index 3    
	
	TEST CASE 2:
			Enter the total elements in the array : 3                                                                                     
			Enter the array elements :                                                                                                    
			56  80  12                                                                                                                    
			Enter the element to search : 51                                                                                              
			Element 51 is not found in the array  
			
************************************************************/
/* B. BINARY SEARCH USING RECURSIVE METHOD*/
//CODE: 

		#include <stdio.h>
		int recursiveBinarySearch(int array[], int start_index, int end_index, int element)
		{
		   if (end_index >= start_index)
		   {
			  int middle = start_index + (end_index - start_index )/2;
			  
			  if (array[middle] == element)
				 return middle;
				 
			  if (array[middle] > element)
				 return recursiveBinarySearch(array, start_index, middle-1, element);
				 
			  return recursiveBinarySearch(array, middle+1, end_index, element);
		   }
		   return -1;
		}
		int main()
		{
			int n, element, found_index, m = 0, array[100];
			printf("Enter the total elements in the array : ");
			scanf("%d", &n);
		 
			printf("Enter the array elements : \n");
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &array[i]);
			}
		 
			printf("Enter the element to search : ");
			scanf("%d", &element);
		 
			found_index =  recursiveBinarySearch(array, 0, n-1, element);
			if (found_index == -1)
			{
				printf("Element not found");
			}
			else
			{
				printf("Element %d is found at index %d ",  element,found_index);
			}
			return 0;
		}

/************************************************************
OUTPUT:

	TEST CASE 1: 
			Enter the total elements in the array : 5                                                                                       
			Enter the array elements :                                                                                                      
			11  66  36  2  90                                                                                                               
			Enter the element to search : 36                                                                                                
			Element 36 is found at index 2 
	
	TEST CASE 2:
			Enter the total elements in the array : 6                                                                                       
			Enter the array elements :                                                                                                      
			1  5  89  35  23  67                                                                                                            
			Enter the element to search : 80                                                                                                
			Element 80 is not found in the array 

************************************************************/
/*===============================================================================================================================================*/

/*3. FIND MINIMUM AND MAXIMUM IN AN ARRAY USING DIVIDE AND CONQUER APPROACH*/
//CODE:
		#include <stdio.h>
		#include <stdlib.h>
		#define SIZE 20

		int findMinMax(int a[],int low,int high,int *min,int *max)
		{
			int minL, minR, maxL, maxR, mid;
			if(high == low)
				*min = *max = a[low];
				
			else if(low+1 == high)
			{
				if(a[low]<a[high])
				{
					*min = a[low];
					*max = a[high];
				}
				else
				{
					*min = a[high];
					*max = a[low];
				}
			}
			else
			{
				mid = ( low + high )/2;
				findMinMax(a, low, mid, &minL, &maxL);
				findMinMax(a, mid+1, high, &minR, &maxR );

				if(minL < minR)
					*min = minL;
				else
					*min = minR;

				if(maxL > maxR)
					*max = maxL;
				else
					*max = maxR;
			}
			return 0;
		}
		int main()
		{
			int a[SIZE], i, n,min,max, low = 0, high;
			printf("Enter the total elements in the array : ");
			scanf("%d", &n);
				 
			printf("Enter the array elements : \n");
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &a[i]);
			}
			high = n-1;
			findMinMax(a, low, high, &min, &max);
					
			printf("The minimum element from the array is %d\n", min);
			printf("The maximum element from the array is %d", max);
					

			return 0;		
		}
		
/*******************************************************************************************
OUTPUT:

	TEST CASE 1:
			Enter the total elements in the array : 5                                                                                     
			Enter the array elements :                                                                                                    
			11  22  33  44  55                                                                                                            
			The minimum element from the array is 11                                                                                      
			The maximum element from the array is 55 

	TEST CASE 2:
			Enter the total elements in the array : 4                                                                                     
			Enter the array elements :                                                                                                    
			2  67  14  36                                                                                                                 
			The minimum element from the array is 2                                                                                       
			The maximum element from the array is 67

**********************************************************************************************/