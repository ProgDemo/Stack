//Vektorral �br�zolt statikus verem, eg�sz sz�mokkal

/*
Include guard, seg�ts�g�vel a header hivatkoz�s hely�n elker�lhet� a duplik�ci�.
Tov�bbiak: https://en.wikipedia.org/wiki/Include_guard
*/
#ifndef STACK_H
#define STACK_H

#include <vector>

//Kiv�telt�pus
enum StackException {StackOverFlowException, ItemNotFoundException};

class Stack
{
    private:
        const int MAX_SIZE = 100;
        int stackPointer; //a verem tetej�re mutat, az aktu�lis elemsz�mot is mutatja
        std::vector<int> items;

    public:
        Stack(): stackPointer(0) {}
        void push(const int& item);
        int pop();
        void clear();
        int top() const;
        bool isEmpty() const;
        bool isFull() const;
};

#endif // STACK_H
