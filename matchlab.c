#include <stdio.h>


void flag_a(char* arguments[])
{
   /*
   -a Criteria:
   - any odd number of repetitions of the letter “b”;
   - exactly one “_”;                                             --> Create a counter var. If var exceeds 1 or is 0, not matching
   - between 3 and 7 repetitions (inclusive) of the letter “t”;
   - exactly two “=”s; and
   - an odd number of uppercase letters.
   */

   int underscoreCounter = 0;

   //Handle each argument individually
   int index;
   for (index = 0; index < sizeof(arguments); index++)
   {
     //stop if there are no more arguments
     if (arguments[index] == "empty") { break; }

     //This should grab the current 'string' and place it into an array of characters?
     char* currentArgument = arguments[index];

     char * currentCharacater; // first copy the pointer to not change the original

     //iterate through each character in order to check the Criteria
     for (currentCharacater = currentArgument; *currentCharacater != '\0'; currentCharacater++) {
        printf("%c\n", *currentCharacater);

        //Update the underscoreCounter variable.
        if (*currentCharacater == '_')
        {
          underscoreCounter++;
        }
     }

     //Underscore condition
     if (underscoreCounter == 0 || underscoreCounter > 1)
     {
        printf("no");
     }


     //Since it has passed all of these tests, we know it's matching so we
     //print yes!
     else {
       printf("yes");
     }


   }

}

void flag_b(char* arguments[])
{
   printf("Flag B: \n");
}

void flag_c(char* arguments[])
{
   printf("Flag C: \n");
}

void flag_t(char* name)
{
   printf("this is -T, %s\n", name);
}

void nonFlag(char* name){
  printf("this is NOT a flag, %s\n", name);
}


int main(int argc, char* argv[])
{
  //-a is the default
  char flag = 'a';

  //0 = False, 1 = True
  int tFlagWasSet = 0;

  //Array of arguments coming in:
  char* args[argc];
  int argsCount = 0;

  //Set each argument to empty so we know when the array is finished
  int tempIndex;
  for (tempIndex = 0; tempIndex < argc; tempIndex++) { args[tempIndex] = "empty"; }


  //For each argument, process it accordingly
  int i;
  char* currentArg;
  for (i = 1; i < argc; i++)
  {
    currentArg = argv[i];

    //These if statements set the right flags
    if (currentArg[0] == '-')
    {
      if (currentArg[1] == 'a' )     {                     }
      else if (currentArg[1] == 'b') {  flag = 'b';        }
      else if (currentArg[1] == 'c') {  flag = 'c';        }
      else if (currentArg[1] == 't') {  tFlagWasSet = 1;   }
    }
    else
    {
      //Add the current argument to the array
      args[argsCount] = currentArg;
      argsCount++;
    }
  }

  //TODO: account for -t flag!

  //At this point, we have the correct flags set, and the arguments stored in an array to process.
  if (flag == 'a')       { flag_a(args); }
  else if (flag == 'b')  { flag_b(args); }
  else if (flag == 'c')  { flag_c(args); }


  return 0;
}
