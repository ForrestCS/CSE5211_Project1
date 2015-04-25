/**
Insertion Sort & Merge Sort Program
main.cpp

1) Implement insertion sort and merge sort. To artificially increase I/O time, employ file I/O.

2) Time the algorithmns for increasing file sizes

3) Fine file size where merge running time < insertion running time

@author Charles Forrest
@version 1.0 01/31/2015
*/

#include <time.h>
#include "sortHelper.h"

// 1 to print arrays 0 otherwise
#define TEST_OUTPUT 1

int main()
{
	int inputLength = 0, trendStartLength = 0, trendCounter = 0;
	int *unsortedArray = NULL;
	int *tempArray = NULL;
	bool trendStarted = false, mainLoop = true;

	clock_t start, exit;
	double timeOfIns;
	double timeOfMer;
	double startTime;
	double endTime;

	FILE *inputFile = NULL;
	FILE *outputFile = NULL;

	char tempString[255] = "";

	fopen_s(&inputFile, "integerArray.txt", "r");
	fopen_s(&outputFile, "SortingOutput.txt", "w+");

	if (outputFile == NULL || inputFile == NULL)
	{
		printf("Error in File I/O");
	}

	printf("Array Size? \n");
	scanf_s("%d", &inputLength);

	if (inputLength < 0 && inputLength > INT_MAX)
	{
		printf("Invalid Input\n");
	}

	while (mainLoop == true)
	{
		Sleep(5000);

		//Print current size to screen
		printf("Current Array Length:%d\n", inputLength);
		fprintf(outputFile, "Current Array Length : %d\n", inputLength);
		fflush(outputFile);

		unsortedArray = (int*)malloc(inputLength * sizeof(int));
		tempArray = (int*)malloc(inputLength * sizeof(int));

		//get the unsorted array here - flush after each read
		for (int ii = 0; ii < inputLength; ii++)
		{
			if ((fgets(tempString, sizeof(tempString), inputFile) != NULL))
			{
				unsortedArray[ii] = atoi(tempString);
			}
			else
			{
				printf("End of input array file has been reached");
				break;
			}
		}


#if TEST_OUTPUT
		printf("Start Array: \n");
		PrintArray(unsortedArray, inputLength);
#endif

		//copy the unsorted array to temp for running merge sort also
		for (int ii = 0; ii < inputLength; ii++)
		{
			tempArray[ii] = unsortedArray[ii];
		}

		start = clock();
		startTime = (double)start;
		InsertionSort(unsortedArray, inputLength);		
		exit = clock();
		endTime = (double)exit;

		timeOfIns = ((double)(endTime - startTime) / CLOCKS_PER_SEC);

		//write to screen and file
		printf("Insertion finished in %lf \n", timeOfIns);
		fprintf(outputFile, "Insertion finished in %lf \n", timeOfIns);
		fflush(outputFile);

#if TEST_OUTPUT
		printf("Array after Insertion Sort: \n");
		PrintArray(unsortedArray, inputLength);
#endif

		//copy back the original array for merge sort next
		for (int ii = 0; ii < inputLength; ii++)
		{
			unsortedArray[ii] = tempArray[ii];
		}

		start = clock();
		startTime = (double)start;
		MergeSort(unsortedArray, inputLength);
		exit = clock();
		endTime = (double)exit;

		timeOfMer = ((double)(endTime - startTime) / CLOCKS_PER_SEC);
		printf("Merge Sort finished in %lf \n", timeOfMer);
		fprintf(outputFile, "Merge Sort finished in %lf \n", timeOfMer);
		fflush(outputFile);

#if TEST_OUTPUT
		printf("Array after Merge Sort: \n");
		PrintArray(unsortedArray, inputLength);
#endif

		double timeDifference = timeOfIns - timeOfMer;
		printf("Difference of MergeSort and Insertion: %lf \n\n", timeDifference);
		fprintf(outputFile, "Difference of MergeSort and Insertion: %lf \n\n", timeDifference);
		fflush(outputFile);

		if (timeDifference >= .025)
		{
			trendStarted = true;
			trendStartLength = inputLength;
			trendCounter++;

			if (trendCounter >= 20)
			{
				//screen output
				printf("Merge Has Been Faster for Twenty Consecutive Times \n");
				printf("Start of Merge being faster was: %d\n", trendStartLength);

				//file output & flush
				fprintf(outputFile, "Merge Has Been Faster for Twenty Consecutive Times \n");
				//fflush(outputFile);
				fprintf(outputFile, "Start of Merge being faster was : %d\n", trendStartLength);
				//fflush(outputFile);

				mainLoop = false;
			}
		}
		else
		{
			trendStarted = false;
			trendCounter = 0;
		}

		inputLength++;
	}

	printf("Program Halted\n");
	delete(unsortedArray);
	delete(tempArray);
	fclose(inputFile);
	fclose(outputFile);
	system("PAUSE");
}