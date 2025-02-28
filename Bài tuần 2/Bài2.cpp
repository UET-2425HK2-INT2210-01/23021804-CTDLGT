#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}
    
    void insert(int pos, int val) {
        Node* newNode = new Node(val);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void remove(int pos) {
        if (head == nullptr) return;
        Node* temp = head;
        if (pos == 0) {
            head = head->next;
            delete temp;
            return;
        }
        Node* prev = nullptr;
        for (int i = 0; temp != nullptr && i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return;
        prev->next = temp->next;
        delete temp;
    }
    
    void print() {
        Node* temp = head;
        bool first = true;
        while (temp) {
            if (!first) cout << " ";
            cout << temp->data;
            first = false;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList linkedList;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "insert") {
            int p, x;
            cin >> p >> x;
            linkedList.insert(p, x);
        } 
        else if (operation == "delete") {
            int p;
            cin >> p;
            linkedList.remove(p);
        }
    }
    linkedList.print();
    
    return 0;
}
