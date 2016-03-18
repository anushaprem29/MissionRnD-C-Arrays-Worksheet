/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include<string.h>
struct student {
	char name[10];
	int score;
};
void swap(struct student *st1, struct student *st2){

	struct student st = *st1;
	*st1 = *st2;
	*st2 = st;

}


void sort1(struct student * arr, int first, int last){
	int iter1, iter2, pivot;
	if (first < last){
		pivot = first;
		iter1 = first;
		iter2 = last;
		while (iter1 < iter2){
			while (arr[iter1].score >= arr[pivot].score && iter1 < last)
				iter1++;
			while (arr[iter2].score < arr[pivot].score && iter2>0)
				iter2--;
			if (iter1 < iter2){
				swap(&arr[iter1], &arr[iter2]);
			}
		}
		swap(&arr[pivot], &arr[iter2]);

	}
}
void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len<0) return NULL;
	sort1(students, 0, len - 1);
}
