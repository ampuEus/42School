#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef LEN
# define LEN 100
#endif

int random_nbr_generator(void)
{
	return (rand() % 400); /* Example: 201 - 100 -> range from -100 to 100 */
}

void semi_sort(int arr[], int len) {
	int temp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				if (rand() % 2 == 0) { // Randomly swap some values
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
}

void reverse_semi_sort(int arr[], int len) {
	int temp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				if (rand() % 2 == 0) { // Randomly swap some values
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
}

void sort(int arr[], int len) {
	int temp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void reverse_sort(int arr[], int len) {
	int temp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {
	int arr[LEN];

	srand(time(NULL));
	for (int i = 0; i < LEN; i++) {
		int nbr = random_nbr_generator();
		while (1) {
			int repeat = 0;
			for (int j = 0; j < i; j++) {
				if (arr[j] == nbr) {
					repeat = 1;
					break;
				}
			}
			if (!repeat) {
				arr[i] = nbr;
				break;
			}
			nbr = random_nbr_generator();
		}
	}
	//semi_sort(arr, LEN);
	//reverse_semi_sort(arr, LEN);
	//sort(arr, LEN);
	//reverse_sort(arr, LEN);
	for (int i = 0; i < LEN; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
