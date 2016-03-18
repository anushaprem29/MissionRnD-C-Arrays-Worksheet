/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int pos[2], iter, iter2 = 0;
	if (Arr == NULL || len < 0)	return  NULL;
	//find the two wrong positions.
	for (iter = 0; iter < len - 1; iter++){
		if (Arr[iter]>Arr[iter + 1]){
			pos[iter2] = iter + (iter2++);
		}
	}
	//swapping
	if (pos[0] != pos[1]){
		iter = Arr[pos[0]];
		Arr[pos[0]] = Arr[pos[1]];
		Arr[pos[1]] = iter;
	}
	return Arr;
}