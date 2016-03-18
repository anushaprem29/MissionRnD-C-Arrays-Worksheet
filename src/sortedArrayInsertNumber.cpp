/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>
void shift(int *arr, int first, int last){
	while (first < last){
		arr[last] = arr[--last];
	}

}
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int iter;
	if (Arr == NULL || len<0) return NULL;
	Arr = (int *)realloc(Arr, len * sizeof(int));
	Arr[len] = num;
	if (num < Arr[0]){
		shift(Arr, 1, len);
		Arr[0] = num;
		return Arr;
	}
	for (iter = 1; iter < len; iter++){
		if (Arr[iter - 1] < num && Arr[iter] >= num){
			shift(Arr, iter, len);
			Arr[iter] = num;
			break;
		}
	}
	return Arr;
}