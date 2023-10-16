#include <iostream>

using namespace std;

class FixedSizeStack {
	int *data;
    int max_size;
    int top_index;
    
public:
    FixedSizeStack(int maxSize) : max_size(maxSize), top_index(-1) {
        data = new int[max_size];
    }

    bool isEmpty() {
        return top_index == -1;
    }

    bool isFull() {
        return top_index == max_size - 1;
    }

    void push(int value) {
        data[++top_index] = value;
    }

    void pop() {
        --top_index;
    }

    int top() {
        return data[top_index];
    }
};

int main() {
    FixedSizeStack stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    //stack.push(5);
    
    if (stack.isFull()) {
        cout << "A pilha esta cheia." << endl;
    }
    
    if (stack.isEmpty()) {
        cout << "A pilha esta vazia." << endl;
    }

    cout << "Topo da pilha: " << stack.top() << endl;
    stack.pop();
    cout << "Topo apos o pop: " << stack.top() << endl;
    stack.isFull();
    

    return 0;
}



