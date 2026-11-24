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
    StackNode *newNode = malloc(sizeof(StackNode)); //Erzeugt Speicher der größe des erstellten structs
    if(newNode == NULL){ //Fall newNode nicht ersetellt wird der vorherige Knoten unverändert zurückgegeben
        return stack;
    }

    newNode->data = data; //Neuer Knoten bekommt Adresse des nächsten Knotens sowie Adresse der gewünschten Daten zugewiesen
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

    StackNode *temp = stack->next; //Zeiger wird zwischengepeichert, der Stack gelöscht und anschlißend der Zeiger auf den jetzt obersten Knoten zurückgegeben
    
    free(stack); //Wichtig nach temp, da sonst die Adresse auf den nächsten Knoten verloren wäre und kein Zugriff mehr möglich

    return temp;
}

// Returns the data of the top element.
void *top(StackNode *stack)
{
    if(stack == NULL){
        return NULL;
    }
    return stack->data; //gibt den Inhalt des obersten Knotens zurück
}

// Clears stack and releases all memory.
void clearStack(StackNode *stack)
{
    if(stack == NULL){
        return stack;
    }

    while(stack != NULL){ //Gleicher Aufbau wie pop. Wird nur mehrfach wiederholt, bis nichts mehr im Stack liegt
        StackNode *temp = stack->next;

        free(stack);

        stack = temp;
    }
    return NULL;
}