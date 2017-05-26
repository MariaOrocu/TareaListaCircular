/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.cpp
 * Author: maria
 * 
 * Created on 16 de mayo de 2017, 10:23
 */

#include "List.h"
#include <sstream>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

List::List() {
    headNode = NULL;
}

List::List(const List& orig) {
}

List::~List() {
}

void List::insertIntoList(char value) {

    NODEPTR newPtr, tempPtr, headNodePrev;

    newPtr = (NODEPTR) malloc(sizeof (NODE));
    newPtr->data = value;
    newPtr->nextPtr = NULL;


    tempPtr = headNode;
    headNodePrev = headNode;
    if (tempPtr == NULL) {
        headNode = newPtr;
        newPtr->nextPtr = headNode;
    } else {
        headNode = newPtr;
        headNode->nextPtr = tempPtr;
        bool recorrer = true;
        while (recorrer) {
            if (tempPtr->nextPtr->data == headNodePrev->data) {
                recorrer = false;
                tempPtr->nextPtr = headNode;
            }
            tempPtr = tempPtr->nextPtr;
        }
    }
}

void List::printList() {
    //nodo temporal
    NODEPTR tempNode = headNode;
    bool recorrer = true;
    bool completa = false;
    if (tempNode != NULL) {
        while (recorrer) {
            if (tempNode->data == headNode->data) {
                if (completa) {
                    recorrer = false;
                } else {
                    completa = true;
                    printf("%c--> ", tempNode->data);
                }
            } else {
                printf("%c--> ", tempNode->data);
            }
            tempNode = tempNode->nextPtr;
        }

    } else {
        printf("The list is empty.\n\n");
    }
    printf("END ");
}

void List::deleteFromList(char value) {
    NODEPTR tempPtr, headNodePrev, prevPtr;

    bool recorrer = true;
    if (headNode->data == value) {
        tempPtr = headNode;
        headNodePrev = headNode;
        headNode = tempPtr->nextPtr;

        while (recorrer) {
            if (tempPtr->nextPtr->data == headNodePrev->data) {
                recorrer = false;
                tempPtr->nextPtr = headNode;
            }
            tempPtr = tempPtr->nextPtr;
        }
    } else {
        prevPtr = headNode;
        tempPtr = headNode->nextPtr;
        while (recorrer) {
            if (tempPtr->data == value) {
                recorrer = false;
                prevPtr->nextPtr = tempPtr->nextPtr;
            }
            if (tempPtr->data == headNode->data) {
                recorrer = false;
            }
            tempPtr = tempPtr->nextPtr;
            prevPtr = prevPtr->nextPtr;
        }
    }

}

void List::insertInOrder(char value) {

    NODEPTR newPtr, tempPtr, headNodePrev;

    newPtr = (NODEPTR) malloc(sizeof (NODE));
    newPtr->data = value;
    newPtr->nextPtr = NULL;
    tempPtr = headNode;

    if (tempPtr == NULL) {
        headNode = newPtr;
        newPtr->nextPtr = headNode;
    } else if (strcmp(&newPtr->data, &headNode->data) < 0) {

        headNodePrev = headNode;
        headNode = newPtr;
        headNode->nextPtr = tempPtr;
        bool recorrer = true;
        while (recorrer) {
            if (tempPtr->nextPtr->data == headNodePrev->data) {
                recorrer = false;
                tempPtr->nextPtr = headNode;
            }

            tempPtr = tempPtr->nextPtr;
        }
    } else {
        bool recorrer = true;
        while (recorrer) {
            if (tempPtr->nextPtr->data == headNode->data) {
                recorrer = false;
                tempPtr->nextPtr = newPtr;
                newPtr->nextPtr = headNode;
            } else {
                if (strcmp(&tempPtr->nextPtr->data, &newPtr->data) > 0) {
                    recorrer = false;
                    newPtr->nextPtr = tempPtr->nextPtr;
                    tempPtr->nextPtr = newPtr;
                }
            }
            tempPtr = tempPtr->nextPtr;
        }
    }

}

void List::actualizar(char value, char newValue) {

    NODEPTR tempPtr;

    tempPtr = headNode;
    if (headNode->data == value) {
        headNode->data = newValue;

    } else {
        bool recorrer = true;
        while (recorrer) {
            if (tempPtr->nextPtr->data == headNode->data) {
                recorrer = false;
            }
            if (tempPtr->data == value) {
                tempPtr->data = newValue;
            }
            tempPtr = tempPtr->nextPtr;
        }
    }
}







