#include <stdio.h>


void flag_a(char* arguments[])
{
   /*
   -a Criteria:                                                       STATUS
   - any odd number of repetitions of the letter “b”;             --> TODO: find out if this is for upper and lowercase
   - exactly one “_”;                                             --> DONE
   - between 3 and 7 repetitions (inclusive) of the letter “t”;   --> TODO: find out if this is for upper and lowercase
   - exactly two “=”s; and                                        --> DONE
   - an odd number of uppercase letters.                          --> DONE
   */


   //Counters
   int letterBRepCounter      = 0;
   int underscoreCounter      = 0;
   int letterTCounter         = 0;
   int characterEqualsCounter = 0;
   int upperCaseCount         = 0;


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

        //Update the letterBRepCounter
        if (*currentCharacater == 'b')
        {
          letterBRepCounter++;
        }
        //Update the underscoreCounter variable.
        else if (*currentCharacater == '_')
        {
          underscoreCounter++;
        }
        else if (*currentCharacater == 't')
        {
          letterTCounter++;
        }
        else if (*currentCharacater == '=')
        {
          characterEqualsCounter++;
        }


        //This check is seperate because we want to count multiple times, where
        //we don't with the ones above.
        if (*currentCharacater >= 65 && *currentCharacater <= 90) { //ASCII chart
          upperCaseCount++;
        }
     }

     //Note: the if statements are more simple as to avoid bugs.
     // I learned this technique from my internship.

     //Letter B conditions
     if (letterBRepCounter%2 == 0) //If even
     {
       printf("no\n");
       printf("1\n");
     }

     //Underscore conditions
     else if (underscoreCounter == 0)
     {
       printf("no\n");
       printf("2\n");
     }
     else if (underscoreCounter > 1)
     {
        printf("no\n");
        printf("3\n");
     }

     //Letter T conditions
     else if (letterTCounter > 7)
     {
       printf("no\n");
       printf("4\n");
     }
     else if (letterTCounter < 3)
     {
       printf("no\n");
       printf("5\n");
     }

     //= character conditions
     else if (characterEqualsCounter != 2)
     {
       printf("no\n");
       printf("6\n");
     }

     //Uppercase conditions
     else if (upperCaseCount%2 == 0) //If even
     {
       printf("no\n");
       printf("7\n");
     }



     //Since it has passed all of these tests, we know it's matching so we
     //print yes!
     else {
       printf("yes\n");

       printf("stats:\n");
       printf("letterBRepCounter %d\n", letterBRepCounter);
       printf("underscoreCounter %d\n", underscoreCounter);
       printf("letterTCounter %d\n", letterTCounter);
       printf("characterEqualsCounter %d\n", characterEqualsCounter);
       printf("upperCaseCount %d\n", upperCaseCount);
  
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
      if (currentArg[1] == 'a' )     {                   }
      else if (currentArg[1] == 'b') {  flag = 'b';      }
      else if (currentArg[1] == 'c') {  flag = 'c';      }
      else if (currentArg[1] == 't') {  tFlagWasSet = 1; }
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
