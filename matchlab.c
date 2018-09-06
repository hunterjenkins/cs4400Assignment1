#include <stdio.h>
#include <string.h>

//Hunter Jenkins

void flag_a(char* arguments[], int tFlag)
{


   //Handle each argument individually
   int index;
   for (index = 0; index < sizeof(arguments); index++)
   {

     //Counters
     int letterBRepCounter      = 0;
     int underscoreCounter      = 0;
     int letterTCounter         = 0;
     int characterEqualsCounter = 0;
     int upperCaseCount         = 0;

     int should_continue        = 1; //1 = true, 0 = false


     //stop if there are no more arguments
     if (arguments[index] == "empty") { break;}


     //This should grab the current 'string' and place it into an array of characters?
     char* currentArgument = arguments[index];

     printf("current argument %s\n", currentArgument );

     char* currentCharacater; // first copy the pointer to not change the original

     char newArgument[50] = {0}; //we can pick a large number because we know it can't exceed these.

    //check if first character is not b
    if (*currentArgument != 'b')
    {
      if (tFlag == 0)
      {
        printf("no\n");
      }

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
             if (tFlag == 0)
             {
               printf("no\n");
             }

             should_continue = 0;
             continue;
           }

           underscoreCounter++;
         }

         else if (*currentCharacater == 't')
         {

           //We know that _ should be done. Check it's truthfulness.
           if (underscoreCounter == 0)
           {
             if (tFlag == 0)
             {
               printf("no\n");
             }

             should_continue = 0;
             continue;
           }
           else if (underscoreCounter > 1)
           {
             if (tFlag == 0)
             {
               printf("no\n");
             }

              should_continue = 0;
              continue;
           }

           letterTCounter++;
         }
         else if (*currentCharacater == '=')
         {

           //Check t.
           if (letterTCounter > 7)
           {
             if (tFlag == 0)
             {
               printf("no\n");
             }

             should_continue = 0;
             continue;
           }
           else if (letterTCounter < 3)
           {
             if (tFlag == 0)
             {
               printf("no\n");
             }

             should_continue = 0;
             continue;
           }


           characterEqualsCounter++;
         }
         else if (*currentCharacater >= 65 && *currentCharacater <= 90) { //ASCII chart

           //check equals
           if (characterEqualsCounter != 2)
           {
             if (tFlag == 0){
               printf("no\n");
             }

             should_continue = 0;
             continue;
           }

           upperCaseCount++;
         }
         else {
           //this means a bad character was in the string
           if (tFlag == 0)
           {
             printf("no\n");
           }

           should_continue = 0;
           continue;
         }
      }


      if (should_continue != 0)
      {
        if (upperCaseCount%2 == 0) //If even
        {
          if (tFlag == 0)
          {
            printf("no\n");
          }

        }
        //Since it has passed all of these tests, we know it's matching so we
        //print yes!
        else {
          if (tFlag == 0) //We're not transforming
          {
            printf("yes\n");
          }
          else {

            char* pointer = currentArgument;
	    int sizeOfString = 0;

            while (*pointer != '\0')
            {
	      sizeOfString++;
               pointer++;
            }

	    char* newPointer = currentArgument;
	    char first = newPointer[0];

	    int index; //Start on last index
	    for (index = 0; index < sizeOfString-1; index++)
	    {
	      newPointer[index] = newPointer[index+1];
	    }
	    newPointer[sizeOfString-1] = first;

	    printf("%s\n", newPointer);

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




  //Handle each argument individually
  int index;
  for (index = 0; index < sizeof(arguments); index++)
  {
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

    //stop if there are no more arguments
    if (arguments[index] == "empty") { break; }

    char* currentArgument = arguments[index];

    char* currentCharacater; // first copy the pointer to not change the original

   //check if first character is not b
   if (*currentArgument != 'b')
   {
     if (tFlag == 0)
     {
       printf("no\n");
     }

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
            if (tFlag == 0)
            {
              printf("no\n");
            }

            should_continue = 0;
            continue;
          }

          colonCounter++;
        }
        else if (*currentCharacater >= 48 && *currentCharacater <= 57 && sequence == 0) //This means it's a digit
        {
          //Attempting to stop a seg fault before it happens.
          if (sequenceXCounter >=3)
          {
            if (tFlag == 0)
            {
              printf("no\n");
            }

            should_continue = 0;
            continue;
          }

          //We know that the colon character should be done. Check it's truthfulness.
          if (colonCounter != 2)
          {
            if (tFlag == 0)
            {
              printf("no\n");
            }

            should_continue = 0;
            continue;
          }

          sequenceX[sequenceXCounter] = *currentCharacater;
          sequenceXCounter++;

        }
        else if (*currentCharacater == 'q')
        {
          sequence = 1;

          if (sequenceXCounter > 3)
          {
            if (tFlag == 0)
            {
              printf("no\n");
            }

            should_continue = 0;
            continue;
          }
          else if (sequenceXCounter < 1)
          {
            if (tFlag == 0)
            {
              printf("no\n");
            }

            should_continue = 0;
            continue;
          }

          letterQCounter++;
        }
        else if (*currentCharacater == '=')
        {

          //check equals
          if (letterQCounter > 7)
          {
            if (tFlag == 0)
            {
              printf("no\n");
            }

            should_continue = 0;
            continue;
          }
          else if (letterQCounter < 3)
          {
            if (tFlag == 0)
            {
              printf("no\n");
            }

            should_continue = 0;
            continue;
          }

          equalsCounter++;
        }
        else if (*currentCharacater >= 48 && *currentCharacater <= 57 && sequence == 1) //checking sequence y
        {

          //Attempting to stop a seg fault before it happens.
          if (sequenceYCounter >= 2)
          {
            if (tFlag == 0)
            {
              printf("no\n");
            }

            should_continue = 0;
            continue;
          }

          if (equalsCounter!= 1)
          {
            if (tFlag == 0)
            {
              printf("no\n");
            }

            should_continue = 0;
            continue;
          }

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
              if (tFlag == 0)
              {
                printf("no\n");
              }

              should_continue = 0;
              continue;
            }
            if (newSequenceX[1] != sequenceY[1]) //if they're not a match
            {
              if (tFlag == 0)
              {
                printf("no\n");
              }

              should_continue = 0;
              continue;
            }
            upperCaseCount++;
        }
        else
        {
          if (tFlag == 0)
          {
            printf("no\n");
          }

          // printf("Bad character%s\n", *currentCharacater);
          should_continue = 0;
          continue;
        }
     }


     if (should_continue != 0)
     {
       if (upperCaseCount%2 == 0) //If even
       {
         if (tFlag == 0)
         {
           printf("no\n");
         }

       }
       //Since it has passed all of these tests, we know it's matching so we
       //print yes!
       else
       {
	 if (tFlag == 0)
	 {
	   printf("yes\n");
	 }
	 else
	 {
	   //Do the conversion
	   char*pointer = currentArgument;
	   int sizeOfString = 0;
	   int Acounter = 0;

	   //Gather the size of the array with how many A's there are.
	   while (*pointer != '\0')
	   {
	     if (*pointer == 'A')
	     {
	       Acounter++;
	     }
	     sizeOfString++;
	     pointer++;
	   }

	   char * newPointer = currentArgument;
	   int size = sizeOfString + Acounter;
	   char arrayString[size];
	   memset(arrayString, 0, sizeOfString+Acounter);

	   int index;
	   int arrayStringIndex = 0;
	   for (index = 0; index < sizeOfString; index++)
	   {

	     if (*newPointer == 'A')
	     {
	       arrayString[arrayStringIndex] = 'F';
	       arrayStringIndex++;
	       arrayString[arrayStringIndex] = 'A';
	     }
	     else
	     {
	       arrayString[arrayStringIndex] = *newPointer;
	     }
	     arrayStringIndex++;
	     newPointer++;
	   }
	   printf("%s\n", arrayString);

	 }

       }
     }
   }
  }
}

void flag_c(char* arguments[], int tFlag)
{





  //Handle each argument individually
  int index;
  for (index = 0; index < sizeof(arguments); index++)
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

    //stop if there are no more arguments
    if (arguments[index] == "empty") { break; }

    char* currentArgument = arguments[index];

    char* currentCharacater; // first copy the pointer to not change the original

   //check if first character is not b
   if (*currentArgument != 'd' && *currentArgument != '=')
   {
     if (tFlag == 0)
     {
       printf("no\n");
     }
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
            should_continue = 0;
            continue;
          }

          equalsCounter++;
        }
        else if (*currentCharacater >= 48 && *currentCharacater <= 57 && sequence == 0) //This means it's a digit
        {
          //Attempting to stop a seg fault before it happens.
          if (sequenceXCounter >=3)
          {
            printf("no\n");
            should_continue = 0;
            continue;
          }

          //We know that the colon character should be done. Check it's truthfulness.
          if (equalsCounter != 1)
          {
            printf("no\n");
            printf("2\n");
            should_continue = 0;
            continue;
          }

          sequenceX[sequenceXCounter] = *currentCharacater;
          sequenceXCounter++;

        }
        else if (*currentCharacater == 'u')
        {
          sequence = 1;

          if (sequenceXCounter > 3)
          {
            printf("no\n");
            should_continue = 0;
            continue;
          }
          else if (sequenceXCounter < 1)
          {
            printf("no\n");
            should_continue = 0;
            continue;
          }

          letterUCounter++;
        }
        else if (*currentCharacater == '_')
        {

          //check equals
          if (letterUCounter == 0)
          {
            printf("no\n");
            should_continue = 0;
            continue;
          }


          underscoreCounter++;
        }
        else if (*currentCharacater >= 48 && *currentCharacater <= 57 && sequence == 1) //checking sequence y
        {

          //Attempting to stop a seg fault before it happens.
          if (sequenceYCounter >= 3)
          {
            printf("no\n");
            should_continue = 0;
            continue;
          }

          if (underscoreCounter != 1)
          {
            printf("no\n");
            should_continue = 0;
            continue;
          }

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
                should_continue = 0;
                continue;
              }
              if (sequenceX[1] != sequenceY[1]) //if they're not a match
              {
                printf("no\n");

                should_continue = 0;
                continue;
              }
              if (sequenceX[2] != sequenceY[0]) //if they're not a match
              {
                printf("no\n");

                should_continue = 0;
                continue;
              }
            }
            else if (sequenceXCounter == 2)
            {
              if (sequenceX[0] != sequenceY[1]) //if they're not a match
              {
                printf("no\n");
                should_continue = 0;
                continue;
              }
              if (sequenceX[1] != sequenceY[0]) //if they're not a match
              {
                printf("no\n");
                should_continue = 0;
                continue;
              }
            }
            else if (sequenceXCounter == 1)
            {
              if (sequenceX[0] != sequenceY[0]) //if they're not a match
              {
                printf("no\n");
                should_continue = 0;
                continue;
              }
            }


            upperCaseCount++;
        }
        else
        {
          //this means a bad character was in the string
          printf("no\n");

          // printf("Bad character%s\n", *currentCharacater);
          should_continue = 0;
          continue;
        }
     }


     if (should_continue != 0)
     {
       if (upperCaseCount%2 == 0) //If even
       {
         printf("no\n");
       }
       //Since it has passed all of these tests, we know it's matching so we
       //print yes!
       else
       {
	 if (tFlag == 0)
	 {
	   printf("yes\n");
	 }
	 else
	 {
	   //Do the conversion
	   char*pointer = currentArgument;
	   int sizeOfString = 0;
	   int letterCounter = 0; //A + E;

	   //Gather the size of the array with how many A's and E's there are.
	   while (*pointer != '\0')
	   {
	     if (*pointer == 'A' || *pointer == 'E')
	     {
	       letterCounter++;
	     }
	     sizeOfString++;
	     pointer++;
	   }

	   char * newPointer = currentArgument;
	   int size = sizeOfString - letterCounter;
	   char arrayString[size];
	   memset(arrayString, 0, sizeOfString-letterCounter);


	   int index;
	   int arrayStringIndex = 0;
	   for (index = 0; index < sizeOfString; index++)
	   {
	     if (*newPointer == 'A' || *newPointer == 'E')
	     {
	       //Do nothing
	     }
	     else
	     {
	       arrayString[arrayStringIndex] = *newPointer;
	       arrayStringIndex++;
	     }
	     newPointer++;
	   }
	   printf("%s\n", arrayString);



	 }

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
