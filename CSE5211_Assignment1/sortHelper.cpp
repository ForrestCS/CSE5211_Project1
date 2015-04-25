/**
sortHelper.cpp
This class file contains various functions used for the implementation of the
insertion and merge sort algorithmns.

@author Charles Forrest
@version 1.0 01/31/2015
*/

#include "sortHelper.h"

/*
* This function calls an insertion sort of the given array
*
* @param arrayToSort input as reference array to sort
* @param arraySize  size of the given array
* @return N/A
*/
void InsertionSort(int arrayToSort[], int arraySize)
{
	//loop through each element
	for (int jj = 1; jj < arraySize; jj++)
	{
		int key = arrayToSort[jj];
		int ii = jj - 1;

		//compare to all the previous elements
		while (ii >= 0 && arrayToSort[ii] > key)
		{
			arrayToSort[ii + 1] = arrayToSort[ii];
			ii = ii - 1;
		}

		arrayToSort[ii + 1] = key;
	}
}

/*
* This function calls a merge sort of the given array
*
* @param arrayToSort input as reference array to sort
* @param arraySize  size of the given array
* @return N/A
*/
void MergeSort(int arrayToSort[], int arraySize)
{
	int ii;
	int *leftArray, *rightArray;
	int leftSize, rightSize;

	//if we are at the one base case, return and continue
	if (arraySize < 2)
	{
		return;
	}

	//allocate two arrays of half the size of the original
	leftSize = arraySize / 2;
	rightSize = arraySize - leftSize;
 	leftArray = (int*)malloc(sizeof(int) * (leftSize + 1));
	rightArray = (int*)malloc(sizeof(int) * (rightSize + 1));

	//assign the two new arrays
	for (ii = 0; ii < leftSize; ii++)
	{
		leftArray[ii] = arrayToSort[ii];
	}
	for (ii = 0; ii < rightSize; ii++)
	{
		rightArray[ii] = arrayToSort[ii + leftSize];
	}

	//set the last element to max to avoid a bad value
	leftArray[leftSize] = INT_MAX;
	rightArray[rightSize] = INT_MAX;

	//recursive call with new arrays
	MergeSort(leftArray, leftSize);
	MergeSort(rightArray, rightSize);

	//call merge - starts after base case
	Merge(leftArray, leftSize, rightArray, rightSize, arrayToSort);

	//free allocated memory
	free(leftArray);
	free(rightArray);
}

/*
* This function calls a recursive merge of two given arrays left and right side
*
* @param leftArray left half of the previous array in recursion
* @param leftSize  size of the left array
* @param rightArray  right half of the previous array in recursion
* @param rightSize  size of the right array
* @param arrayToSort  resulting array needed to be sorted
* @return N/A
*/
void Merge(int *leftArray, int leftSize, int *rightArray, int rightSize, int* arrayToSort)
{
	int ii = 0, jj = 0;

	//loop through to build the new sorted array
	for (int kk = 0; kk < (leftSize + rightSize); kk++)
	{
		//compare each and pick the lowest
		if (leftArray[ii] <= rightArray[jj] && ii < leftSize)
		{
			arrayToSort[kk] = leftArray[ii];
			ii++;
		}
		else
		{
			arrayToSort[kk] = rightArray[jj];
			jj++;
		}
	}
}

/*
* This function calls a recursive merge of two given arrays left and right side
*
* @param arrayToPrint array to print
* @param arraySize size of the array to print
* @return N/A
*/
void PrintArray(int arrayToPrint[], int arraySize)
{
	for (int ii = 0; ii < arraySize; ii++)
	{
		printf("%d ", arrayToPrint[ii]);
	}

	printf("\n");
}