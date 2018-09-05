#include <stdio.h>


void flag_a(char* arguments[])
{
   /*
   -a Criteria:                                                       STATUS
   - any odd number of repetitions of the letter “b”;             --> DONE
   - exactly one “_”;                                             --> DONE
   - between 3 and 7 repetitions (inclusive) of the letter “t”;   --> DONE
   - exactly two “=”s; and                                        --> DONE
   - an odd number of uppercase letters.                          --> DONE
   */


   //Counters
   int letterBRepCounter      = 0;
   int underscoreCounter      = 0;
   int letterTCounter         = 0;
   int characterEqualsCounter = 0;
   int upperCaseCount         = 0;

   int should_continue        = 1; //1 = true, 0 = false


   //Handle each argument individually
   int index;
   for (index = 0; index < sizeof(arguments); index++)
   {
     //stop if there are no more arguments
     if (arguments[index] == "empty") { break; }

     //This should grab the current 'string' and place it into an array of characters?
     char* currentArgument = arguments[index];

     char* currentCharacater; // first copy the pointer to not change the original

    //check if first character is not b
    if (*currentArgument != 'b')
    {
      printf("no\n");
      printf("initial check\n" );
    }
    else {
      //iterate through each character in order to check the Criteria.
      //Update: as we are iterating, we will be checking the previous character. This
      //will allow us to maintain the order of events.
      for (currentCharacater = currentArgument; *currentCharacater != '\0'; currentCharacater++)
      {

         //Update the letterBRepCounter
         if (*currentCharacater == 'b')
         {
           letterBRepCounter++;
         }
         //Update the underscoreCounter variable.
         else if (*currentCharacater == '_')
         {

           //we know that b should be done at this point. Check it's truthfulness.
           if (letterBRepCounter%2 == 0) //If even
           {
             printf("no\n");
             printf("1\n");
             should_continue = 0;
             break;
           }

           underscoreCounter++;
         }

         else if (*currentCharacater == 't')
         {

           //We know that _ should be done. Check it's truthfulness.
           if (underscoreCounter == 0)
           {
             printf("no\n");
             printf("2\n");
             should_continue = 0;
             break;
           }
           else if (underscoreCounter > 1)
           {
              printf("no\n");
              printf("3\n");
              should_continue = 0;
              break;
           }

           letterTCounter++;
         }
         else if (*currentCharacater == '=')
         {

           //Check t.
           if (letterTCounter > 7)
           {
             printf("no\n");
             printf("4\n");
             should_continue = 0;
             break;
           }
           else if (letterTCounter < 3)
           {
             printf("no\n");
             printf("5\n");
             should_continue = 0;
             break;
           }


           characterEqualsCounter++;
         }
         else if (*currentCharacater >= 65 && *currentCharacater <= 90) { //ASCII chart

           //check equals
           if (characterEqualsCounter != 2)
           {
             printf("no\n");
             printf("6\n");
             should_continue = 0;
             break;
           }

           upperCaseCount++;
         }
         else {
           //this means a bad character was in the string
           printf("no\n");
           printf("Bad character\n");
           should_continue = 0;
           break;
         }
      }


      if (should_continue != 0)
      {
        if (upperCaseCount%2 == 0) //If even
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
   }

}

void flag_b(char* arguments[])
{
  /*
  -b Criteria:
    -any even number (including zero) repetitions of the letter “b”;
    -exactly two “:”s;
    -between 1 and 3 (inclusive) decimal digits — call this sequence X;
    -between 3 and 7 repetitions (inclusive) of the letter “q”;
    -exactly one “=”;
    -the same characters as the even-positioned characters in X; and
    -an odd number of uppercase letters.
  */

  //This will be used to track if we are on sequence x or sequence y.
  int sequence = 0;

  //Counters
  int letterBCounter         = 0;
  int colonCounter           = 0;
  char* sequenceX            = "";
  int sequenceXCounter       = 0;
  int letterQCounter         = 0;
  int equalsCounter          = 0;
  char* sequenceY            = "";
  int upperCaseCount         = 0;


  int should_continue        = 1; //1 = true, 0 = false


  //Handle each argument individually
  int index;
  for (index = 0; index < sizeof(arguments); index++)
  {


    //stop if there are no more arguments
    if (arguments[index] == "empty") { break; }

    char* currentArgument = arguments[index];

    char* currentCharacater; // first copy the pointer to not change the original

   //check if first character is not b
   if (*currentArgument != 'b')
   {
     printf("no\n");
     printf("initial check\n" );
   }
   else
   {
     //iterate through each character in order to check the Criteria.
     //Update: as we are iterating, we will be checking the previous character. This
     //will allow us to maintain the order of events.
     for (currentCharacater = currentArgument; *currentCharacater != '\0'; currentCharacater++)
     {
        //Update the letterBCounter
        if (*currentCharacater == 'b')
        {
          letterBCounter++;
        }
        //Update the colon character
        else if (*currentCharacater == ':')
        {

          //we know that b should be done at this point. Check it's truthfulness.
          if (letterBCounter%2 != 0) //If odd
          {
            printf("no\n");
            printf("1\n");
            should_continue = 0;
            break;
          }

          colonCounter++;
        }
        //update sequence X TODO: verify that this works?
        else if (*currentCharacater >= 48 && *currentCharacater <= 57 && sequence == 0) //This means it's a digit
        {


          //We know that the colon character should be done. Check it's truthfulness.
          if (colonCounter != 2)
          {
            printf("no\n");
            printf("2\n");
            should_continue = 0;
            break;
          }

          sequenceXCounter++;
          printf("Adding this to sequenceX: %d\n", *currentCharacater);
          sequenceX += *currentCharacater; //TODO: verify This works
        }
        else if (*currentCharacater == 'q')
        {
          sequence = 1;

          if (sequenceXCounter > 3)
          {
            printf("no\n");
            printf("3\n");
            should_continue = 0;
            break;
          }
          else if (sequenceXCounter < 1)
          {
            printf("no\n");
            printf("4\n");
            should_continue = 0;
            break;
          }

          letterQCounter++;
        }
        else if (*currentCharacater == '=')
        {

          //check equals
          if (letterQCounter > 7)
          {
            printf("no\n");
            printf("6\n");
            should_continue = 0;
            break;
          }
          else if (letterQCounter < 3)
          {
            printf("no\n");
            printf("7\n");
            should_continue = 0;
            break;
          }

          equalsCounter++;
        }
        else if (*currentCharacater >= 48 && *currentCharacater <= 57 && sequence == 1) //checking sequence y
        {
          if (equalsCounter!= 1)
          {
            printf("no\n");
            printf("8\n");
            should_continue = 0;
            break;
          }

          printf("Adding this to sequenceY: %d\n", *currentCharacater);
          sequenceY += *currentCharacater;
        }
        else if (*currentCharacater >= 65 && *currentCharacater <= 90) //uppercase
        {
            //now we can check the sequences
            //iterate through sequence x, but only checking odds

            // char* sequenceXCopy = sequenceX;
            char* currentDigit; // first copy the pointer to not change the original

            char* newSequenceX = "";

            //TODO: FIX THIS!!!!!! How to create a new string with only odd indecies?
            int counter = 0;
            for (currentDigit = &sequenceX; *currentDigit != '\0'; currentDigit++)
            {
              if (counter % 2 == 0) //only touch the even ones
              {
                newSequenceX += *currentDigit;
                printf("adding to newSequenceX: %d\n",*currentDigit );
              }
              counter++;
            }


            //then, we compare
            if (strcmp(newSequenceX,sequenceY) != 0) //if they're not a match
            {
              printf("no\n");
              printf("9\n");
              should_continue = 0;
              break;
            }
            upperCaseCount++;
        }
        else
        {
          //this means a bad character was in the string
          printf("no\n");
          printf("current character %d\n", *currentCharacater);

          // printf("Bad character%s\n", *currentCharacater);
          should_continue = 0;
          break;
        }
     }


     if (should_continue != 0)
     {
       if (upperCaseCount%2 == 0) //If even
       {
         printf("no\n");
         printf("7\n");
       }
       //Since it has passed all of these tests, we know it's matching so we
       //print yes!
       else
       {
         printf("yes\n");

         // printf("stats:\n");
         // printf("letterBRepCounter %d\n", letterBRepCounter);
         // printf("underscoreCounter %d\n", underscoreCounter);
         // printf("letterTCounter %d\n", letterTCounter);
         // printf("characterEqualsCounter %d\n", characterEqualsCounter);
         // printf("upperCaseCount %d\n", upperCaseCount);
       }
     }
   }
  }
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
