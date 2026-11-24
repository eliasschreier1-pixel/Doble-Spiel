#include <stdlib.h>
#include "stack.h"

//TODO: grundlegende Stackfunktionen implementieren:
/*  * `push`: legt ein Element oben auf den Stack,
    * `pop`: entfernt das oberste Element,
    * `top`: liefert das oberste Element zurück,
    * `clearStack`: gibt den gesamten Speicher frei. */

// Pushes data as pointer onto the stack.
StackNode *push(StackNode *stack, void *data)
{
    StackNode *newNode = malloc(sizeof(StackNode));
    if(newNode == NULL){
        return stack;
    }

    newNode->data = data;
    newNode->next = stack;

    return newNode;


}

// Deletes the top element of the stack (latest added element) and releases its memory. (Pointer to data has to be
// freed by caller.)
StackNode *pop(StackNode *stack)
{
    if(stack == NULL){
        return stack;
    }

    StackNode *temp = stack->next;
    
    free(stack);

    return temp;
}

// Returns the data of the top element.
void *top(StackNode *stack)
{
    if(stack == NULL){
        return NULL;
    }
    return stack->data;
}

// Clears stack and releases all memory.
void clearStack(StackNode *stack)
{

}