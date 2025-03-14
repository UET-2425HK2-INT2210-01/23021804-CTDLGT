#include <iostream>
using namespace std;

struct Node {
    int value, priority;
    Node* next;
    Node* prev;
    Node(int v, int p) : value(v), priority(p), next(nullptr), prev(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;
public:
    PriorityQueue() : head(nullptr) {}

    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);
        
        if (!head || head->priority < priority) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next && current->next->priority >= priority)
            current = current->next;
        
        newNode->next = current->next;
        if (current->next) 
            current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }

    void dequeue() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
        }
    }

    void printQueue() {
        Node* current = head;
        while (current) {
            cout << "(" << current->value << ", " << current->priority << "); ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    PriorityQueue pq;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
    }

    pq.printQueue();
    return 0;
}