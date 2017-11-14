#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node() {}
    Node(int x) : val(x), next(NULL) {}
};

void insert(Node* p, int x) {
    while (p->next != NULL) {
        p = p->next;
    }

    Node* novo = new Node();
    novo->val = x;
    novo->next = NULL;
    p->next = novo;
}

int main() {
    int sizeA, sizeB;
    scanf(" %d", &sizeA);

    Node* A = new Node();
    for (int i = 0; i < sizeA; i++) {
        int x;
        scanf(" %d", &x);
        insert(A, x);
    }

    scanf(" %d", &sizeB);

    Node* B = new Node();
    for (int i = 0; i < sizeB; i++) {
        int x;
        scanf(" %d", &x);
        insert(B, x);
    }

    
    Node* p, q;
    
    p = A;
    while (p->next != NULL) {
        sizeA++;
        p = p->next;
    }
    
    q = B;
    while (q->next != NULL) {
        sizeB++;
        q = q->next;
    }
    
    if (sizeA < sizeB) {
        p = B, q = A;
    } else {
        p = A, q = B;
    }
    
    printf("sizeA %d sizeB %d\n", sizeA, sizeB); 
       
    int cont = 0;
    while (p->next != NULL && abs(sizeA - sizeB) > cont) {
        p = p->next;
        cont++;
    }
    
    while (p->next != NULL && p->next != q->next) {
        p = p->next;
        q = q->next;
    }
}
