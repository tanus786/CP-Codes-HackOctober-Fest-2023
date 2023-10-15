// This code use the concept of stack implementation and ask user to input the size of stack and perform the operation accordingly

#include <iostream>

class Stack {
private:
    int* arr;      // Pointer to dynamically allocated array
    int capacity;  // Maximum capacity of the stack
    int top;       // Index of the top element

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1) {
            std::cout << "Stack is full. Cannot push " << value << std::endl;
            return;
        }
        arr[++top] = value;
        std::cout << value << " pushed to the stack." << std::endl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        std::cout << arr[top--] << " popped from the stack." << std::endl;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the stack: ";
    std::cin >> size;

    Stack stack(size); // Create a stack with user-defined capacity

    while (true) {
        int choice;
        std::cout << "1. Push element\n2. Pop element\n3. Display remaining items\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int value;
                std::cout << "Enter the element to push: ";
                std::cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                if (stack.isEmpty()) {
                    std::cout << "Stack is empty." << std::endl;
                } else {
                    std::cout << "Remaining items in the stack: ";
                    for (int i = 0; i <= stack.size(); i++) {
                        std::cout << stack.peek() << " ";
                        stack.pop();
                    }
                    std::cout << std::endl;
                }
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
}