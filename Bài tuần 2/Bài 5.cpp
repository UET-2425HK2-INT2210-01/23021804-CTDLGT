#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    
    void pop() {
        if (!top) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    
    void print() {
        Node* temp = top;
        bool first = true;
        while (temp) {
            if (!first) cout << " ";
            cout << temp->data;
            temp = temp->next;
            first = false;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Stack myStack;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "push") {
            int x;
            cin >> x;
            myStack.push(x);
        } else if (operation == "pop") {
            myStack.pop();
        }
    }
    
    myStack.print();
    
    return 0;
}

