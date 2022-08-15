#include "shuffle.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    printf("Usage: %s <number of simulations>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);

  int* boxes = malloc(sizeof(int) * 100);
  int count_loss_random = 0;
  int count_loss_strategy = 0;

  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    
    for (int i = 0; i < 100; i++)
    {
      boxes[i] = i;
    }

    shuffle(boxes, 100);

    // play round for random choice
    for (int prisoner = 0; prisoner < 100; prisoner++)
    {
      unsigned found = 0;

      for (int round = 0; round < 50; round++)
      {
        int choice = random_int(0, 100);
        
        // prisoner found their number
        if (boxes[choice] == prisoner)
        {
          found = 1;
          break;
        }
      }

      // Prisoner hasnt found their box number
      if (!found)
      {
        count_loss_random++;
        break;
      }
    }

    // play round for strategy choice
    for (int prisoner = 0; prisoner < 100; prisoner++)
    {
      unsigned found = 0;

      int prev_choice = prisoner;
      for (int round = 0; round < 50; round++)
      {
        int choice = boxes[prev_choice];
        
        // prisoner found their number
        if (boxes[choice] == prisoner)
        {
          found = 1;
          break;
        }

        prev_choice = choice;
      }

      // Prisoner hasnt found their box number
      if (!found)
      {
        count_loss_strategy++;
        break;
      }
    }
  }

  printf("Random choice: %f %%\n", ((float)(n-count_loss_random)/(float)n)*100.0);
  printf("Strategy choice: %f %%\n", ((float)(n-count_loss_strategy)/(float)n)*100.0);
  free(boxes);
  return 0;
}
