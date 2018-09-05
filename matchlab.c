#include <stdio.h>
#include <string.h>



void flag_a(char* arguments[], int tFlag)
{
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
     if (arguments[index] == "empty") { break;}

     //This should grab the current 'string' and place it into an array of characters?
     char* currentArgument = arguments[index];

     char* currentCharacater; // first copy the pointer to not change the original

     char newArgument[50] = {0}; //we can pick a large number because we know it can't exceed these.

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
          if (tFlag == 0) //We're not transforming
          {
            printf("yes\n");
          }
          else {
            printf("Current arg: %s\n", currentArgument);

            char* pointer = currentArgument;

            while (*pointer != '\0')
            {
              printf("%c\n", *pointer);
              pointer++;
            }
          }

        }
      }
    }
   }

}

void flag_b(char* arguments[], int tFlag)
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
  char sequenceX[3]          = {0};  //3 because it can't be any bigger than this!
  int sequenceXCounter       = 0;
  int letterQCounter         = 0;
  int equalsCounter          = 0;
  char sequenceY[2]          = {0}; //2 because it can't be any bigger than this! 9
  int sequenceYCounter       = 0;
  int upperCaseCount         = 0;
  char newSequenceX[2]       = {0};

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
        else if (*currentCharacater >= 48 && *currentCharacater <= 57 && sequence == 0) //This means it's a digit
        {
          //Attempting to stop a seg fault before it happens.
          if (sequenceXCounter >=3)
          {
            printf("no\n");
            printf("too many digits. Trying to stop seg fault\n");
            should_continue = 0;
            break;
          }

          //We know that the colon character should be done. Check it's truthfulness.
          if (colonCounter != 2)
          {
            printf("no\n");
            printf("2\n");
            should_continue = 0;
            break;
          }

          printf("Adding this to sequenceX: %d\n", *currentCharacater);
          sequenceX[sequenceXCounter] = *currentCharacater;
          sequenceXCounter++;

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

          //Attempting to stop a seg fault before it happens.
          if (sequenceYCounter >= 2)
          {
            printf("no\n");
            printf("too many digits. Trying to stop seg fault for 'y'\n");
            should_continue = 0;
            break;
          }

          if (equalsCounter!= 1)
          {
            printf("no\n");
            printf("8\n");
            should_continue = 0;
            break;
          }

          printf("Adding this to sequenceY: %d\n", *currentCharacater);
          sequenceY[sequenceYCounter] = *currentCharacater;

          sequenceYCounter++;
        }
        else if (*currentCharacater >= 65 && *currentCharacater <= 90) //uppercase
        {
            //now we can check the sequences
            //iterate through sequence x, but only checking odds


            if (sequenceX[0] != '\0')
            {
              newSequenceX[0] = sequenceX[0];
            }
            if (sequenceX[2] != '\0')
            {
              newSequenceX[1] = sequenceX[2];
            }



            //then, we compare
            if (newSequenceX[0] != sequenceY[0]) //if they're not a match
            {
              printf("no\n");
              printf("9\n");

              should_continue = 0;
              break;
            }
            if (newSequenceX[1] != sequenceY[1]) //if they're not a match
            {
              printf("no\n");
              printf("10\n");

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
       }
     }
   }
  }
}

void flag_c(char* arguments[], int tFlag)
{


  //This will be used to track if we are on sequence x or sequence y.
  int sequence = 0;

  //Counters
  int letterDCounter         = 0;
  int equalsCounter          = 0;

  char sequenceX[3]          = {0};  //3 because it can't be any bigger than this!
  int sequenceXCounter       = 0;

  int letterUCounter         = 0;

  int underscoreCounter      = 0;
  char sequenceY[3]          = {0}; //2 because it can't be any bigger than this! 9
  int sequenceYCounter       = 0;

  int upperCaseCount         = 0;

  char newSequenceX[3]       = {0};

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
   if (*currentArgument != 'd' && *currentArgument != '=')
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
        if (*currentCharacater == 'd')
        {
          letterDCounter++;
        }
        //Update the colon character
        else if (*currentCharacater == '=')
        {

          //we know that b should be done at this point. Check it's truthfulness.
          if (letterDCounter%2 != 0) //If odd
          {
            printf("no\n");
            printf("1\n");
            should_continue = 0;
            break;
          }

          equalsCounter++;
        }
        else if (*currentCharacater >= 48 && *currentCharacater <= 57 && sequence == 0) //This means it's a digit
        {
          //Attempting to stop a seg fault before it happens.
          if (sequenceXCounter >=3)
          {
            printf("no\n");
            printf("too many digits. Trying to stop seg fault\n");
            should_continue = 0;
            break;
          }

          //We know that the colon character should be done. Check it's truthfulness.
          if (equalsCounter != 1)
          {
            printf("no\n");
            printf("2\n");
            should_continue = 0;
            break;
          }

          printf("Adding this to sequenceX: %d\n", *currentCharacater);
          sequenceX[sequenceXCounter] = *currentCharacater;
          sequenceXCounter++;

        }
        else if (*currentCharacater == 'u')
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

          letterUCounter++;
        }
        else if (*currentCharacater == '_')
        {

          //check equals
          if (letterUCounter == 0)
          {
            printf("no\n");
            printf("6\n");
            should_continue = 0;
            break;
          }


          underscoreCounter++;
        }
        else if (*currentCharacater >= 48 && *currentCharacater <= 57 && sequence == 1) //checking sequence y
        {

          //Attempting to stop a seg fault before it happens.
          if (sequenceYCounter >= 3)
          {
            printf("no\n");
            printf("too many digits. Trying to stop seg fault for 'y'\n");
            should_continue = 0;
            break;
          }

          if (underscoreCounter != 1)
          {
            printf("no\n");
            printf("8\n");
            should_continue = 0;
            break;
          }

          printf("Adding this to sequenceY: %d\n", *currentCharacater);
          sequenceY[sequenceYCounter] = *currentCharacater;
          sequenceYCounter++;
        }
        else if (*currentCharacater >= 65 && *currentCharacater <= 90) //uppercase
        {
            //now we can check the sequences

            if (sequenceXCounter == 3)
            {
              //then, we compare
              if (sequenceX[0] != sequenceY[2]) //if they're not a match
              {
                printf("no\n");
                printf("9\n");
                should_continue = 0;
                break;
              }
              if (sequenceX[1] != sequenceY[1]) //if they're not a match
              {
                printf("no\n");
                printf("10\n");

                should_continue = 0;
                break;
              }
              if (sequenceX[2] != sequenceY[0]) //if they're not a match
              {
                printf("no\n");
                printf("11\n");

                should_continue = 0;
                break;
              }
            }
            else if (sequenceXCounter == 2)
            {
              if (sequenceX[0] != sequenceY[1]) //if they're not a match
              {
                printf("no\n");
                printf("12\n");
                should_continue = 0;
                break;
              }
              if (sequenceX[1] != sequenceY[0]) //if they're not a match
              {
                printf("no\n");
                printf("13\n");
                should_continue = 0;
                break;
              }
            }
            else if (sequenceXCounter == 1)
            {
              if (sequenceX[0] != sequenceY[0]) //if they're not a match
              {
                printf("no\n");
                printf("14\n");
                should_continue = 0;
                break;
              }
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
       }
     }
   }
  }
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


  //At this point, we have the correct flags set, and the arguments stored in an array to process.
  if (flag == 'a')       { flag_a(args, tFlagWasSet); }
  else if (flag == 'b')  { flag_b(args, tFlagWasSet); }
  else if (flag == 'c')  { flag_c(args, tFlagWasSet); }


  return 0;
}
