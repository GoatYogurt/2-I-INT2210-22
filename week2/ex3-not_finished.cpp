#include <iostream>

using namespace std;

struct Node {
    int data;
    Node(int data_) {
        data = data_;
        prev = nullptr;
        next = nullptr;
    }
    Node* prev;
    Node* next;
};

Node* pushNode(Node* node) {
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

int count_triplets(Node* head) {
    int count = 0;
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
        if (current->prev != nullptr) {
            if (current->prev->data + current->data + current->next->data == 0) {
            count++;
            }
        }
    }
}

Node* readNumber(int n) {
    for (int i = 1; i <= n; ++i) {
        int data;
        cin >> data;
        Node* newNode = Node(data);
    }
}

int main() {
    int n;
    int [n];
    for (int i = 1; i <= n; ++i) {
        int data;
        cin >> data;
    }
}
