/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void swap2(struct student *st1, struct student *st2){
	struct student st = *st1;
	*st1 = *st2;
	*st2 = st;
}


void sort2(struct student * arr, int first, int last){
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
				swap2(&arr[iter1], &arr[iter2]);
			}
		}
		swap2(&arr[iter2], &arr[pivot]);
		sort2(arr, first, iter2 - 1);
		sort2(arr, iter2 + 1, last);
	}
}
struct student ** topKStudents(struct student *students, int len, int K) {
	if (students == NULL || K <= 0) return NULL;
	struct student **topList = (struct student**)calloc(K, sizeof(struct student));
	sort2(students, 0, len - 1);
	while (K--){
		topList[K] = &students[K];
	}
	return topList;
}