/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.h
 * Author: maria
 *
 * Created on 16 de mayo de 2017, 10:23
 */

#ifndef LIST_H
#define LIST_H

class List {
public:
    List();
    List(const List& orig);
    virtual ~List();
    void insertIntoList(char value);
    void deleteFromList(char value);
    void insertInOrder(char value);
    void actualizar(char value, char newValue);
    void printList();

private:

    struct listNode {
        char data;
        struct listNode *nextPtr;

    };

    /*variables*/
    typedef struct listNode NODE;
    typedef NODE * NODEPTR;

    NODEPTR headNode;


};

#endif /* LIST_H */

