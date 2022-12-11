#include <iostream>
#include <time.h>  // time()
using namespace std;
#define RND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
#define SIZE 10

void BubbleSort(int mas[]) { // Bubble sort
	for (int i = 0; i < SIZE; i++) {
		for (int j = SIZE - 1; j > 0; j--) { 
			if (mas[j] < mas[j - 1]) {
				swap(mas[j], mas[j - 1]); 
			}
		}
	}
}

void BrickSort(int mas[]) {
	// Simple exchange sort - "brick" sort
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			//if (mas[j] > mas[j + 1]) { // ascending
			if (mas[j] < mas[j + 1]) { // descending
				swap(mas[j], mas[j + 1]);
			}
		}
	}
}

void SelectionSort(int mas[]) { //Selection sort
	for (int i = 0; i < SIZE - 1; i++) {
		int min = i; //the smallest element is the first element (index 0)
		for (int j = i + 1; j < SIZE; j++) {
			if (mas[j] < mas[min]) {
				min = j; //min is now the smallest element
			}
		}
		swap(mas[i], mas[min]);
	}
}

void InsertionSort(int mas[]) { //Insertion sort
	for (int i = 1; i < SIZE; i++) {
		for (int j = i; j > 0; j--) {
			if (mas[j - 1] > mas[j]) {
				swap(mas[j - 1], mas[j]);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int mas[SIZE];
	for (int i = 0; i < SIZE; i++) {
		mas[i] = RND(1, 9); // [1;9] - random array filling
		cout << mas[i] << " ";
	}
	cout << endl;
	InsertionSort(mas);
	// sort result output
	cout << "Sorted array:\n";
	for (int i = 0; i < SIZE; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;

	cin.get(); cin.get();
}
