#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "unity.h"

void test_pushThenTopReturnsPushedData(void)
{
    int a = 1;
    StackNode *stack = NULL;
    
    stack = push(stack, &a); //Ein Knoten pushen, dann auslesen und mit eingegebenem Wert vergleichen

    TEST_ASSERT_EQUAL_PTR(&a, top(stack));

    clearStack(stack);
}

void test_popRevealsPreviousElement(void)
{
    int a = 1, b = 2;
    StackNode *stack = NULL;

    stack = push(stack, &a); //Zwei Knoten pushen, einen wieder löschen und auslesen
    stack = push(stack, &b);

    stack = pop(stack);

    TEST_ASSERT_EQUAL_PTR(&a, top(stack));
    TEST_ASSERT_NOT_NULL(stack); //Prüfen ob noch etwas im Stack ist

    clearStack(stack);
}

void test_topOnEmptyStack(void)
{
    StackNode *stack = NULL;

    TEST_ASSERT_NULL(top(stack)); //Aufrufen des Rückgabewerrts
}

void test_popOnEmptyStack(void)
{
    StackNode *stack = NULL;

    TEST_ASSERT_NULL(stack); //Aufrufen der Variable
}

void test_clearOnEmptyStack(void)
{
    StackNode *stack = NULL;

    clearStack(stack);

    TEST_ASSERT_NULL(stack); //NULL Test ändert nichts. Eigentlich sollte hier nur kein Absturz geprüft werden
}                              //!!!Vlt nochmal ändern

void test_clearOnFullStack(void)
{
    StackNode *stack = NULL;
    int values[5] = {1, 2, 3, 4, 5};
    
    for(int i = 0; i < 5; i++)
    {
        stack = push(stack, &values[i]);
    }

    TEST_ASSERT_NOT_NULL(stack); //!!! Hier weiter machen. Prüfen ob Test korrekt 
    
    clearStack(stack);
}

void setUp(void) {}
void tearDown(void) {}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_pushThenTopReturnsPushedData);
    RUN_TEST(test_popRevealsPreviousElement);
    RUN_TEST(test_topOnEmptyStack);
    RUN_TEST(test_popOnEmptyStack);
    RUN_TEST(test_clearOnEmptyStack);
    RUN_TEST(test_clearOnFullStack);

    return UNITY_END();
}