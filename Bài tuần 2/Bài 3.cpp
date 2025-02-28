#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    
    int count_triplets() {
        if (!head || !head->next || !head->next->next) return 0;
        int count = 0;
        Node* current = head->next; 
        while (current->next) {
            if (current->prev->data + current->data + current->next->data == 0) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    DoublyLinkedList dll;
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        dll.append(value);
    }
    
    cout << dll.count_triplets() << endl;
    
    return 0;
}