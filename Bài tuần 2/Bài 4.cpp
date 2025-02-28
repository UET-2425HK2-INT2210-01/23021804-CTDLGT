#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (!rear) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    
    void dequeue() {
        if (!front) return;
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }
    
    void print() {
        Node* temp = front;
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
    Queue myQueue;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "enqueue") {
            int x;
            cin >> x;
            myQueue.enqueue(x);
        } else if (operation == "dequeue") {
            myQueue.dequeue();
        }
    }
    
    myQueue.print();
    
    return 0;
}
