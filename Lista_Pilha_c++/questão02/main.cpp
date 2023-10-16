#include <iostream>

using namespace std;

struct No {
    int data;
    No *next;

    No(int value) : data(value), next(NULL) {}
};

void push(No *&top, int value) {
    No *elemento = new No(value);
    elemento->next = top;
    top = elemento;
}

void pop(No *&top) {
    if (top) {
        No *temp = top;
        top = top->next;
        delete temp;
    }
}

bool isEmpty(No *top) {
    return top == NULL;
}

void reverseStack(No *&top) {
    No *prev = NULL;
    No *current = top;
    No *nextNode;

    while (current) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    top = prev;
}

void printList(No *top) {
    while (top) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

int main() {
    No *top = NULL;

    push(top, 1);
    push(top, 2);
    push(top, 3);
    push(top, 4);
    push(top, 5);

    cout << "Pilha original: ";
    printList(top);

    reverseStack(top);

    cout << "Pilha revertida: ";
    printList(top);

    while (!isEmpty(top)) {
        pop(top);
    }

    return 0;
}


