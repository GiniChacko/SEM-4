/***************************************************************************************************************
   NAME : GINI CHACKO
   CLASS : SE COMPS B
   BATCH : B
   ROLL NO : 8942
   LAB ASSIGNMENT: 7 
				   Implementation of 1. Naive string Matching
								     2. KMP algorithm
									 3. Rabin Karp algorithm
   
****************************************************************************************************************/

//1. IMPLEMENTATION OF NAIVE STRING MATCHING

//CODE:

	#include <stdio.h>
	#include <string.h>
	 
	void search(char* pat, char* txt)
	{
		int M = strlen(pat);
		int N = strlen(txt);
	 
		/* A loop to slide pat[] one by one */
		for (int i = 0; i <= N - M; i++) {
			int j;
	 
			/* For current index i, check for pattern match */
			for (j = 0; j < M; j++)
				if (txt[i + j] != pat[j])
					break;
	 
			if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
				printf("Pattern found at index : %d \n", i);
		}
	}
	 
	int main()
	{
		char txt[] = "IGINIMONGINISSGINIS";
		char pat[] = "GINI";
		printf("**********NAIVE STRING MATCHING ALGORITHM**********\n\n");
		printf("TEXT : IGINIMONGINISSGINIS\n");
		printf("PATTERN : GINI\n");
		printf("\n----------------------------------------------------\n\n");
		search(pat, txt);
		printf("\n----------------------------------------------------\n\n");
		return 0;
	}

/**************************************************************

OUTPUT:

	**********NAIVE STRING MATCHING ALGORITHM**********

	TEXT : IGINIMONGINISSGINIS
	PATTERN : GINI

	----------------------------------------------------

	Pattern found at index : 1 
	Pattern found at index : 8 
	Pattern found at index : 14 

	----------------------------------------------------

***************************************************************/

/*=============================================================================================================*/

//2. MPLEMENTATION OF KMP ALGORITHM

//CODE:

	#include <stdio.h>
	#include <string.h>
	  
	void computeLPSArray(char* pat, int M, int* lps);
	  
	// Prints occurrences of txt[] in pat[]
	void KMPSearch(char* pat, char* txt)
	{
		int M = strlen(pat);
		int N = strlen(txt);
	  
		// create lps[] that will hold the longest prefix suffix
		// values for pattern
		int lps[M];
	  
		// Preprocess the pattern (calculate lps[] array)
		computeLPSArray(pat, M, lps);
	  
		int i = 0; // index for txt[]
		int j = 0; // index for pat[]
		while (i < N) {
			if (pat[j] == txt[i]) {
				j++;
				i++;
			}
	  
			if (j == M) {
				printf("Pattern found at index : %d \n", i - j);
				j = lps[j - 1];
			}
	  
			// mismatch after j matches
			else if (i < N && pat[j] != txt[i]) {
				// Do not match lps[0..lps[j-1]] characters,
				// they will match anyway
				if (j != 0)
					j = lps[j - 1];
				else
					i = i + 1;
			}
		}
	}
	  
	// Fills lps[] for given patttern pat[0..M-1]
	void computeLPSArray(char* pat, int M, int* lps)
	{
		// length of the previous longest prefix suffix
		int len = 0;
	  
		lps[0] = 0; // lps[0] is always 0
	  
		// the loop calculates lps[i] for i = 1 to M-1
		int i = 1;
		while (i < M) {
			if (pat[i] == pat[len]) {
				len++;
				lps[i] = len;
				i++;
			}
			else // (pat[i] != pat[len])
			{
			  
				if (len != 0) {
					len = lps[len - 1];
	  
				}
				else // if (len == 0)
				{
					lps[i] = 0;
					i++;
				}
			}
		}
	}
	  
	int main()
	{
		char txt[] = "GGGGIGGGGGIIIGGGGI";
		char pat[] = "GGGI";
		printf("**********KNUTH MORRIS PRATT ALGORITHM**********\n\n");
		printf("TEXT : GGGGIGGGGGIIIGGGGI\n");
		printf("PATTERN : GGGI\n");
		printf("\n----------------------------------------------------\n\n");
		KMPSearch(pat, txt);
		printf("\n----------------------------------------------------\n\n");
		return 0;
	}

/**************************************************************

OUTPUT:

	**********KNUTH MORRIS PRATT ALGORITHM**********

	TEXT : GGGGIGGGGGIIIGGGGI
	PATTERN : GGGI

	----------------------------------------------------

	Pattern found at index : 1 
	Pattern found at index : 7 
	Pattern found at index : 14 

	----------------------------------------------------

***************************************************************/

/*=============================================================================================================*/

//3. IMPLEMENTATION OF RABIN KRAP ALGORITHM

//CODE:

	#include <stdio.h>
	#include <string.h>

	#define d 10

	void rabinKarp(char pattern[], char text[], int q) {
	  int m = strlen(pattern);
	  int n = strlen(text);
	  int i, j;
	  int p = 0;
	  int t = 0;
	  int h = 1;

	  for (i = 0; i < m - 1; i++)
		h = (h * d) % q;

	  // Calculate hash value for pattern and text
	  for (i = 0; i < m; i++) {
		p = (d * p + pattern[i]) % q;
		t = (d * t + text[i]) % q;
	  }

	  // Find the match
	  for (i = 0; i <= n - m; i++) {
		if (p == t) {
		  for (j = 0; j < m; j++) {
			if (text[i + j] != pattern[j])
			  break;
		  }

		  if (j == m)
			printf("Pattern found at index : %d \n", i + 1);
		}
		 
		if (i < n - m) {
		  t = (d * (t - text[i] * h) + text[i + m]) % q;

		  if (t < 0)
			t = (t + q);
		}
	  }
	}

	int main() {
	  char text[] = "GINIMONGINIS";
	  char pattern[] = "GINI";
	  int q = 13;
	  printf("**********RABIN KRAP ALGORITHM**********\n\n");
	  printf("TEXT : GINIMONGINIS\n");
	  printf("PATTERN : GINI\n");
	  printf("\n----------------------------------------------------\n\n");
	  rabinKarp(pattern, text, q);
	  printf("\n----------------------------------------------------\n");
	}

/**************************************************************

OUTPUT:

	**********RABIN KRAP ALGORITHM**********

	TEXT : GINIMONGINIS
	PATTERN : GINI

	----------------------------------------------------

	Pattern found at index : 1 
	Pattern found at index : 8 

	----------------------------------------------------

***************************************************************/

/*=============================================================================================================*/