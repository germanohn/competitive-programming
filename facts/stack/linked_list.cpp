#include<bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int val;
        Node* next;
};

class Stack {
    private:
        Node* head = NULL;

    public:
        void push(int x) {
            Node* no = new Node;
            no->val = x;
            no->next = head;
            head = no;
        }

        void pop() {
            if (head == NULL) {
                printf("Error: stack empty\n");
                return;
            }

            head = head->next;
        }

        int top() {
            if (head == NULL) {
                throw "Error: stack empty\n";
            }

            return head->val;
        }
};

int main() {
    Stack S;
    char str[10];
    int x;
    while (scanf(" %s", str) != EOF) {
        if (strcmp(str, "push") == 0) { 
            scanf(" %d", &x);
            S.push(x);
        } else if (strcmp(str, "pop") == 0) {
            S.pop();
        } else {
            printf("%d\n", S.top());
        }
    }
}
