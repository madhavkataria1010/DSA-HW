/*Write a program to perform the basic operations of a stack such as push(), pop(), peek(), isFull(), isEmpty(). Assume stack is of size 100 integers. The program should take input of a given n number of integers and push them into the stack and then perform the operations in the order mentioned below.
Input Format:
	N 1, 2, 3, ..n integers
Output Format:
	Output of peek(), printWholeStack(), pop(), isFull(), and isEmpty() in a new line:
Example:
	Input: 5
        15 123 62 10 44
	Output: 
		44
		44 10 62 123 15
		44
		0 // isFull() returns 1 if full, 0 otherwise
		0 // isEmpty() returns 1 if empty, 0 otherwise
*/#include <stdio.h>

#define MX_SIZE 1000

typedef struct {
    int a[100];
    int top;
} Stack;

void initStack(Stack* s){
    s->top = -1;
}

int isFull(Stack* s) {
    return (s->top == 99);
}

int isEmpty(Stack* s) {
    return (s->top == -1);
}

int push(Stack* s, int data){
    if(isFull(s))
        return 0;
    s->a[++(s->top)] = data;
    return 1;
}

int pop(Stack *s) {
    if(isEmpty(s))
        return -1;
    return s->a[(s->top)--];
}

int peek(Stack *s) {
    if(isEmpty(s))
        return -1;
    return s->a[s->top];
}

// Print all elements in the stack and add a newline at the end
void printWholeStack(Stack* s){
    for (int i = s->top; i >= 0; i--){
        printf("%d", s->a[i]);
       // if(i > 0)
            printf(" ");
    }
    printf("\n");
}

int main(){
    int n, x;
    scanf("%d", &n);
    Stack s;
    initStack(&s);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        push(&s, x);
    }
    x = peek(&s);
    printf("%d\n", x);
    printWholeStack(&s);
    x = pop(&s);
    printf("%d\n", x);
    printf("%d\n", isFull(&s));
    printf("%d\n", isEmpty(&s));
    return 0;
}