/**
 * @file linked_list.cpp
 * @author Ivan Mercep
 * @brief 
 * insert, reverse and print Linked List
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

struct Node
{
    int value;
    Node* next;

    Node(int value) : value(value), next(nullptr) {};
};

class LinkedList 
{
    Node* head;
public:
    LinkedList() : head(nullptr) {};
    ~LinkedList() {
        delete[] head;
    };

    /**
     * @brief 
     * Have to use pointer to pointer to keep head pointing to the first element
     * 
     * @param value node's value
     */
    void push(int value)
    {
        Node** it = &head;
        while(*it != nullptr)
        {
            it = &(*it)->next;
        }
        *it = new Node(value);
    }

    /**
     * @brief 
     * head->next becomes previous.
     * head becomes head->next.
     * Prev will be reversed linked list
     */
    void reverse()
    {
        Node* prev = nullptr;
        Node* next = nullptr;

        while(head != nullptr)
        {
            // need this for last line in scope
            next = head->next;

            //swap
            head->next = prev;

            //for next iteration
            prev = head;
            head = next; 
        }
        head = prev;
    }

    /**
     * @brief 
     * pointer to head and iterate
     */
    void print()
    {
        std::cout << "Linked List: ";
        Node* it = head;
        while(it != nullptr)
        {
            std::cout << it->value << " ";
            it = it->next;
        }
        std::cout << "\n";
    }

};


int main(int argc, char** argv)
{
    LinkedList ll;
    ll.push(1);
    ll.push(3);
    ll.push(5);

    ll.print();
    // ll: (null)->1->3->5->(null)

    ll.reverse();

    ll.print();
    // ll: (null)->5->3->1->(null)

    return 0;
}
