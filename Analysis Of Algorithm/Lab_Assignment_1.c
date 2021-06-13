/***************************************************************************************************************
   NAME : GINI CHACKO
   CLASS : SE COMPS B
   BATCH : B
   ROLL NO : 8942
   LAB ASSIGNMENT: 1 (Sorting Algorithms)
				   		
*****************************************************************************************************************/

/* 1. IMPLEMENTATION FOR BUBBLE SORT*/
//CODE:
		#include<stdio.h>

		void bubbleSort(int a[],int n)
		{
			int pass,j,t;
			for(pass = 1; pass<= n-1 ; pass++)
			{
				for(j=0 ; j<n-pass ; j++)
				{
					if (a[j] > a[j+1])		//if consecutive elements not in order then swap
					{
						t=a[j];
						a[j]=a[j+1];
						a[j+1]=t;
					}
				}
				//for output after every passs, write print in for loop
			}
		}

		int main(int argc, char const *argv[])
		{
			int a[10],n,i;

			printf("Enter number of elements : ");	
			scanf("%d",&n);
		 
			printf("Enter the %d elements : \t",n);		//input the elements
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);

			bubbleSort(a,n);	//function call

			printf("The sorted array is : \t");		//print the sorted elements
			for(i=0;i<n;i++)
				printf("%d\t",a[i]);
			
			return 0;
		}
		
/*********************************************************************
OUTPUT:
	
	TEST CASE 1:
			Enter number of elements : 5                                                                                                    
			Enter the 5 elements :  10  5  81  -2  45                                                                                       
			The sorted array is :   -2      5       10      45      
	
	TEST CASE 2:
			Enter number of elements : 4                                                                                                  
			Enter the 4 elements :  80   -3  -5  17                                                                                       
			The sorted array is :   -5      -3      17      80  
			
**********************************************************************/

/*=====================================================================================================================================*/

/* 2. IMPLEMENTATION FOR MODIFIED BUUBLE SORT*/
//CODE:
		#include<stdio.h>

		void modBubbleSort(int a[],int n)
		{
			int pass,j,t;
			int exchange = 1;//boolean variable to denote exchange has happened or not in the previous pass
			for(pass=1; pass<= n-1 && exchange==1 ; pass++)
			{
				exchange=0;	//assuming exchange won't happen in this pass

				for(j=0 ; j<n-pass ; j++)
				{
					if (a[j] > a[j+1])		//if consecutive elements not in order then swap
					{
						t=a[j];
						a[j]=a[j+1];
						a[j+1]=t;
						exchange=1;//exchange has occured
					}
				}
			}
		}

		int main()
		{
			int a[10],n,i;

			printf("Enter number of elements : ");	
			scanf("%d",&n);

			printf("Enter the %d elements : ",n);	//input the elements
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);

			modBubbleSort(a,n);	//function call

			printf("The sorted array is : \t");	//print the sorted elements
			for(i=0;i<n;i++)
				printf("%d\t",a[i]);
			
			return 0;
		}

/*********************************************************************************
OUTPUT:
	
	TEST CASE 1:
			Enter number of elements : 6                                                                                                  
			Enter the 6 elements : 18  3  90  -4  -15  56                                                                                 
			The sorted array is :   -15     -4      3       18      56      90        
	
	TEST CASE 2:
			Enter number of elements : 3                                                                                                  
			Enter the 3 elements : 18  -6  2                                                                                              
			The sorted array is :   -6      2       18   
			
**********************************************************************************/

/*=====================================================================================================================================*/

/* 3. IMPLEMENTATION FOR SELECTION SORT*/
//CODE:
		#include <stdio.h>

		void selectionSort(int a[],int n)
		{
			int pass,j,min,t,pos,i;
			for(pass=1; pass<=n-1;pass++)
			{
				//code to find minimum in unsorted array pass-1 till n
				min = a[pass-1];//assume first element of the array as minimum 
				pos = pass-1; //minimum element is found at 'pos' position

				for( i = pass; i < n; i++) //iterate through other elements of array
				{
					if( a[i] < min) //if array element is smaller than current minimum
					{
						min = a[i]; //update minimum
						pos = i; //update 'pos'
					}
				}

				//exchange minimum element with element at pass-1
				a[pos] = a[pass-1]; 
				a[pass-1] = min;

			}
		}

		int main()
		{
			int a[10],n,i;

			printf("Enter number of elements : ");	
			scanf("%d",&n);

			printf("Enter the %d elements : ",n);	//input the elements
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);

			selectionSort(a,n);	//function call

			printf("The sorted array is : \t");	//print the sorted elements
			for(i=0;i<n;i++)
				printf("%d\t",a[i]);
			
			return 0;
		}

/*********************************************************************
OUTPUT:
	
	TEST CASE 1:
			Enter number of elements : 5                                                                                                  
			Enter the 5 elements : 78  90  -4  -15  43                                                                                    
			The sorted array is :   -15     -4      43      78      90      
	
	TEST CASE 2:
			Enter number of elements : 4                                                                                                  
			Enter the 4 elements : 20  11  -9  51                                                                                         
			The sorted array is :   -9      11      20      51 
			
**********************************************************************/

/*=====================================================================================================================================*/

/* 4. IMPLEMENTATION FOR INSERTION SORT*/
//CODE:
		#include<stdio.h>

		void insertionSort(int a[],int n)
		{
			int pass,j;
			for(pass=1;pass<n;pass++)
			{
				int x=a[pass];	//at a time one element is inserted in sorted array
				int j=pass-1;//indicates end index of sorted array
				while(j>=0)
				{
					if(x>a[j])		//if in proper order break and go for next pass
						break;
					else 			
					{
						a[j+1]=a[j];//else make place for the element by shifting the element
						j--;//go for next element in sorted array from backwards
					}
				}

				a[j+1]=x;	//insert the element at proper postion
			}
		}

		int main()
		{
			int a[10],n,i;

			printf("Enter number of elements : ");	
			scanf("%d",&n);

			printf("Enter the %d elements : ",n);	//input the elements
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);

			insertionSort(a,n);	//function call

			printf("The sorted array is : \t");	//print the sorted elements
			for(i=0;i<n;i++)
				printf("%d\t",a[i]);
			
			return 0;
		}

/*********************************************************************
OUTPUT:
	
	TEST CASE 1:
			Enter number of elements : 5                                                                                                  
			Enter the 5 elements : 89  54  -9  -6  -2                                                                                     
			The sorted array is :   -9      -6      -2      54      89 
	
	TEST CASE 2:
			Enter number of elements : 3                                                                                                  
			Enter the 3 elements : 57  -4  -9                                                                                             
			The sorted array is :   -9      -4      57  
			
**********************************************************************/

/*=====================================================================================================================================*/

/* 5. IMPLEMENTATION FOR MERGE SORT*/
//CODE:
		#include<stdio.h>
		void mergeList(int a[],int l1,int h1,int l2,int h2) //l1 - low index of LSA and h1 - high index of LSA
									   //l2 - low index of RSA and h2 - high index of RSA
		{
			int i=l1,j=l2;//i and j indicate lower bounds of two sub arrays
			int c[20];//dummy array
			int k=0;//indicates index in dummy array

			while(i<=h1 && j<=h2)
			{
				if(a[i] < a[j]) //if element from subarray 1 should be inserted first
				{
					c[k]=a[i];//insert element from subarray 1
					k++;	
					i++;//increment index of subarray 1
				}
				else
				{
					c[k]=a[j];//insert element from subarray 2
					j++;//increment index of subarray 2
					k++;
				}
			}
			while(i<=h1)		//insert remaining elements from subarray 1
			{	
				c[k]=a[i];
				i++;
				k++;
			}

			while(j<=h2)		//insert remaining elements from subarray 2
			{
				c[k]=a[j];
				j++;
				k++;
			}

			//now dummy array  (c) contains the merged and sorted list of subarray 1 and 2
			//to transfer the changes into actual array (a) copy c into a

			for(i=l1,j=0 ; i<=h2 ; i++,j++)
				a[i]=c[j];

		}

		void mergeSort(int a[],int l,int h)
		{
			if (l==h)
				return;
			//else
			int m=(l+h)/2;

			mergeSort(a,l,m);		//recursive call for subarray 1(first half) 
			mergeSort(a,m+1,h);	//recursive call for subarray 2(second half)
			mergeList(a,l,m,m+1,h);	//merging subarray 1 and 2
		}

		int main()
		{
			int a[10],n,i;

			printf("Enter number of elements : ");	
			scanf("%d",&n);

			printf("Enter the %d elements : ",n);	//input the elements
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);

			mergeSort(a,0,n-1);	//function call

			printf("The sorted array is : \t");	//print the sorted elements
			for(i=0;i<n;i++)
				printf("%d\t",a[i]);
			
			return 0;
		}
		
/*********************************************************************

OUTPUT:
	
	TEST CASE 1:
			Enter number of elements : 5                                                                                                    
			Enter the 5 elements : 78  56  34  90  -8                                                                                       
			The sorted array is :   -8      34      56      78      90

	TEST CASE 2:
			Enter number of elements : 4                                                                                                  
			Enter the 4 elements : 67  55  89  32                                                                                         
			The sorted array is :   32      55      67      89 
			
**********************************************************************/

/*=====================================================================================================================================*/

/* 6. IMPLEMENTATION FOR QUICK SORT*/
//CODE:
		#include <stdio.h>
		int partition(int a[],int low, int high)	//puts pivot at proper postion and returns that position
		{
			//after this method is executed, elements to ;left of pivot are smaller and to the right are greater
			int x=a[low];	//pivot
			int down = low;	
			int up = high;
			int t;
			while(down<up)		//until the boundaries are not crossed
			{
				while(a[down]<=x && down<high)	//if elements are smaller keep moving right(forward)
					down++;			//terminates when a smaller element is encountered
				
				while(a[up]>x && up>=low)	//if elements are greater keep moving left(backward)
					up--;			//terminates when a larger element is encountered
				
				if(down<up)		        //puts a smaller element at the down position 
				{
					//swap up and down elements
					t=a[down];
					a[down]=a[up];
					a[up]=t;
				}
			}

			//now pivot will occupy the position given by the end of the list of smaller elements (up)
			a[low]=a[up];
			a[up]=x;
			return up;
		}

		void quickSort(int a[],int low ,int high)
		{
			if(low<high)
			{
				int split=partition(a,low,high);	//after pivot element occupies proper position the array is split
				quickSort(a,low,split-1);			//recursive call for Left Sub Array
				quickSort(a,split+1,high);			//recursive call for Right Sub Array
			}
		}

		int main()
		{
			int a[10],n,i;

			printf("Enter number of elements : ");	
			scanf("%d",&n);

			printf("Enter the %d elements : ",n);	//input the elements
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);

			quickSort(a,0,n-1);	//function call
			
			printf("The sorted array is : \t");	//print the sorted elements
			for(i=0;i<n;i++)
				printf("%d\t",a[i]);
			
			return 0;
		}
		
/*********************************************************************

OUTPUT:
	
	TEST CASE 1:
			Enter number of elements : 5                                                                                                  
			Enter the 5 elements : 45  89  32  -9  -10                                                                                    
			The sorted array is :   -10     -9      32      45      89 
			
	TEST CASE 2:
			Enter number of elements : 5                                                                                                  
			Enter the 5 elements : 77  54  -9  90  10                                                                                     
			The sorted array is :   -9      10      54      77      90  
						
**********************************************************************/

/*=====================================================================================================================================*/