#include <iostream>
#include "Stack.h"

using namespace std;

#define NORMAL
#ifdef NORMAL

int main()
{
    //kiv�telkezel�s
    try {
        /*try �gban haszn�ljuk azokat a met�dusokat, amik kiv�telt dobhatnak
            *ha nincs kiv�tel, akkor a try v�gigfut, a catch �gba nem l�p�nk be
            *kiv�tel eset�n a catch �gba ugrunk, az ex v�ltoz� �rt�ke az "elkapott" kiv�tel
        */
        Stack s;
        for (int i = 1; i <= 10; ++i) {
            s.push(i);
        }

        while (!s.isEmpty()) {
            std::cout << s.pop() << std::endl;
        }

    } catch (StackException ex) {

        //Azonos�tjuk a kiv�telt
        switch(ex) {
        case StackOverFlowException:
            std::cout << "Stack is full!\n";
            break;
        case ItemNotFoundException:
            std::cout << "Stack is empty!\n";
            break;
        }
    }

    //Mi t�rt�nik, ha nem kezelj�k a kiv�telt
    //Stack s;
    //s.pop();

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//N�h�ny teszteset

TEST_CASE("Empty stack, top method", "Should throw ItemNotFoundException") {

    Stack s;
    CHECK_THROWS(s.top()); //Azt ellen�rzi, hogy a top met�dus dob -e kiv�telt
}

TEST_CASE("Empty stack, pop method", "Should throw ItemNotFoundException") {

    Stack s;
    CHECK_THROWS(s.pop());
}

TEST_CASE("Stack with 1 item, top method", "Should return the top item") {

    Stack s;
    s.push(1);
    CHECK(s.top() == 1);
}

TEST_CASE("Stack with 1 item, pop method", "Should return the top item with empty stack") {

    Stack s;
    s.push(1);
    bool result = s.pop() == 1 && s.isEmpty();
    CHECK(result);
}

TEST_CASE("Stack with more items, pop method", "Should return the top item") {

    Stack s;

    for (int i = 1; i <= 5; ++i) {
        s.push(i);
    }

    CHECK(s.top() == 5);
}

TEST_CASE("Full stack, full method", "Should return true") {

    Stack s;

    for (int i = 1; i <= 100; ++i) {
        s.push(i);
    }

    CHECK(s.isFull());
}

TEST_CASE("Empty stack, empty method", "Should return true") {

    Stack s;

    CHECK(s.isEmpty());
}

TEST_CASE("Full stack, push method", "Should throw StackOverFlowException") {

    Stack s;

    for (int i = 1; i <= 100; ++i) {
        s.push(i);
    }

    CHECK_THROWS(s.push(10));
}

TEST_CASE("Stack with more items, clear method", "isEmpty should return true") {

    Stack s;

    for (int i = 1; i <= 10; ++i) {
        s.push(i);
    }
    s.clear();

    CHECK(s.isEmpty());
}

#endif
