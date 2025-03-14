#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr){}
};

class LinkedList{
public:
    Node* head;
    int sz;
    LinkedList() : head(nullptr), sz(0){}
    
    void append(int k){
        Node* newNode = new Node(k);
        if (head == nullptr) {
            head = newNode;
            sz++;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        sz++;
        return;
    }
    
    void search( int k) {
        Node* temp = head;
        int posi = 0;
        while (temp != nullptr){
            if (temp->data == k){
                cout << posi << endl;
                return;
            }
            temp = temp->next;
            posi ++;
        }
        cout << "NO";
    }
    
    void reverse() {
        Node* nxt = nullptr;
        Node* cur = head;
        Node* pre = nullptr;
        while (cur != nullptr){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        head = pre;
        Node* temp = head;
        while (temp != nullptr){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        return;
    }
    
};

int main(){
    int n, k;
    cin >> n;
    string command;
    LinkedList list;
    for (int i = 0; i < n; i++){
        cin >> command;
        if (command == "reverse"){
            list.reverse();
        } else   if (command == "append") {
            cin >> k;
            list.append(k);
        } else if (command == "search"){
            cin >> k;
            list.search(k);
        }
    }
}