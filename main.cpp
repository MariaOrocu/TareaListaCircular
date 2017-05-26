/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: maria
 *
 * Created on 16 de mayo de 2017, 10:23
 */

#include <cstdlib>

#include "List.h"

using namespace std;

/*
 * 
 */
int main() {

    List myList;
    myList.insertIntoList('a');
    myList.insertIntoList('b');
    myList.insertIntoList('c');
    myList.printList();

    myList.insertInOrder('e');
    myList.insertInOrder('d');
    myList.insertInOrder('g');
    myList.insertInOrder('f');
    myList.printList();
     
    myList.deleteFromList('d');
    myList.deleteFromList('g');
    myList.printList();

    myList.actualizar('a', 'w');
    myList.actualizar('e', 'i');
    myList.printList();

}

