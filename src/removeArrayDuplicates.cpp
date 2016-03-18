/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
void sort(int * arr, int first, int last){
	int iter1, iter2, pivot, temp;
	if (first < last){
		pivot = first;
		iter1 = first;
		iter2 = last;
		while (iter1 < iter2){
			while (arr[iter1] <= arr[pivot] && iter1<last)
				iter1++;
			while (arr[iter2]>arr[pivot])
				iter2--;
			if (iter1<iter2){
				temp = arr[iter2];
				arr[iter2] = arr[iter1];
				arr[iter1] = temp;
			}
		}
		temp = arr[iter2];
		arr[iter2] = arr[pivot];
		arr[pivot] = temp;
		sort(arr, first, iter2 - 1);
		sort(arr, iter2 + 1, last);
	}
}

int removeArrayDuplicates(int *Arr, int len)
{
	int iter, shift = 0, extra = 0, count = 0;
	if (Arr == NULL || len<0)	return -1;
	sort(Arr, 0, len - 1);
	for (iter = 1; iter < len; iter++){
		if (Arr[iter] == Arr[iter - 1]){
			count++;
			shift++;
		}
		else{
			if (shift != 0){
				Arr[iter - shift - extra] = Arr[iter];
				extra++;
				shift = 0;
			}
		}
	}
	return len - count;
}