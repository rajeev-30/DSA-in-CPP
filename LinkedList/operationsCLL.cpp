#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning of the circular linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode; // Point to itself if the list is empty
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newNode; // Make the last node point to the new node
            newNode->next = head; // Make the new node point to the head
        }
        head = newNode; // Update the head to the new node
    }

    // Function to insert a node at the end of the circular linked list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode; // Point to itself if the list is empty
            head = newNode;
        } else {
            Node* last = head;
            while (last->next != head) {       
                last = last->next;
            }
            last->next = newNode; // Make the last node point to the new node
            newNode->next = head; // Make the new node point to the head
        }
    }

    // Function to insert a node after a specific value in the circular linked list
    void insertAfter(int afterValue, int value) {
        Node* newNode = new Node(value);
        if (!head) {
            std::cout << "List is empty. Cannot insert after." << std::endl;
            return;
        } else {
            Node* current = head;
            do {
                if (current->data == afterValue) {
                    newNode->next = current->next;
                    current->next = newNode;
                    return;
                }
                current = current->next;
            } while (current != head);
            std::cout << "Value " << afterValue << " not found in the list." << std::endl;
        }
    }

    // Function to delete a node by value from the circular linked list
    void deleteNode(int value) {
        if (!head)
            return;

        Node* current = head;
        Node* prev = nullptr;

        while (current->data != value) {
            if (current->next == head) {
                // If we reach the head again, the element is not in the list
                std::cout << "Element not found in the list." << std::endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        if (current == head) {
            // If the node to be deleted is the head, we need to update the head
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            head = head->next;
        } else {
            // If the node to be deleted is not the head, update the previous node's next pointer
            prev->next = current->next;
        }

        delete current; // Free the memory of the deleted node
    }

    // Function to display the circular linked list
    void display() {
        if (!head)
            return;

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList circularList;
    


    circularList.insertAtBeginning(1);
    circularList.insertAtBeginning(2);
    circularList.insertAtBeginning(3);
    circularList.insertAtBeginning(4);
    circularList.insertAtBeginning(5);

    std::cout << "Circular Linked List: ";
    circularList.display();

    circularList.insertAtEnd(6);

    std::cout << "After inserting 6 at the end: ";
    circularList.display();

    circularList.insertAfter(3, 7);

    std::cout << "After inserting 7 after 3: ";
    circularList.display();

    return 0;
}
