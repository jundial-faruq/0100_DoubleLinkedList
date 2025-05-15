#include <iostream>
using namespace std;


class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // step 1: Allocate memory for new node
        Node *newNode = new Node();

        // step 2: Assign value to the data field
        newNode->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            //step 4: newNode.next = START
            newNode->next = START;

            // step 5: START.prev = newNode (if START exists)
            if (START != NULL)
                START->prev = newNode;

            // step 6: newNode.prev = NULL
            newNode->prev = NULL;
           
            //step 7: START = newNode
            START = newNode;
            return;
            
        }

        //insert in between node
        // step 8: Locate position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDublicate roll numbers not allowed" << endl;
            return;
        }
        
        // step 9: Insert between current  and current->next
        newNode->next = current->next; // Step 9a:newNode.next = current.next
        newNode->prev = current; // Step 9b: newNode.prev = current

        // Insert Last node
        if (current->next != NULL)
            current->next->prev = newNode; // step 9c: current.next = newNode

            current->next = newNode; // step 9d: current.next = newNode
    }
}

int main()
{


    return 0;
}