#include <iostream>

using namespace std;

struct Node {
    int data;
    Node(int data_) {
        data = data_;
        next = nullptr;
    }
    Node* next;
};

//position tinh tu 0
Node* insertNode(Node* head, int position, int data_) {
    Node* newNode = new Node(data_);
    if (head == nullptr) {
        head = newNode;
        return head;
    }
    Node* current = head, *previous = nullptr;
    int i = 0;
    while (current != nullptr) {
        if (i == position) {
            break;
        }
        previous = current;
        current = current->next;
        ++i;
    }
    previous->next = newNode;
    newNode->next = current;
    return head;
}

Node* deleteNode(Node* head, int position) {
    Node* current = head, *previous = nullptr;
    int i = 0;
    while (current != nullptr) {
        if (i == position) {
            break;
        }
        ++i;
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    return head;
}

void printNode(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        if (s == "insert") {
            int position, data;
            cin >> position >> data;
            head = insertNode(head, position, data);
        } else {
            int position;
            cin >> position;
            head = deleteNode(head, position);
        }
    }
    printNode(head);
}
