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
    randomNumbers[i] = numbers;
  }

   //Eine Zahl aussuchen und dann Duplizieren und wieder an irgendeiner stelle einfügen
  unsigned int indexToDuplicate = rand() % len;
  unsigned int temp = randomNumbers[indexToDuplicate];
  unsigned int indexToPlace = indexToDuplicate;
  while(indexToDuplicate == indexToPlace){
    indexToPlace = rand() % len;
  }
  randomNumbers[indexToPlace] = temp;

  return randomNumbers;
}
//Vergleichsfunktion um zu überprüfen welche Zahl doppelt vor kommt
int compareNumbers(const void *a, const void *b){
  const unsigned int *numA = (const unsigned int *)a;
  const unsigned int *numB = (const unsigned int *)b;
  if(*numA < *numB){
    return -1;
  }
  else if(*numA > *numB){
    return 1;
  }
  else{
    return 0;
  }
}



// Returns only the only number in numbers which is present twice. Returns zero on errors.
unsigned int getDuplicate(const unsigned int numbers[], unsigned int len)
{
  if(numbers == 0 || len == 0){
    return 0;
  }
  unsigned int *sortNumbers = malloc(len * sizeof(unsigned int));
  if(sortNumbers == NULL){
    return 0;
  }
  for(unsigned int i = 0; i < len; i++){
      sortNumbers[i] = numbers[i];
  }
  unsigned int duplicate = 0;
  qsort(sortNumbers, len, sizeof(unsigned int), compareNumbers);
  for(unsigned int i = 0; i < len - 1; i++){
   if(sortNumbers[i] == sortNumbers[i + 1]){
     duplicate = sortNumbers[i];
     break;
    }
  }
  free(sortNumbers);
  return duplicate;

}