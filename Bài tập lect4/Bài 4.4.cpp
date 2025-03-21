
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const int TABLE_SIZE = 10007; 
const int MAX_NAME_LENGTH = 100;
const int MAX_CLASS_LENGTH = 30;

struct Student {
    int ID;
    string name;
    string class_name;
    Student* next;
    Student(int id, string n, string c) : ID(id), name(n), class_name(c), next(nullptr) {}
};

class StudentManager {
public:
    vector<Student*> hashTable;
    int hashFunction(int ID) {
        return ID % TABLE_SIZE;
    }
    
    StudentManager() : hashTable(TABLE_SIZE, nullptr) {}
    
    void insert(int ID, const string& name, const string& class_name)
    {
        int index = hashFunction(ID);
        Student* newStudent = new Student(ID, name, class_name);
        
        if (!hashTable[index]) {
            hashTable[index] = newStudent;
            return;
        }
        
        Student* current = hashTable[index];
        while (current) {
            if (current->ID == ID) {
                current->name = name;
                current->class_name = class_name;
                delete newStudent;
                return;
            }
            if (!current->next) break;
            current = current->next;
        }
        current->next = newStudent;
    }
    
    void remove(int ID)
    {
        int index = hashFunction(ID);
        Student* current = hashTable[index];
        Student* prev = nullptr;
        
        while (current) {
            if (current->ID == ID)
            {
                if (prev) {
                    prev->next = current->next;
                } else {
                    hashTable[index] = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    
    string infor(int ID) {
        int index = hashFunction(ID);
        Student* current = hashTable[index];
        
        while (current) {
            if (current->ID == ID) {
                return current->name + "," + current->class_name;
            }
            current = current->next;
        }
        return "NA,NA";
    }
};

int main() {
    StudentManager manager;
    string line;
    
    while (getline(cin, line)) {
        stringstream ss(line);
        string command;
        ss >> command;
        
        if (command == "Insert") {
            int ID;
            string name, class_name;
            ss >> ID;
            ss.ignore();
            getline(ss, name, ' ');
            getline(ss, class_name);
            manager.insert(ID, name, class_name);
        } 
        else if (command == "Delete") {
            int ID;
            ss >> ID;
            manager.remove(ID);
        } 
        else if (command == "Infor") {
            int ID;
            ss >> ID;
            cout << manager.infor(ID) << endl;
        }
    }
    
    return 0;
}  