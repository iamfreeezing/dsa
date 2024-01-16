#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

};

void insertAtHead(Node* &head, int data) {

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;

}

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;

}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    Node* temp = new Node(data);
    if (position==1) {
        insertAtHead(head, data);
        }

    else {
        Node* current = head;
        int currPos = 1;

        while(currPos<position - 1) {
                current = current->next;
                currPos++;
        }


        Node* temp = new Node(data);

        if (current->next==NULL) {
            insertAtTail(tail, data);
            return;
        }
        temp->next = current->next;
        current->next = temp;
        
    }

}

void printLL(Node* head, Node* tail) {
    Node* current = head;
    while(current->next!=NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << endl;

    cout << "New head is: " << head->data << endl;
    cout << "New tail is: " << tail->data << endl;

}

void deleteNode(Node* &head, Node* &tail, int position) {
    if (position==1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    int currPos = 1;
    Node* current = head;
    while(currPos<position-1) {
        current = current->next;
        currPos++;
    }
    Node* temp = current->next;
    if (temp->next==NULL) {
        tail = current;
        current->next = NULL;
        delete temp;
    }
    else {
        current->next = current->next->next;
        temp->next = NULL;
        delete temp;
    }
    
}

int main() {

    Node* node1 = new Node(2);
    Node* head = node1;
    Node* tail = node1;

    printLL(head, tail);

    insertAtHead(head, 1);
    insertAtTail(tail, 4);
    insertAtPosition(head, tail, 3, 3);
    insertAtTail(tail, 5);


    printLL(head, tail);

    deleteNode(head, tail, 1);
    printLL(head, tail);
    deleteNode(head, tail, 4);
    printLL(head, tail);
    


}