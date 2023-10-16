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

void printList(No *top) {
    while (top) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

void removeMeio(No *&top) {
    if (!top)
        return;

    No *slow = top;
    No *fast = top;
    No *prev = NULL;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev) {
        prev->next = slow->next;
        delete slow;
    } else {
        pop(top);
    }
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

    removeMeio(top);

    cout << "Pilha com o elemento do meio removido: ";
    printList(top);

    return 0;
}






