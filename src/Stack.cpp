//Statikus verem, tesztel�s, kiv�telkezel�s

#include "Stack.h"

//�j elemet helyez a verem tetej�re, ha a verem tele van kiv�telt dob
void Stack::push(const int& item) {

    if (isFull()) {
        throw StackOverFlowException;
    }

    items.push_back(item);
    stackPointer++;
}

//Kiveszi a verem tetej�n l�v� elemet, ha a verem �res kiv�telt dob
int Stack::pop() {

    if (isEmpty()) {
        throw ItemNotFoundException;
    }

    stackPointer--;
    int item = items.back();
    items.pop_back();

    return item;
}

//�r�ti a vermet
void Stack::clear() {

    stackPointer = 0;
    items.clear();
}

//Visszaadja a verem tetej�n l�v� elemet, de nem veszi ki a veremb�l
int Stack::top() const {

    if (stackPointer == 0) { //items.empty()
        throw ItemNotFoundException;
    }

    return items.back();
}

bool Stack::isEmpty() const {

    return items.empty();
}

bool Stack::isFull() const {

    return stackPointer == MAX_SIZE; // items.size() == MAX_SIZE
}
