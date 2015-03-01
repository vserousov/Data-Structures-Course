template <class T> 
LinkedList<T>::LinkedList() 
{
    //Creation of the dummy/sentinel element
    pPreHead = new Node<T>;
    pPreHead -> next = 0;

    // Write your code here
    // ...
}

template <class T> 
LinkedList<T>::~LinkedList()
{
    // Write your code here...
    
    Node<T>* start = pPreHead;
    Node<T>* end = pPreHead;

    while (end->next != 0) {
        end = end->next;
    }

    while (start != end) {
        Node<T>* tmp = start->next;
        delete start;
        start = tmp;
    }

    pPreHead = start;
    
    // Delete sentinel
    delete pPreHead;
}

template <class T> 
Node<T>* LinkedList<T>::getPreHead(void) {
    return pPreHead;
}

template <class T> 
T & LinkedList<T>::operator[] (int i) throw(out_of_range) {
    if (i >= size()) {
        throw out_of_range("LinkedList out of range");
    }

    Node<T>* p = pPreHead;
    
    for (int j = 0; j <= i; j++) {
        p = p->next;
    }

    return p->value;
}

template <class T> 
int LinkedList<T>::size() {
    int count = 0;
    Node<T>* p = pPreHead;

    while (p->next != 0) {
        p = p->next;
        count++;
    }

    return count;
}

template <class T> 
void LinkedList<T>::addElementToEnd(T& value) {
    Node<T>* p = pPreHead;

    while (p->next != 0) {
        p = p->next;
    }

    p->next = new Node<T>;
    p->next->value = value;
}

template <class T> 
void LinkedList<T>::deleteNodes(Node<T>* pNodeBefore, Node<T>* pNodeLast) {
    Node<T>* p = pNodeBefore->next;
    Node<T>* add = pNodeLast->next;

    while (p != add) {
        Node<T>* tmp = p->next;
        delete p;
        p = tmp;
    }

    pNodeBefore->next = add;
}

template <class T> 
void LinkedList<T>::deleteNextNode(Node<T>* pNodeBefore) {
    Node<T>* p = pNodeBefore->next->next;
    delete pNodeBefore->next;
    pNodeBefore->next = p;
}

template <class T> 
void LinkedList<T>::addNodesToEnd(Node<T>* pNodeBefore, Node<T>* pNodeLast) {
    Node<T>* add = pNodeBefore->next;
    Node<T>* last = pNodeLast->next;
    pNodeLast->next = 0;
    pNodeBefore->next = last;
    Node<T>* p = pPreHead;

    while (p->next != 0) {
        p = p->next;
    }

    p->next = add;
}

template <class T> 
void LinkedList<T>::addNodeToEnd(Node<T>* pNodeBefore) {
    Node<T>* add = pNodeBefore->next;
    pNodeBefore->next = pNodeBefore->next->next;
    add->next = 0;
    Node<T>* p = pPreHead;
    
    while (p->next != 0) {
        p = p->next;
    }

    p->next = add;
}

template <class T> 
void LinkedList<T>::moveNodesAfter(Node<T>* pNode, Node<T>* pNodeBefore, Node<T>* pNodeLast) {
    Node<T>* p = pNodeBefore->next;
    pNodeBefore->next = pNodeLast->next;
    pNodeLast->next = pNode->next;
    pNode->next = p;
}

template <class T> 
void LinkedList<T>::moveNodeAfter(Node<T>* pNode, Node<T>* pNodeBefore) {
    Node<T>* p = pNodeBefore->next;
    pNodeBefore->next = pNodeBefore->next->next;
    p->next = pNode->next;
    pNode->next = p;
}