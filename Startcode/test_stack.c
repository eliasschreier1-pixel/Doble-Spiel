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

    TEST_ASSERT_NULL(stack);
}

void test_clearOnFullStack(void)
{
    StackNode *stack = NULL;
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    int x = 0;
    for(int i = '97' + x; i < 102; i++)
    {
        stack = push(stack, &i);

        x++;
    }

    clearStack(stack);

    TEST_ASSERT_NULL(stack); //!!! Hier weiter machen. Prüfen ob Test korrekt
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

    return UNITY_END();
}