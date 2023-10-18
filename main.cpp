#include <iostream>

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

class UnorderedLinkedList {
private:
    Node* head; // Pointer to the head of the linked list

public:
    UnorderedLinkedList() {
        head = nullptr;
    }

    // Function to insert an element at the beginning of the list
    void insert(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Function to display the elements in the list
    void display() {
        Node* current = head;
        std::cout << "List: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free the memory when the object is destroyed
    ~UnorderedLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    UnorderedLinkedList list;

    int choice, value;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Insert an element\n";
        std::cout << "2. Display elements\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter an element to insert: ";
                std::cin >> value;
                list.insert(value);
                break;
            case 2:
                list.display();
                break;
            case 3:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
