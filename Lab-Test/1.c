/*Implement a C program using a queue with a linked list to find and print the length of the longest consecutive sequence of 1s in the array.
Example
10
1 1 0 1 1 1 0 1 1 1
Output : 3*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
	int data;
	struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// Function to enqueue a node in the linked list
void enqueue(struct Node** front, struct Node** rear, int data) 
{
// Your Implementation

}

// Function to dequeue a node from the linked list
void dequeue(struct Node** front)
{
// Your implementation
}
// Function to find the length of the longest consecutive sequence of 1s
int findLongestConsecutiveOnes(int n, int* arr) 
{
// Your implementation


}

int main() {
	int n;

	// Input the number of elements in the binary array
	scanf("%d", &n);

	int *arr = malloc(n * sizeof(int));

	// Input the binary array
	for (int i = 0; i < n; i++) {
    	scanf("%d", &arr[i]);
	}

	// Find and print the length of the longest consecutive sequence of 1s
	int result = findLongestConsecutiveOnes(n, arr);
	printf("%d\n", result);

	// Free allocated memory
	free(arr);

	return 0;
}