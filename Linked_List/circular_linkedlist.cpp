#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
    
public:
    CircularLinkedList() {
        head = nullptr;
    }
    
    // 1 & 3. Insert at End (used to create CLL)
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    
    // 2. Insert at Beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }
    
    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        do {
            cout << temp->data << " → ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }
    
    // 4. Traversal (avoiding infinite loops)
    void traverse() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        cout << "Traversing: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    
    // 5. Count Nodes
    int countNodes() {
        if (head == nullptr) return 0;
        
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        
        return count;
    }
    // 6. Delete First Node
    void deleteFirst() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        
        Node* toDelete = head;
        temp->next = head->next;
        head = head->next;
        delete toDelete;
    }
    
    // 7. Delete Last Node
    void deleteLast() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        
        Node* toDelete = temp->next;
        temp->next = head;
        delete toDelete;
    }
    
    // 8. Search a Key
    bool search(int key) {
        if (head == nullptr) return false;
        
        Node* temp = head;
        do {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        
        return false;
    }
    
    // 9. Insert After Given Node
    void insertAfter(int key, int data) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(data);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        
        cout << "Key " << key << " not found" << endl;
    }
    
    // 10. Split CLL into Two Equal Halves
    void splitList(CircularLinkedList& cll1, CircularLinkedList& cll2) {
        if (head == nullptr || head->next == head) {
            cout << "Cannot split - insufficient nodes" << endl;
            return;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        cll1.head = head;
        cll2.head = slow->next;
        slow->next = cll1.head;
        
        Node* temp = cll2.head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = cll2.head;
    }
    
    // 11. Check if List is Circular
    bool isCircular() {
        if (head == nullptr) return true;
        
        Node* temp = head->next;
        while (temp != nullptr && temp != head) {
            temp = temp->next;
        }
        
        return (temp == head);
    }
    
    // 12. Josephus Problem
    static int josephus(int n, int k) {
        CircularLinkedList cll;
        for (int i = 1; i <= n; i++) {
            cll.insertAtEnd(i);
        }
        
        Node* current = cll.head;
        cout << "\nJosephus Problem: n=" << n << ", k=" << k << endl;
        
        while (current->next != current) {
            for (int i = 1; i < k; i++) {
                current = current->next;
            }
            
            cout << "Eliminated: " << current->next->data << endl;
            Node* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        }
        
        cout << "Survivor: " << current->data << endl;
        return current->data;
    }
    
    // 13. Reverse CLL
    void reverse() {
        if (head == nullptr || head->next == head) {
            return;
        }
        
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        Node* tail = head;
        
        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);
        
        tail->next = prev;
        head = prev;
    }
    
    // 14. Convert SLL to CLL
    static CircularLinkedList* sllToCll(Node* sllHead) {
        if (sllHead == nullptr) {
            return nullptr;
        }
        
        Node* temp = sllHead;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        temp->next = sllHead;
        
        CircularLinkedList* cll = new CircularLinkedList();
        cll->head = sllHead;
        return cll;
    }
    
    // 15. Insert in Sorted CLL
    void insertSorted(int data) {
        Node* newNode = new Node(data);
        
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        
        Node* current = head;
        
        // Insert before head if data is smallest
        if (data <= current->data) {
            while (current->next != head) {
                current = current->next;
            }
            newNode->next = head;
            current->next = newNode;
            head = newNode;
            return;
        }
        
        // Find position to insert
        while (current->next != head && current->next->data < data) {
            current = current->next;
        }
        
        newNode->next = current->next;
        current->next = newNode;
    }
    
    Node* getHead() { return head; }
};

int main() {
    // 1. Create CLL
    cout << "\n1. Creating Circular Linked List:" << endl;
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    cll.display();
    
    // 2. Insert at Beginning
    cout << "\n2. Insert at Beginning (5):" << endl;
    cll.insertAtBeginning(5);
    cll.display();
    
    // 3. Insert at End
    cout << "\n3. Insert at End (50):" << endl;
    cll.insertAtEnd(50);
    cll.display();
    
    // 4. Traversal
    cout << "\n4. Traversal (showing loop prevention):" << endl;
    cll.traverse();
    
    // 5. Count Nodes
    cout << "\n5. Count Nodes: " << cll.countNodes() << endl;
    
    // 6. Delete First Node
    cout << "\n6. Delete First Node:" << endl;
    cll.deleteFirst();
    cll.display();
    
    // 7. Delete Last Node
    cout << "\n7. Delete Last Node:" << endl;
    cll.deleteLast();
    cll.display();
    
    // 8. Search Key
    cout << "\n8. Search for key 20: " << (cll.search(20) ? "FOUND" : "NOT FOUND") << endl;
    cout << "   Search for key 100: " << (cll.search(100) ? "FOUND" : "NOT FOUND") << endl;
    
    // 9. Insert After Given Node
    cout << "\n9. Insert 25 after 20:" << endl;
    cll.insertAfter(20, 25);
    cll.display();
    
    // 10. Split List
    cout << "\n10. Split List into Two Halves:" << endl;
    CircularLinkedList cll1, cll2;
    cll.splitList(cll1, cll2);
    cout << "First half: ";
    cll1.display();
    cout << "Second half: ";
    cll2.display();
        
    // 11. Check if Circular
    cout << "\n11. Is list circular? " << (cll1.isCircular() ? "YES" : "NO") << endl;
    
    // 12. Josephus Problem
    CircularLinkedList::josephus(7, 3);
    
    // 13. Reverse CLL
    cout << "\n13. Reversing CLL:" << endl;
    cout << "Original: ";
    cll1.display();
    cll1.reverse();
    cout << "Reversed: ";
    cll1.display();
    
    // 14. Convert SLL to CLL
    cout << "\n14. Convert SLL to CLL:" << endl;
    Node* sllHead = new Node(1);
    sllHead->next = new Node(2);
    sllHead->next->next = new Node(3);
    CircularLinkedList* convertedCll = CircularLinkedList::sllToCll(sllHead);
    cout << "Converted: ";
    convertedCll->display();
    
    // 15. Insert in Sorted CLL
    cout << "\n15. Insert in Sorted CLL:" << endl;
    CircularLinkedList sortedCll;
    sortedCll.insertSorted(10);
    sortedCll.insertSorted(30);
    sortedCll.insertSorted(20);
    sortedCll.insertSorted(40);
    sortedCll.insertSorted(5);
    cout << "Sorted list: ";
    sortedCll.display();
    
    return 0;
}