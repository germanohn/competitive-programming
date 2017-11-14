#include<bits/stdc++.h>
using namespace std;

int s[SIZE];
int top;

void push(int x) {
    if (top == SIZE) {
        printf("Error: overflow\n");
        return;
    }
    
    s[top++] = x;
}

void pop() {
    if (!top) {
        printf("Error: No element to pop\n");
        return;
    }
    top--;
}

int top() {
    if (!top) {
        printf("Error: stack empty\n");
        return;
    }

    return s[top];
}

int isEmpty() {
    if (!top) return true;
    return false;
}

