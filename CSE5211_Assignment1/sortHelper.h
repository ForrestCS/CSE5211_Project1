/**
sortHelper.h
This class file contains various declarations of functions used for the implementation
of the insertion and merge sort algorithmns.

@author Charles Forrest
@version 1.0 01/32/2015
*/

#ifndef SORTHELPER_H
#define SORTHELPER_H

#include <iostream>
#include <stdio.h>
#include "Windows.h"

/* @brief Function to perform merge sort */
void InsertionSort(int arrayToSort[], int arraySize);

/* @brief Function to perform merge sorting */
void MergeSort(int arrayToSort[], int arraySize);

/* @brief Function to perform recursive merge */
void Merge(int *leftArray, int leftSize, int *rightArray, int rightSize, int* arrayToSort);

/* @brief Function to print out the given array */
void PrintArray(int arrayToPrint[], int arraySize);

#endif