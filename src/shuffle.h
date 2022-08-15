#include <stdlib.h>

int random_int(int min, int max) { return rand() % (max - min + 1) + min; }

void shuffle(int* array, int size)
{
  for (int i = size - 1; i > 0; i--)
  {
    int j = random_int(0, i);
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}
