#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
   Node class that wraps the element in the LinkedList.
   Next reference is 0 when there is no next value after this node.
   */
template <class T>
class Node {
    public:
        T value;
        // The content/data/value of the node

        Node * next;
        // The pointer to the next element
    public:
        Node(): next(0) { }
        //Constructor
};

/* Linked list template */
template <class T> 
class LinkedList { 
    private:
        Node<T>* pPreHead; 
        // ��������������� �������

    public:
        LinkedList(void);

        ~LinkedList(void);

        Node<T>* getPreHead(void);
        /*
         * ���������� pPreHead
         */

        T & operator[] (int i) throw(out_of_range);
        /*
         * ���������� ������� �� �������
         */

        int size();
        /*
         * ������� ������ ������
         */

        void addElementToEnd(T& value);
        /*
         * �������� ����� ���� �� ��������� value � ����� ������
         */

        void deleteNodes(Node<T>* pNodeBefore, Node<T>* pNodeLast);
        /*
         * ������� ���� ������� �� pNodeBefore->next � �� ���� pNodeLast
         * �����!!! �� ������� pNodeBefore, � pNodeLast �������
         * �.�. ������� ���� �� pNodeBefore->next �� pNodeLast ������������.
         */

        void deleteNextNode(Node<T>* pNodeBefore);
        /*
         * ������� ���� pNodeBefore->next
         * �����!!! �� ������� pNodeBefore
         */

        void addNodesToEnd(Node<T>* pNodeBefore, Node<T>* pNodeLast);
        /*
         * �������� � ����� �������� ������ ���� �� ������� ������ �� pNodeBefore->next �� pNodeLast
         * �����!!! pNodeBefore � pNodeLast - ���� ������� ������
         * �� ������� ������ ���� pNodeBefore->next...pNodeLast ��������.
         */

        void addNodeToEnd(Node<T>* pNodeBefore);
        /*
         * �������� � ����� �������� ������ ���� pNodeBefore->next �� ������� ������
         * �����!!! pNodeBefore - ���� ������� ������
         * �� ������� ������ ���� pNodeBefore->next ��������.
         */

        void moveNodesAfter(Node<T>* pNode, Node<T>* pNodeBefore, Node<T>* pNodeLast);
        /*
         * �������� �� ������� ������ ���� pNodeBefore->next ... pNodeLast
         * � ������� ������ ����� ���� pNode.
         * �����!!! pNodeBefore � pNodeLast - ���� ������� ������
         * �� ������� ������ ���� pNodeBefore->next...pNodeLast ��������.
         */

        void moveNodeAfter(Node<T>* pNode, Node<T>* pNodeBefore);
        /*
         * �������� �� ������� ������ ���� pNodeBefore->next
         * � ������� ������ ����� ���� pNode.
         * �����!!! pNodeBefore - ���� ������� ������
         * �� ������� ������ ���� pNodeBefore->next ��������.
         */
};

#include "LinkedList.hpp"

#endif

