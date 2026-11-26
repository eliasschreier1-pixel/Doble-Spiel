#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "numbers.h"
#include "bintree.h"

//TODO: getDuplicate und createNumbers implementieren
/*  *   * Erzeugen eines Arrays mit der vom Nutzer eingegebenen Anzahl an Zufallszahlen.
  * Sicherstellen, dass beim Befüllen keine Duplikate entstehen.
  * Duplizieren eines zufälligen Eintrags im Array.
  * in `getDuplicate()`: Sortieren des Arrays und Erkennen der doppelten Zahl durch Vergleich benachbarter Elemente. */

// Returns len random numbers between 1 and 2x len in random order which are all different, except for two entries.
// Returns NULL on errors. Use your implementation of the binary search tree to check for possible duplicates while
// creating random numbers.
unsigned int *createNumbers(unsigned int len)
{
  srand(time(NULL));
  if(len == 0){
    return NULL;
  }
  //Speicher Anlegen
  unsigned int *randomNumbers = malloc(len * sizeof(unsigned int));
  if(randomNumbers == NULL){ //Überprüfen ob es geklappt hat
    return NULL;
  }
  //Random Zahlen erstellen und überprüfen ob jede nur einmal vorkommt
  for(unsigned int i = 0; i < len; i++){
    unsigned int duplicateFound = 1;
    unsigned int numbers;
    while(duplicateFound == 1){
      duplicateFound = 0;
      numbers = (rand() % (2 * len)) + 1;
      for(unsigned int j = 0; j < i; j++){
        if(randomNumbers[j] == numbers){
          duplicateFound = 1;
          break;
        }
      }      
    }
    //Eine Zahl aussuchen und dann Duplizieren und wieder an irgendeiner stelle einfügen
    


    randomNumbers[i] = numbers;
  }
  
  unsigned int IndexToDuplicate = rand() % (len + 1);
  unsigned int temp = randomNumbers[IndexToDuplicate];
  unsigned int duplicatePlace = 1;
  unsigned int IndexToPlace;
  while(duplicatePlace == 1){
    IndexToPlace = rand() % (len + 1);
    if(IndexToDuplicate == IndexToPlace){
      duplicatePlace == 1;
    }
  }
  randomNumbers[IndexToPlace] = temp;

  return randomNumbers;
}

// Returns only the only number in numbers which is present twice. Returns zero on errors.
unsigned int getDuplicate(const unsigned int numbers[], unsigned int len)
{

}