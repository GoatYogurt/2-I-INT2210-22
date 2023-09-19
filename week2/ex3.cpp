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

int count_triplets(Node* head) {
    int count = 0;
    Node* current = head;
    current = current->next;
    while (current->next != nullptr) {
        if (current->prev->data + current->data + current->next->data == 0) {
        count++;
        }
        current = current->next;
    }
    return count;
}

Node* pushNode(Node* head, Node* node) {
    if (head == nullptr) {
        head = node;
    } else if (head->next == nullptr) {
        head->next = node;
        node->prev = head;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = node;
        node->prev = current;
    }
    return head;
}

Node* readNumber(Node* head, int n) {
    for (int i = 1; i <= n; ++i) {
        int data;
        cin >> data;
        Node* newNode = new Node(data);
        head = pushNode(head, newNode);
    }
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
    head = readNumber(head, n);
    cout << count_triplets(head);
}
