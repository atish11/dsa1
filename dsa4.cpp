



#include <iostream>
struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void Enqueue(int x) {
    Node* newnode = new Node;
    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
        rear->next = front;
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void Dequeue() {
    if (front == NULL && rear == NULL) {
        std::cout << "\nQueue is Empty";
    } else if (front == rear) {
        delete front;
        front = rear = NULL;
    } else {
        Node* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
    }
}

void Display() {
    Node* temp = front;

    std::cout << "The elements inside the queue are: ";

    if (front == NULL && rear == NULL) {
        std::cout << "\nQueue is empty";
    } else {
        while (temp->next != front) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << temp->data;
    }
}

int main() {
    int choice, value;

    do {
        std::cout << "\n\n*** Queue Menu ***";
        std::cout << "\n1. Enqueue";
        std::cout << "\n2. Dequeue";
        std::cout << "\n3. Display";
        std::cout << "\n4. Exit";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the value to enqueue: ";
                std::cin >> value;
                Enqueue(value);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                std::cout << "Exiting program...";
                break;
            default:
                std::cout << "Invalid choice! Please enter a valid option.";
        }
    } while (choice != 4);

    return 0;
}
