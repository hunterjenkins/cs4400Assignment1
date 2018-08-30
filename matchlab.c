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

   //Handle each argument individually
   int index;
   for (index = 0; index < sizeof(arguments); index++)
   {
     char currentArgument[] = arguments[index]; //This should grab the current 'string' and place it into an array of characters?

     //iterate through each character in order to check the Criteria
     int characterIndex;
     for (characterIndex = 0; characterIndex < sizeof(currentArgument); characterIndex++)
     {

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
  char* args[];
  int argsCount = 0;

  //For each argument, process it accordingly
  int i;
  char* currentArg;
  for (i = 1; i < argc; i++)
  {
    currentArg = argv[i];

    //These if statements set the right flags
    if (currentArg[0] == '-')
    {
      if (currentArg[1] == 'b')      {  flag = 'b'; }
      else if (currentArg[1] == 'c') {  flag = 'c'; }
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
