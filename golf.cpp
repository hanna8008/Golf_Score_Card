/*
Hanna Zelis
CSC1710 - 01
5/5/2021

This program creates a scorecard for one golf round with four players.

The first thing done was take the 18 hold pars, four player's names, and their 
scores for each round from a datafile and read them into the program.

Next, I was able to print the players scores (in addition to their 9-subtotal scores
for the first and the last 9 holes in parentheses). 

Then, whoever had the smallest amount of strokes from the 18-holes was the winner and
the output shows how close they were to a perfect par (the total of all 18-hold
par scores). This could be shown through a positive, negative, or nothing because they
got exactly a perfect par number).

Next, I outputed a table with the 18 holes of golf and the player's name and lined
them up accordingly in which at the end of the table you can see each players final scores.
 
Finally, I was able to determine that if there was a tie breaker, the program
would evaluate the number of birdies and eagles. If one player had more birdies than
another, then they won. However, if the number of birdies were tied too, then the number
of eagles each player had was evaluated. Whoever had more eagles won. However, if the 
number of eagles were a tie too, then the computer said that it could not longer
evlauate scores and that if they really wanted a tie breaker they would play one more
round of golf or they could just accept that they tied and both won.
*/








#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>








using namespace std;








//Function prototype: total par after 18 rounds
int totalPar(int par[]);


//Function prototype player one's total strokes
int playerOneStrokes(char one[], char two[], char three[], char four[], char five[], char six[],
    char seven[], char eight[], char nine[], char ten[], char eleven[], char twelve[], char thirteen[],
    char fourteen[], char fifteen[], char sixteen[], char seventeen[], char eighteen[]); 


//Function prototype: player two's total strokes
int playerTwoStrokes(char one[], char two[], char three[], char four[], char five[], char six[],
    char seven[], char eight[], char nine[], char ten[], char eleven[], char twelve[], char thirteen[],
    char fourteen[], char fifteen[], char sixteen[], char seventeen[], char eighteen[]);


//Function prototype: player three's total strokes
int playerThreeStrokes(char one[], char two[], char three[], char four[], char five[], char six[],
    char seven[], char eight[], char nine[], char ten[], char eleven[], char twelve[], char thirteen[],
    char fourteen[], char fifteen[], char sixteen[], char seventeen[], char eighteen[]);


//Function prototype: player four's total strokes
int playerFourStrokes(char one[], char two[], char three[], char four[], char five[], char six[],
    char seven[], char eight[], char nine[], char ten[], char eleven[], char twelve[], char thirteen[],
    char fourteen[], char fifteen[], char sixteen[], char seventeen[], char eighteen[]);


//Function prototype: determine the winner and determine winner of tie breaker if necessary
void winner(string people[], int one, int two, int three, int four, int perfectParFun, int personOneBirdie, 
     int personTwoBirdie, int personThreeBirdie, int personFourBirdie, int personOneEagle, int personTwoEagle,
     int personThreeEagle, int personFourEagle);


//Function prototype: calculate 9-hole subtotal
void nineHoles(string people[], char one[], char two[], char three[], char four[], char five[], char six[], 
     char seven[], char eight[], char nine[], char ten[], char eleven[], char twelve[], char thirteen[],
     char fourteen[], char fifteen[], char sixteen[], char seventeen[], char eighteen[], int oneTotal,
     int twoTotal, int threeTotal, int fourTotal);










int main()
{


  //Inputting data from the datafile golfData.txt
  ifstream indata;
  indata.open("golfData.txt");


  //If for some reason the program isn't able to read in the file, the program will output this message
  if (!indata)
    cout << "Error: file could not be opened" << endl;



  




  //Informing user of tie breaker rule for this program

  cout << "This program is designed for golf holes with pars and strokes >= 0 and <= 9" << endl;

  cout << endl;
  cout << endl;

  cout << "For a tie breaker, the amount of birdies and eagles are evaluated. " << endl;
  cout << "Birdies will be considered first and then the eagles (if birdies are tied)." << endl;
  cout << "If birdies and eagles are tied, the program will declare both players a winner." << endl;
  cout << endl;
  cout << "If you do not want a tie between people, feel free to do one more hole on your own." << endl;
  cout << "Whoever gets less strokes for the extra hole is the winner!" << endl;




  cout << endl;
  cout << endl;




  //Delcaring variables
  int i;
  int holeParValues[18]; //array associated with holding the par values for each of the 18 holes in order
  string players[4]; //array that holds the name of the four players


  int perfectPar; //declared int that holds the result of the function that adds up all the par values


  //Arrays that hold each of the four player's strokes in each hole in the same order
  char holeOne[4];
  char holeTwo[4];
  char holeThree[4];
  char holeFour[4];
  char holeFive[4];
  char holeSix[4]; 
  char holeSeven[4];
  char holeEight[4];
  char holeNine[4];
  char holeTen[4];
  char holeEleven[4];
  char holeTwelve[4];
  char holeThirteen[4];
  char holeFourteen[4];
  char holeFifteen[4];
  char holeSixteen[4];
  char holeSeventeen[4];
  char holeEighteen[4];

  
  //The integer that holds the results from the functions that added up the player's number of strokes from the arrays above
  int playerOneTotalStrokes;
  int playerTwoTotalStrokes;
  int playerThreeTotalStrokes;
  int playerFourTotalStrokes;








  //reading in the par values for each hole into its own array
  for (i = 0; i < 18; i++)
    indata >> holeParValues[i];








  //reading in the names of the players into c-string array
  for (i = 0; i < 4; i++) 
    indata >> players[i];








//Each hole has its own array with its own set of results

  //reading in the results from hole one
  for (i = 0; i < 4; i++)
    indata >> holeOne[i];

 
  //reading in hole two results
  for (i = 0; i < 4; i++)
    indata >> holeTwo[i];
 
  
  //reading in hole three results
  for (i = 0; i < 4; i++)
    indata >> holeThree[i];

  
  //reading in hole four results
  for (i = 0; i < 4; i++)
    indata >> holeFour[i];
  

  //reading in hole five results
  for (i = 0; i < 4; i++)
    indata >> holeFive[i];


  //reading in hole six result
  for (i = 0; i < 4; i++)
    indata >> holeSix[i];


  //reading in hole seven results
  for (i = 0; i < 4; i++)
    indata >> holeSeven[i];


  //reading in hole eight results
  for (i = 0; i < 4; i++)
    indata >> holeEight[i];


  //reading in hole 9 results
  for (i = 0; i < 4; i++)
    indata >> holeNine[i];


  //reading in hole 10 results
  for (i = 0; i < 4; i++)
    indata >> holeTen[i];


  //reading in hole 11 results
  for (i = 0; i < 4; i++)
    indata >> holeEleven[i];


  //reading in hole 12 results
  for (i = 0; i < 4; i++)
    indata >> holeTwelve[i];

 
  //reading in hole 13 results
  for (i = 0; i < 4; i++)
    indata >> holeThirteen[i];


  //reading in hole 14 resutls
  for (i = 0; i < 4; i++)
    indata >> holeFourteen[i];


  //reading in hole 15 results
  for (i = 0; i < 4; i++)
    indata >> holeFifteen[i];


  //reading in hole 16 results
  for (i = 0; i < 4; i++)
    indata >> holeSixteen[i];


  //reading in hole 17 results
  for (i = 0; i < 4; i++)
    indata >> holeSeventeen[i];


  //reading in hole 18 results
  for (i = 0; i < 4; i++)
    indata >> holeEighteen[i];


  //Closing the data file as all values necessary have been accessed from the golfData.txt file
  indata.close();





  //Putting player one's total number of strikes into a variable
  playerOneTotalStrokes = playerOneStrokes(holeOne, holeTwo, holeThree, holeFour, holeFive, holeSix, holeSeven, holeEight, holeNine, holeTen, holeEleven, holeTwelve, holeThirteen, holeFourteen, holeFifteen, holeSixteen, holeSeventeen, holeEighteen);





  //Putting player two's total number of strikes into a variable
  playerTwoTotalStrokes = playerTwoStrokes(holeOne, holeTwo, holeThree, holeFour, holeFive, holeSix, holeSeven, holeEight, holeNine, holeTen, holeEleven, holeTwelve, holeThirteen, holeFourteen, holeFifteen, holeSixteen, holeSeventeen, holeEighteen);
 




  //Putting player three's total number of strikes into a variable
  playerThreeTotalStrokes = playerThreeStrokes(holeOne, holeTwo, holeThree, holeFour, holeFive, holeSix, holeSeven, holeEight, holeNine, holeTen, holeEleven, holeTwelve, holeThirteen, holeFourteen, holeFifteen, holeSixteen, holeSeventeen, holeEighteen);





  //Putting player four's total number of strikes into a variable
  playerFourTotalStrokes = playerFourStrokes(holeOne, holeTwo, holeThree, holeFour, holeFive, holeSix, holeSeven, holeEight, holeNine, holeTen, holeEleven, holeTwelve, holeThirteen, holeFourteen, holeFifteen, holeSixteen, holeSeventeen, holeEighteen);








  //Putting the total par after 18 holes into a variable
  perfectPar = totalPar(holeParValues);




/* 
   In order to add a * or ! for the output to show birdies and eagles, I decided to use the following variables
   and arrays in order to create a new array to export. If there was a birdie or eagle, its correlating symbol
   would be added to the number corresponding in the original 18 hole arrays that hold each player's results for 
   each round. These new arrays would then be used in the output of the program.
*/

  string oneB;
  string oneE;
  string birdieEagleHoleOne[5];

  string twoB;
  string twoE;
  string birdieEagleHoleTwo[5];

  string threeB;
  string threeE;
  string birdieEagleHoleThree[5]; 

  string fourB;
  string fourE;
  string birdieEagleHoleFour[5];

  string fiveB;
  string fiveE;
  string birdieEagleHoleFive[5];

  string sixB;
  string sixE;
  string birdieEagleHoleSix[5];

  string sevenB;
  string sevenE;
  string birdieEagleHoleSeven[5];

  string eightB;
  string eightE;
  string birdieEagleHoleEight[5];

  string nineB;
  string nineE;
  string birdieEagleHoleNine[5];

  string tenB;
  string tenE;
  string birdieEagleHoleTen[5];

  string elevenB;
  string elevenE;
  string birdieEagleHoleEleven[5];

  string twelveB;
  string twelveE;
  string birdieEagleHoleTwelve[5];

  string thirteenB;
  string thirteenE;
  string birdieEagleHoleThirteen[5];

  string fourteenB;
  string fourteenE;
  string birdieEagleHoleFourteen[5];

  string fifteenB;
  string fifteenE;
  string birdieEagleHoleFifteen[5];

  string sixteenB;
  string sixteenE;
  string birdieEagleHoleSixteen[5];

  string seventeenB;
  string seventeenE;
  string birdieEagleHoleSeventeen[5];

  string eighteenB;
  string eighteenE;
  string birdieEagleHoleEighteen[5];








  //Helps show what variable correspondings with what character and the variable would be used to help update the new array 
  char birdie = '*';
  char eagle = '!';
  int x;


  //Helped count the number of birdies each player had
  int playerOneBirdie = 0;
  int playerTwoBirdie = 0;
  int playerThreeBirdie = 0;
  int playerFourBirdie = 0;


  //Helped count the number of eagles each player had    
  int playerOneEagle = 0;
  int playerTwoEagle = 0;
  int playerThreeEagle = 0;
  int playerFourEagle = 0;

  



/*
   I could not find a way to update the varaibles as I go with a counter, so, I had to replicate this following code 
   that updates the birdies and eagles with its appropriate symbol to a new array for each hole. 
   If there is a birdie and/or eagle, each player's corresponding birdie and/or eagle variable counters would be updated
*/



  //Update the output so if in the first round any one has a birdie or eagle, there correlating symbol will also be outputted
    for (i = 0; i < 4; i++)
    {
      if (((static_cast<int>(holeOne[i])) - 48) == (holeParValues[0] - 1))
      {
        char combineBirdie[3];
        combineBirdie[1] = holeOne[i];
        combineBirdie[0] = birdie;
          for (x = 0; x < 2; x++)
            oneB = oneB + combineBirdie[x];
        birdieEagleHoleOne[i] = oneB;
        if (i == 0)
          playerOneBirdie++;
        if (i == 1)
          playerTwoBirdie++;
        if (i == 2)
          playerThreeBirdie++;
        if (i == 3)
          playerFourBirdie++;
        oneB.clear();
      }

      else if (((static_cast<int>(holeOne[i])) - 48) == (holeParValues[0] - 2))
      {
        char combineEagle[3];
        combineEagle[1] = holeOne[i];
        combineEagle[0] = eagle;
          for (x = 0; x < 2; x++)
            oneE = oneE + combineEagle[x];
        birdieEagleHoleOne[i] = oneE;
        if (i == 0)
          playerOneEagle++;
        if (i == 1)
          playerTwoEagle++;
        if (i == 2)
          playerThreeEagle++;
        if (i == 3)
          playerFourEagle++;
        oneE.clear();
      }

      else if (((static_cast<int>(holeOne[i])) - 48) >= holeParValues[0])
        birdieEagleHoleOne[i] = holeOne[i];
    }



  

  //Hole 2 birdies and eagles
    for (i = 0; i < 4; i++)
    {
      if (((static_cast<int>(holeTwo[i])) - 48) == (holeParValues[1] - 1))
      {
        char combineBirdie[3];
        combineBirdie[1] = holeTwo[i];
        combineBirdie[0] = birdie;
          for (x = 0; x < 2; x++)
              twoB = twoB + combineBirdie[x];
        birdieEagleHoleTwo[i] = twoB;
        if (i == 0)
          playerOneBirdie++;
        if (i == 1)
          playerTwoBirdie++;
        if (i == 2)
          playerThreeBirdie++;
        if (i == 3)
          playerFourBirdie++;
        twoB.clear();
      }
  
      if (((static_cast<int>(holeTwo[i])) - 48 ) == (holeParValues[1] - 2))
      {
        char combineEagle[3];
        combineEagle[1] = holeTwo[i];
        combineEagle[0] = eagle;
          for (x = 0; x < 2; x++)
              twoE = twoE + combineEagle[x];
        birdieEagleHoleTwo[i] = twoE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
        twoE.clear();
      }
     
      if (((static_cast<int>(holeTwo[i])) - 48) >= (holeParValues[1]))
        birdieEagleHoleTwo[i] = holeTwo[i];
    }





  //Hole 3 birdies and eagles
     for (i = 0; i < 4; i++)
     {
       if (((static_cast<int>(holeThree[i])) - 48) == (holeParValues[2] - 1))
       {
         char combineBirdie[3]; 
         combineBirdie[1] = holeThree[i];
         combineBirdie[0] = birdie; 
           for (x = 0; x < 2; x++)
               threeB = threeB + combineBirdie[x];
         birdieEagleHoleThree[i] = threeB;
         if (i == 0)
           playerOneBirdie++;
         if (i == 1)
           playerTwoBirdie++;
         if (i == 2)
           playerThreeBirdie++;
         if (i == 3)
           playerFourBirdie++;
         threeB.clear();
       }
   
       if (((static_cast<int>(holeThree[i])) - 48) == (holeParValues[2] - 2))
       {
         char combineEagle[3];
         combineEagle[1] = holeThree[i];
         combineEagle[0] = eagle;
           for (x = 0; x < 2; x++)
               threeE = threeE + combineEagle[x];
         birdieEagleHoleThree[i] = threeE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
         threeE.clear();
       }

       if (((static_cast<int>(holeThree[i])) - 48) >= holeParValues[2])
         birdieEagleHoleThree[i] = holeThree[i];
    }





  //Hole 4 birdies and eagles
    for (i = 0; i < 4; i++)
    {
      if (((static_cast<int>(holeFour[i])) - 48) == (holeParValues[3] - 1))
      {
        char combineBirdie[3];
        combineBirdie[1] = holeFour[i];
        combineBirdie[0] = birdie;
          for (x = 0; x < 2; x++)
              fourB = fourB + combineBirdie[x];
        birdieEagleHoleFour[i] = fourB;
        if (i == 0)
          playerOneBirdie++;
        if (i == 1)
          playerTwoBirdie++;
        if (i == 2)
          playerThreeBirdie++;
        if (i == 3)
          playerFourBirdie++;
        fourB.clear();
      }
    
      if (((static_cast<int>(holeFour[i])) - 48) == (holeParValues[3] - 2))
      {
        char combineEagle[3];
        combineEagle[1] = holeFour[i];
        combineEagle[0] = eagle;
          for (x = 0; x < 2; x++)
              fourE = fourE + combineEagle[x];
        birdieEagleHoleFour[i] = fourE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
        fourE.clear();
      }

      if (((static_cast<int>(holeFour[i])) - 48) >= (holeParValues[3]))
        birdieEagleHoleFour[i] = holeFour[i];
    }





    //Hole 5 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeFive[i])) - 48) == (holeParValues[4] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeFive[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                fiveB = fiveB + combineBirdie[x];
          birdieEagleHoleFive[i] = fiveB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          fiveB.clear();
        }

        if (((static_cast<int>(holeFive[i])) - 48) == (holeParValues[4] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeFive[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                fiveE = fiveE + combineEagle[x];
          birdieEagleHoleFive[i] = fiveE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          fiveE.clear();
         }
 
         if (((static_cast<int>(holeFive[i])) - 48) >= (holeParValues[4]))
           birdieEagleHoleFive[i] = holeFive[i];
       }





    //Hole 6 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeSix[i])) - 48) == (holeParValues[5] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeSix[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                sixB = sixB + combineBirdie[x];
          birdieEagleHoleSix[i] = sixB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          sixB.clear();
        }

        if (((static_cast<int>(holeSix[i])) - 48) == (holeParValues[5] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeSix[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                sixE = sixE + combineEagle[x];
          birdieEagleHoleSix[i] = sixE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          sixE.clear();
         }

         if (((static_cast<int>(holeSix[i])) - 48) >= (holeParValues[5]))
           birdieEagleHoleSix[i] = holeSix[i];
      }





    //Hole 7 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeSeven[i])) - 48) == (holeParValues[6] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeSeven[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                sevenB = sevenB + combineBirdie[x];
          birdieEagleHoleSeven[i] = sevenB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          sevenB.clear();
        }

        if (((static_cast<int>(holeSeven[i])) - 48) == (holeParValues[6] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeSeven[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                sevenE = sevenE + combineEagle[x];
          birdieEagleHoleSeven[i] = sevenE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          sevenE.clear();
         }

         if (((static_cast<int>(holeSeven[i])) - 48) >= (holeParValues[6]))
           birdieEagleHoleSeven[i] = holeSeven[i];
      }





    //Hole 8 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeEight[i])) - 48) == (holeParValues[7] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeEight[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                eightB = eightB + combineBirdie[x];
          birdieEagleHoleEight[i] = eightB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          eightB.clear();
        }

        if (((static_cast<int>(holeEight[i])) - 48) == (holeParValues[7] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeEight[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                eightE = eightE + combineEagle[x];
          birdieEagleHoleEight[i] = eightE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          eightE.clear();
         }

         if (((static_cast<int>(holeEight[i])) - 48) >= (holeParValues[7]))
           birdieEagleHoleEight[i] = holeEight[i];
      }





    //Hole 9 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeNine[i])) - 48) == (holeParValues[8] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeNine[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                nineB = nineB + combineBirdie[x];
          birdieEagleHoleNine[i] = nineB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          nineB.clear();
        }

        if (((static_cast<int>(holeNine[i])) - 48) == (holeParValues[8] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeNine[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                nineE = nineE + combineEagle[x];
          birdieEagleHoleNine[i] = nineE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          nineE.clear();
         }

         if (((static_cast<int>(holeNine[i])) - 48) >= (holeParValues[8]))
           birdieEagleHoleNine[i] = holeNine[i];
      }





    //Hole 10 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeTen[i])) - 48) == (holeParValues[9] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeTen[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                tenB = tenB + combineBirdie[x];
          birdieEagleHoleTen[i] = tenB;
          if (i == 0)
           playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          tenB.clear();
        }

        if (((static_cast<int>(holeTen[i])) - 48) == (holeParValues[9] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeTen[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                tenE = tenE + combineEagle[x];
          birdieEagleHoleTen[i] = tenE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          tenE.clear();
         }

         if (((static_cast<int>(holeTen[i])) - 48) >= (holeParValues[9]))
           birdieEagleHoleTen[i] = holeTen[i];
      }





    //Hole 11 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeEleven[i])) - 48) == (holeParValues[10] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeEleven[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                elevenB = elevenB + combineBirdie[x];
          birdieEagleHoleEleven[i] = elevenB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          elevenB.clear();
        }

        if (((static_cast<int>(holeEleven[i])) - 48) == (holeParValues[10] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeEleven[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                elevenE = elevenE + combineEagle[x];
          birdieEagleHoleEleven[i] = elevenE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          elevenE.clear();
         }

         if (((static_cast<int>(holeEleven[i])) - 48) >= (holeParValues[10]))
           birdieEagleHoleEleven[i] = holeEleven[i];
      }





    //Hole 12 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeTwelve[i])) - 48) == (holeParValues[11] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeTwelve[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                twelveB = twelveB + combineBirdie[x];
          birdieEagleHoleTwelve[i] = twelveB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          twelveB.clear();
        }

        if (((static_cast<int>(holeTwelve[i])) - 48) == (holeParValues[11] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeTwelve[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                twelveE = twelveE + combineEagle[x];
          birdieEagleHoleTwelve[i] = twelveE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          twelveE.clear();
         }

         if (((static_cast<int>(holeTwelve[i])) - 48) >= (holeParValues[11]))
           birdieEagleHoleTwelve[i] = holeTwelve[i];
      }





    //Hole 13 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeThirteen[i])) - 48) == (holeParValues[12] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeThirteen[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                thirteenB = thirteenB + combineBirdie[x];
          birdieEagleHoleThirteen[i] = thirteenB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;      
          thirteenB.clear();
        }

        if (((static_cast<int>(holeThirteen[i])) - 48) == (holeParValues[12] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeThirteen[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                thirteenE = thirteenE + combineEagle[x];
          birdieEagleHoleThirteen[i] = thirteenE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          thirteenE.clear();
         }

         if (((static_cast<int>(holeThirteen[i])) - 48) >= (holeParValues[12]))
           birdieEagleHoleThirteen[i] = holeThirteen[i];
      }





    //Hole 14 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeFourteen[i])) - 48) == (holeParValues[13] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeFourteen[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                fourteenB = fourteenB + combineBirdie[x];
          birdieEagleHoleFourteen[i] = fourteenB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          fourteenB.clear();
        }

        if (((static_cast<int>(holeFourteen[i])) - 48) == (holeParValues[13] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeFourteen[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                fourteenE = fourteenE + combineEagle[x];
          birdieEagleHoleFourteen[i] = fourteenE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          fourteenE.clear();
         }

         if (((static_cast<int>(holeFourteen[i])) - 48) >= (holeParValues[13]))
           birdieEagleHoleFourteen[i] = holeFourteen[i];
      }





    //Hole 15 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeFifteen[i])) - 48) == (holeParValues[14] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeFifteen[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                fifteenB = fifteenB + combineBirdie[x];
          birdieEagleHoleFifteen[i] = fifteenB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          fifteenB.clear();
        }

        if (((static_cast<int>(holeFifteen[i])) - 48) == (holeParValues[14] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeFifteen[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                fifteenE = fifteenE + combineEagle[x];
          birdieEagleHoleFifteen[i] = fifteenE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          fifteenE.clear();
         }

         if (((static_cast<int>(holeFifteen[i])) - 48) >= (holeParValues[14]))
           birdieEagleHoleFifteen[i] = holeFifteen[i];
      }





    //Hole 16 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeSixteen[i])) - 48) == (holeParValues[15] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeSixteen[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                sixteenB = sixteenB + combineBirdie[x];
          birdieEagleHoleSixteen[i] = sixteenB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          sixteenB.clear();
        }

        if (((static_cast<int>(holeSixteen[i])) - 48) == (holeParValues[15] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeSixteen[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                sixteenE = sixteenE + combineEagle[x];
          birdieEagleHoleSixteen[i] = sixteenE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          sixteenE.clear();
         }

         if (((static_cast<int>(holeSixteen[i])) - 48) >= (holeParValues[15]))
           birdieEagleHoleSixteen[i] = holeSixteen[i];
      }





    //Hole 17 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeSeventeen[i])) - 48) == (holeParValues[16] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeSeventeen[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                seventeenB = seventeenB + combineBirdie[x];
          birdieEagleHoleSeventeen[i] = seventeenB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          seventeenB.clear();
        }

        if (((static_cast<int>(holeSeventeen[i])) - 48) == (holeParValues[16] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeSeventeen[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                seventeenE = seventeenE + combineEagle[x];
          birdieEagleHoleSeventeen[i] = seventeenE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          seventeenE.clear();
         }

         if (((static_cast<int>(holeSeventeen[i])) - 48) >= (holeParValues[16]))
           birdieEagleHoleSeventeen[i] = holeSeventeen[i];
      }





    //Hole 18 birdies and eagles
      for (i = 0; i < 4; i++)
      {
        if (((static_cast<int>(holeEighteen[i])) - 48) == (holeParValues[17] - 1))
        {
          char combineBirdie[3];
          combineBirdie[1] = holeEighteen[i];
          combineBirdie[0] = birdie;
            for (x = 0; x < 2; x++)
                eighteenB = eighteenB + combineBirdie[x];
          birdieEagleHoleEighteen[i] = eighteenB;
          if (i == 0)
            playerOneBirdie++;
          if (i == 1)
            playerTwoBirdie++;
          if (i == 2)
            playerThreeBirdie++;
          if (i == 3)
            playerFourBirdie++;
          eighteenB.clear();
        }

        if (((static_cast<int>(holeEighteen[i])) - 48) == (holeParValues[17] - 2))
        {
          char combineEagle[3];
          combineEagle[1] = holeEighteen[i];
          combineEagle[0] = eagle;
            for (x = 0; x < 2; x++)
                eighteenE = eighteenE + combineEagle[x];
          birdieEagleHoleEighteen[i] = eighteenE;
          if (i == 0)
            playerOneEagle++;
          if (i == 1)
            playerTwoEagle++;
          if (i == 2)
            playerThreeEagle++;
          if (i == 3)
            playerFourEagle++;
          eighteenE.clear();
         }

         if (((static_cast<int>(holeEighteen[i])) - 48) >= (holeParValues[17]))
           birdieEagleHoleEighteen[i] = holeEighteen[i];
      }










  //Formatting the output of the program


  cout << endl;


  //Calling this function will help in printing the players name, their total scores, and their two 9-subtotal scores
  nineHoles(players, holeOne, holeTwo, holeThree, holeFour, holeFive, holeSix, holeSeven, holeEight, 
      holeNine, holeTen, holeEleven, holeTwelve, holeThirteen, holeFourteen, holeFifteen, holeSixteen, 
      holeSeventeen, holeEighteen, playerOneTotalStrokes, playerTwoTotalStrokes, playerThreeTotalStrokes, playerFourTotalStrokes);


  cout << endl;


  //Calling this function will help report who the winner is and how much off they were of par (whether that be below, above, or equal to)
  //It also helps determine if there is a tie who won based off of how many birdies the tied players had and how many eagles the tied players had
  winner(players, playerOneTotalStrokes, playerTwoTotalStrokes, playerThreeTotalStrokes, playerFourTotalStrokes, perfectPar, 
    playerOneBirdie, playerTwoBirdie, playerThreeBirdie, playerFourBirdie, playerOneEagle, playerTwoEagle, playerThreeEagle,
    playerFourEagle);


  cout << endl;
  cout << endl;


  //This outputs the titles of the columns of the golf score card, which are each round and finally ending with the word score (for each players total score
  cout << setw(12) << "1" << setw(5) << "2" << setw(5) << "3" << setw(5) << "4" << setw(5) << "5" << setw(5) << "6" << setw(5) << "7" << setw(5) << "8"
  << setw(5) << "9" << setw(5) << "10" << setw(5) << "11" << setw(5) << "12" << setw(5) << "13" << setw(5) << "14" << setw(5) << "15" << setw(6) << "16" 
  << setw(5) << "17" << setw(5) << "18" << setw(10) << "Score" << endl;


  int finalStroke;


  //Helps run through each of the 18 hole arrays (the new ones which include the birdies and the eagle updates) four times for each player so to properly output 
  //into a clean table format
  for (i = 0; i < 4; i++)
  {
    if (i == 0)
      finalStroke = playerOneTotalStrokes;
    if (i == 1)
      finalStroke = playerTwoTotalStrokes;
    if (i == 2)
      finalStroke = playerThreeTotalStrokes;
    if (i == 3)
      finalStroke = playerFourTotalStrokes; 

   



    cout << setw(7) << players[i] << setw(5) << birdieEagleHoleOne[i] << setw(5) << birdieEagleHoleTwo[i] << setw(5) << birdieEagleHoleThree[i]
    << setw(5) << birdieEagleHoleFour[i] << setw(5) << birdieEagleHoleFive[i] << setw(5) << birdieEagleHoleSix[i] << setw(5) 
    << birdieEagleHoleSeven[i] << setw(5) << birdieEagleHoleEight[i] << setw(5) << birdieEagleHoleNine[i] << setw(5) << birdieEagleHoleTen[i] 
    << setw(5) << birdieEagleHoleEleven[i] << setw(5) << birdieEagleHoleTwelve[i] << setw(5) << birdieEagleHoleThirteen[i] << setw(5) 
    << birdieEagleHoleFourteen[i] << setw(5) << birdieEagleHoleFifteen[i] << setw(5) << birdieEagleHoleSixteen[i] << setw(5) 
    << birdieEagleHoleSeventeen[i] << setw(5) << birdieEagleHoleEighteen[i] << setw(9) << finalStroke << endl;
  }








return 0;
}










//Function: finding the total par after 18 rounds
int totalPar(int par[])
{
  int sum = 0, i;
  
  for (i = 0; i < 18; i++)
    sum += par[i];

  return sum;
}








//Function: find player one's total number of strokes
int playerOneStrokes(char one[], char two[], char three[], char four[], char five[], char six[],
    char seven[], char eight[], char nine[], char ten[], char eleven[], char twelve[], char thirteen[],
    char fourteen[], char fifteen[], char sixteen[], char seventeen[], char eighteen[])
{
  int sum;

  //I subtracted 48 as that is when the first number appears, so by subtracting 48, I can appropriately convert the char values from the arrays to ints so that the sum of 
  //the player's strokes can be added properly
  int a = one[0] - 48;
  int b = two[0] - 48;
  int c = three[0] - 48;
  int d = four[0] - 48;
  int e = five[0] - 48;
  int f = six[0] - 48;
  int g = seven[0] - 48;
  int h = eight[0] - 48;
  int i = nine[0] - 48;
  int j = ten[0] - 48;
  int k = eleven[0] - 48;
  int l = twelve[0] - 48;
  int m = thirteen[0] - 48;
  int n = fourteen[0] - 48;
  int o = fifteen[0] - 48;
  int p = sixteen[0] - 48;
  int q = seventeen[0] - 48;
  int r = eighteen[0] - 48;

  
  sum = a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p + q + r;

  return sum;
}








//Function: find player two's total number of strokes
int playerTwoStrokes(char one[], char two[], char three[], char four[], char five[], char six[],
    char seven[], char eight[], char nine[], char ten[], char eleven[], char twelve[], char thirteen[],
    char fourteen[], char fifteen[], char sixteen[], char seventeen[], char eighteen[])
{
  int sum;

  //I subtracted 48 as that is when the first number appears, so by subtracting 48, I can appropriately convert the char values from the arrays to ints so that the sum of
  //the f (personOneBirdie > personFourBirdie)
  int a = one[1] - 48;
  int b = two[1] - 48;
  int c = three[1] - 48;
  int d = four[1] - 48;
  int e = five[1] - 48;
  int f = six[1] - 48;
  int g = seven[1] - 48;
  int h = eight[1] - 48;
  int i = nine[1] - 48;
  int j = ten[1] - 48;
  int k = eleven[1] - 48;
  int l = twelve[1] - 48;
  int m = thirteen[1] - 48;
  int n = fourteen[1] - 48;
  int o = fifteen[1] - 48;
  int p = sixteen[1] - 48;
  int q = seventeen[1] - 48;
  int r = eighteen[1] - 48;


  sum = a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p + q + r;

  return sum;

}








//Function: find player three's total number of strokes
int playerThreeStrokes(char one[], char two[], char three[], char four[], char five[], char six[],
    char seven[], char eight[], char nine[], char ten[], char eleven[], char twelve[], char thirteen[],
    char fourteen[], char fifteen[], char sixteen[], char seventeen[], char eighteen[])
{
  int sum;

  //I subtracted 48 as that is when the first number appears, so by subtracting 48, I can appropriately convert the char values from the arrays to ints so that the sum of
  //the player's strokes can be added properly
  int a = one[2] - 48;
  int b = two[2] - 48;
  int c = three[2] - 48;
  int d = four[2] - 48;
  int e = five[2] - 48;
  int f = six[2] - 48;
  int g = seven[2] - 48;
  int h = eight[2] - 48;
  int i = nine[2] - 48;
  int j = ten[2] - 48;
  int k = eleven[2] - 48;
  int l = twelve[2] - 48;
  int m = thirteen[2] - 48;
  int n = fourteen[2] - 48;
  int o = fifteen[2] - 48;
  int p = sixteen[2] - 48;
  int q = seventeen[2] - 48;
  int r = eighteen[2] - 48;


  sum = a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p + q + r;

  return sum;

}








//Function: find player three's total number of strokes
int playerFourStrokes(char one[], char two[], char three[], char four[], char five[], char six[],
    char seven[], char eight[], char nine[], char ten[], char eleven[], char twelve[], char thirteen[],
    char fourteen[], char fifteen[], char sixteen[], char seventeen[], char eighteen[])
{
  int sum;

  //I subtracted 48 as that is when the first number appears, so by subtracting 48, I can appropriately convert the char values from the arrays to ints so that the sum of
  //the player's strokes can be added properly
  int a = one[3] - 48;
  int b = two[3] - 48;
  int c = three[3] - 48;
  int d = four[3] - 48;
  int e = five[3] - 48;
  int f = six[3] - 48;
  int g = seven[3] - 48;
  int h = eight[3] - 48;
  int i = nine[3] - 48;
  int j = ten[3] - 48;
  int k = eleven[3] - 48;
  int l = twelve[3] - 48;
  int m = thirteen[3] - 48;
  int n = fourteen[3] - 48;
  int o = fifteen[3] - 48;
  int p = sixteen[3] - 48;
  int q = seventeen[3] - 48;
  int r = eighteen[3] - 48;


  sum = a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p + q + r;

  return sum;

}








//Function: determine the winner (lowest stroke)
void winner(string people[], int one, int two, int three, int four, int perfectParFun,
            int personOneBirdie, int personTwoBirdie, int personThreeBirdie, 
            int personFourBirdie, int personOneEagle, int personTwoEagle,
            int personThreeEagle, int personFourEagle)
{
  int min;

  int winnerParDifference;

  /*
     These if else statements go through each of the four players and determines whose scores are the lowest and what should be outputted
     if their score is higher, lower, or equal to par. Also, each tie breaker is taken into account so that way the computer doesn't 
     declare a winner yet at the same time say that someone else (the other peron) won the tie breaker
  */

  //Output if player one won
  if ((one < two) && (one < three) && (one < four))
  {
    min = one;
  
    winnerParDifference = perfectParFun - min;

    if (winnerParDifference > 0)
    {
      winnerParDifference *= - 1;
      cout << people[0] << " was the winner with a score of " << winnerParDifference << endl;
    }

    else if (winnerParDifference < 0)
    {
      winnerParDifference *= -1;
      cout << people[0] << " was the winner with a score of +" << winnerParDifference << endl;
    }

    else
      cout << people[0] << " was the winner with a score of 0." << endl;
  
  }  



  //output if player two won
  else if ((two < three) && (two < four) && (two < one))
  {
    min = two;

    winnerParDifference = perfectParFun - min;

    if (winnerParDifference > 0)
    {
      winnerParDifference *= -1;
      cout << people[1] << " was the winner with a score of " << winnerParDifference << endl;
    }

    else if (winnerParDifference < 0)
    {
      winnerParDifference *= -1;
      cout << people[1] << " was the winner with a score of +" << winnerParDifference << endl;
    }

    else
      cout << people[1] << " was the winner with a score of 0." << endl;

  }



  //output if player three won
  else if ((three < four) && (three < one) && (three < two))
  {
    min = three;

    winnerParDifference = perfectParFun - min;

    if (winnerParDifference > 0)
    {
      winnerParDifference *= -1;
      cout << people[2] << " was the winner with a score of " << winnerParDifference << endl;
    }
    else if (winnerParDifference < 0)
    {
      winnerParDifference *= -1;
      cout << people[2] << " was the winner with a score of +" << winnerParDifference << endl;
    }
    else
      cout << people[2] << " was the winner with a score of 0." << endl;
  }



  //output if player four won
  else if ((four < three) && (four < one) && (four < two))
  {
    min = four;

    winnerParDifference = perfectParFun - min;

    if (winnerParDifference > 0)
    {
      winnerParDifference *= -1;
      cout << people[3] << " was the winner with a score of " << winnerParDifference << endl;
    }
    else if (winnerParDifference < 0)
    {
      winnerParDifference *= -1;
      cout << people[3] << " was the winner with a score of +" << winnerParDifference << endl;
    }
    else
      cout << people[3] << " was the winner with a score of 0." << endl;
  }





/*
   The following statements just state whether or not there is a tie breaker between two players.
   NOT who won the tie breaker. That is determined by the number of birdies and eagles in the next
   set of if statements.
*/



  //output if player one and two tied
  else if ((one == two) && (one < three) && (one < four) && (two < three) && (two < four))
    cout << "Tie breaker between " << people[0] << " and " << people[1] << endl;



  //output if player one and three tied
  else if ((one == three) && (one < two) && (one < four) && (three < two) && (three < four))
    cout << "Tie breaker between " << people[0] << " and " << people[2] << endl;
  


  //output if player one and four tied
  else if ((one == four) && (one < two) && (one < three) && (four < two) && (four < three))
    cout << "Tie breaker between " << people[0] << " and " << people[3] << endl;



  //output if player two and three tied
  else if ((two == three) && (two < one) && (two < four) && (three < one) && (three < four))
    cout << "Tie breaker between " << people[1] << " and " << people[2] << endl;


  
  //output if player two and four tied
  else if ((two == four) && (two < one) && (two < three) && (four < one) && (four < three))
    cout << "Tie breaker between " << people[1] << " and " << people[3] << endl;



  //output if player three and four tied
  else if ((three == four) && (three < one) && (three < two) && (four < one) && (four < two))
    cout << "Tie breaker between " << people[2] << " and " << people[3] << endl;



  //output if player 1, 2, and 3 are tied
  else if ((one == two) && (one == three) && (one < four))
     cout << "Tie breaker between " << people[0] << ", " << people[1] << ", and " << people[2] << endl;



  //output if player 1, 2, and 4 are tied
  else if ((one == two) && (one == four) && (one < three))
     cout << "Tie breaker between " << people[0] << ", " << people[1] << ", and " << people[3] << endl;



  //output if player 1, 3, and 4 are tied
  else if ((one == three) && (one == four) && (one < two))
     cout << "Tie breaker between " << people[0] << ", " << people[2] << ", and " << people[3] << endl;



  //output if all players tie
  else if ((one == two) && (one == three) && (one == four))
    cout << "Everyone tied!" << endl;



  //output if players 2, 3, and 4 
  else if ((two == three) && (two == four) && (two < one))
    cout << "Tie breaker between " << people[1] << ", " << people[2] << ", and " << people[3] << endl;








/*
   The next set of code in this winnner function will determine who won the tie breaker between certain
   combinations of players based off the number of birdies and/or eagles each player had. Whoever had 
   more birdies wins, but if birdies are equal, whoever has more eagles wins, and if eagles are equal,
   the computer declares those two people a tie but if they want to only have one champion, they can 
   individually play one round of golf between the two and whoever with the lowest strokes wins.
*/


  //variables declared in order to calculate the difference in the amount of birdies/eagles between the two tied players
  int birdieDifference, eagleDifference;


  //The followinng else if statements are to determine a winner if there is a tie breaker


  //This first set of code describes the result of a tie breaker between players one and two
  if ((one == two) && (one != three) && (one != four))
  {

      if (personOneBirdie > personTwoBirdie)
      {
        birdieDifference = personOneBirdie - personTwoBirdie;
        cout << people[0] << " won the tie breaker with " << people[1] << " by having " << birdieDifference
             << " more birdies than " << people[1] << endl;
      }
 
     
      else if (personOneBirdie < personTwoBirdie)
      {
        birdieDifference = personTwoBirdie - personOneBirdie;
        cout << people[1] << " won the tie breaker with " << people[0] << " by having " << birdieDifference
             << " more birdies than " << people[0] << endl;
      }


      //If all players tied for birdies, then eagles are evaluated
      else if (personOneBirdie == personTwoBirdie)
      {

          if (personOneEagle > personTwoEagle)
          {
            eagleDifference = personOneEagle - personTwoEagle;
            cout << people[0] << " won the tie breaker and tie birdie breaker with " << people[1] << " by having " << eagleDifference
                 << " more eagles than " << people[1] << endl;
          }
    
   
          else if (personOneEagle < personTwoEagle)
          {
            eagleDifference = personTwoEagle - personOneEagle;
            cout << people[1] << " won the tie breaker and tie birdie breaker with " << people[0] << " by having " << eagleDifference 
                 << " more eagles than " << people[0] << endl;
          }
   
   
          else
          {
            cout << "System overload. Unable to determine true winner. Unfortunately this system has declared " << people[0] << " and "
                 << people[1] << " both winners. Feel free to do an extra round by yourself to determine true winner if you wish for there to be only one true winner" << endl;
          }
     }
  }








  //This second set of code would describe the result of a tie breaker between players 1 and 3
  if ((one == three) && (one != two) && (one != four))
  {

      if (personOneBirdie > personThreeBirdie)
      {
        birdieDifference = personOneBirdie - personThreeBirdie;
        cout << people[0] << " won the tie breaker with " << people[2] << " by having " << birdieDifference
             << " more birdies than " << people[2] << endl;
      }


      else if (personOneBirdie < personThreeBirdie)
      {
        birdieDifference = personThreeBirdie - personOneBirdie;
        cout << people[2] << " won the tie breaker with " << people[0] << " by having " << birdieDifference
             << " more birdies than " << people[0] << endl;
      }


      //If all players tied for birdies, then eagles are evaluated
      else if (personOneBirdie == personThreeBirdie)
      {

          if (personOneEagle > personThreeEagle)
          {
            eagleDifference = personOneEagle - personThreeEagle;
            cout << people[0] << " won the tie breaker and tie birdie breaker with " << people[2] << " by having " << eagleDifference
                 << " more eagles than " << people[2] << endl;
          }


          else if (personOneEagle < personThreeEagle)
          {
            eagleDifference = personThreeEagle - personOneEagle;
            cout << people[2] << " won the tie breaker and tie birdie breaker with " << people[0] << " by having " << eagleDifference
                 << " more eagles than " << people[0] << endl;
          }


          else
          {
            cout << "System overload. Unable to determine true winner. Unfortunately this system has declared " << people[0] << " and "
                 << people[2] << " both winners. Feel free to do an extra round by yourself to determine true winner if you wish for there to be only one true winner" << endl;
          }
     }
  }








  //This code tells who would win a tie breaker between player one and player four
  if ((one == four) && (one != two) && (one != three))
  {

      if (personOneBirdie > personFourBirdie)
      {
        birdieDifference = personOneBirdie - personFourBirdie;
        cout << people[0] << " won the tie breaker with " << people[3] << " by having " << birdieDifference
             << " more birdies than " << people[3] << endl;
      }


      else if (personOneBirdie < personFourBirdie)
      {
        birdieDifference = personFourBirdie - personOneBirdie;
        cout << people[3] << " won the tie breaker with " << people[0] << " by having " << birdieDifference
             << " more birdies than " << people[0] << endl;
      }


      //If all players tied for birdies, then eagles are evaluated
      else if (personOneBirdie == personFourBirdie)
      {

          if (personOneEagle > personFourEagle)
          {
            eagleDifference = personOneEagle - personFourEagle;
            cout << people[0] << " won the tie breaker and tie birdie breaker with " << people[3] << " by having " << eagleDifference
                 << " more eagles than " << people[3] << endl;
          }


          else if (personOneEagle < personFourEagle)
          {
            eagleDifference = personFourEagle - personOneEagle;
            cout << people[3] << " won the tie breaker and tie birdie breaker with " << people[0] << " by having " << eagleDifference
                 << " more eagles than " << people[0] << endl;
          }


          else
          {
            cout << "System overload. Unable to determine true winner. Unfortunately this system has declared " << people[0] << " and "
                 << people[3] << " both winners. Feel free to do an extra round by yourself to determine true winner if you wish for there to be only one true winner" << endl;
          }
       }
  }








  //This part of the code determines who wins a tie breaker between player 2 and 3
  if ((two == three) && (two != one) && (two != four))
  {

      if (personTwoBirdie > personThreeBirdie)
      {
        birdieDifference = personTwoBirdie - personThreeBirdie;
        cout << people[1] << " won the tie breaker with " << people[2] << " by having " << birdieDifference
             << " more birdies than " << people[2] << endl;
      }


      else if (personTwoBirdie < personThreeBirdie)
      {
        birdieDifference = personThreeBirdie - personTwoBirdie;
        cout << people[2] << " won the tie breaker with " << people[1] << " by having " << birdieDifference
             << " more birdies than " << people[1] << endl;
      }


      //If all players tied for birdies, then eagles are evaluated
      else if (personTwoBirdie == personThreeBirdie)
      {

          if (personTwoEagle > personThreeEagle)
          {
            eagleDifference = personTwoEagle - personThreeEagle;
            cout << people[1] << " won the tie breaker and tie birdie breaker with " << people[2] << " by having " << eagleDifference
                 << " more eagles than " << people[2] << endl;
          }


          else if (personTwoEagle < personThreeEagle)
          {
            eagleDifference = personThreeEagle - personTwoEagle;
            cout << people[2] << " won the tie breaker and tie birdie breaker with " << people[1] << " by having " << eagleDifference
                 << " more eagles than " << people[1] << endl;
          }


          else
          {
            cout << "System overload. Unable to determine true winner. Unfortunately this system has declared " << people[1] << " and "
                 << people[2] << " both winners. Feel free to do an extra round by yourself to determine true winner if you wish for there to be only one true winner" << endl;
          }
       }
  }








  //This code determines the winner of a tie breaker between players 2 and 4
  if ((two == four) && (two != one) && (two != three))
  { 
      if (personTwoBirdie > personFourBirdie)
      {
        birdieDifference = personTwoBirdie - personFourBirdie;
        cout << people[1] << " won the tie breaker with " << people[3] << " by having " << birdieDifference
             << " more birdies than " << people[3] << endl;
      }


      else if (personTwoBirdie < personFourBirdie)
      {
        birdieDifference = personFourBirdie - personTwoBirdie;
        cout << people[3] << " won the tie breaker with " << people[1] << " by having " << birdieDifference
             << " more birdies than " << people[1] << endl;
      }


      //If all players tied for birdies, then eagles are evaluated
      else if (personTwoBirdie == personFourBirdie)
      {

          if (personTwoEagle > personFourEagle)
          {
            eagleDifference = personTwoEagle - personFourEagle;
            cout << people[1] << " won the tie breaker and tie birdie breaker with " << people[3] << " by having " << eagleDifference
                 << " more eagles than " << people[3] << endl;
          }


          else if (personTwoEagle < personFourEagle)
          {
            eagleDifference = personFourEagle - personTwoEagle;
            cout << people[3] << " won the tie breaker and tie birdie breaker with " << people[1] << " by having " << eagleDifference
                 << " more eagles than " << people[1] << endl;
          }


          else
          {
            cout << "System overload. Unable to determine true winner. Unfortunately this system has declared " << people[1] << " and "
                 << people[3] << " both winners. Feel free to do an extra round by yourself to determine true winner if you wish for there to be only one true winner" << endl;
          }
       }
  }








  //This code will determine the winner of a tie breaker between players 3 and four
  if ((three == four) && (three != one) && (three != two))
  {

      if (personThreeBirdie > personFourBirdie)
      {
        birdieDifference = personThreeBirdie - personFourBirdie;
        cout << people[2] << " won the tie breaker with " << people[3] << " by having " << birdieDifference
             << " more birdies than " << people[3] << endl;
      }


      else if (personThreeBirdie < personFourBirdie)
      {
        birdieDifference = personFourBirdie - personThreeBirdie;
        cout << people[3] << " won the tie breaker with " << people[2] << " by having " << birdieDifference
             << " more birdies than " << people[2] << endl;
      }


      //If all players tied for birdies, then eagles are evaluated
      else if (personThreeBirdie == personFourBirdie)
      {

          if (personThreeEagle > personFourEagle)
          {
            eagleDifference = personThreeEagle - personFourEagle;
            cout << people[2] << " won the tie breaker and tie birdie breaker with " << people[3] << " by having " << eagleDifference
                 << " more eagles than " << people[3] << endl;
          }


          else if (personThreeEagle < personFourEagle)
          {
            eagleDifference = personFourEagle - personThreeEagle;
            cout << people[3] << " won the tie breaker and tie birdie breaker with " << people[2] << " by having " << eagleDifference
                 << " more eagles than " << people[2] << endl;
          }


          else
          {
            cout << "System overload. Unable to determine true winner. Unfortunately this system has declared " << people[2] << " and "
                 << people[3] << " both winners. Feel free to do an extra round by yourself to determine true winner if you wish for there to be only one true winner" << endl;              }
       }
  }



  int birdieDifferenceTwo, birdieDifferenceThree;
  int eagleDifferenceTwo, eagleDifferenceThree;



  /*
      The following set of code in this function will evaluate all other types of ties that include 3 to four playres
  */



  //This will determine the winner if there is a tie between 1, 2, and 3
  if ((one == two) && (one == three))
  {

      if ((personOneBirdie > personTwoBirdie) && (personOneBirdie > personThreeBirdie))
      {
        birdieDifference = personOneBirdie - personTwoBirdie;
        birdieDifferenceTwo = personOneBirdie - personThreeBirdie;
        cout << people[0] << " won the tie breaker with " << people[1] << " and " << people[2] << " by having " << birdieDifference
             << " more birdies than " << people[1] << " and " << birdieDifferenceTwo << " more birdies than " 
             << people[2] << endl;
      }


      else if ((personTwoBirdie > personOneBirdie) && (personTwoBirdie > personThreeBirdie))
      {
        birdieDifference = personTwoBirdie - personOneBirdie;
        birdieDifferenceTwo = personTwoBirdie - personThreeBirdie;
        cout << people[1] << " won the tie breaker with " << people[0] << " and " << people[2] << " by having " << birdieDifference
             << " more birdies than " << people[0] << " and " << birdieDifferenceTwo << " more birdies than " 
             << people[2] << endl;
      }


      else if ((personThreeBirdie > personOneBirdie) && (personThreeBirdie > personTwoBirdie))
      {
        birdieDifference = personThreeBirdie - personOneBirdie;
        birdieDifferenceTwo = personThreeBirdie - personTwoBirdie;
        cout << people[2] << " won the tie breaker with " << people[0] << " and " << people[1] << " by having " << birdieDifference
             << " more birdies than " << people[0] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[1] << endl;
      }


      //If all players tied tie in birdies, then eagles are evaluated
      else if ((personOneBirdie == personTwoBirdie) && (personOneBirdie == personThreeBirdie))
      {

          if ((personOneEagle > personTwoEagle) && (personOneEagle > personThreeEagle))
          {
            eagleDifference = personOneEagle - personTwoEagle;
            eagleDifferenceTwo = personOneEagle - personThreeEagle;
            cout << people[0] << " won the tie breaker and tie birdie breaker with " << people[1] << " and " << people[2] << " by having " << eagleDifference
                 << " more eagles than " << people[1] << " and " << eagleDifferenceTwo << " more eagles than " 
                 << people[2] << endl;
          }


          else if ((personTwoEagle > personOneEagle) && (personTwoEagle > personThreeEagle))
          {
            eagleDifference = personTwoEagle - personOneEagle;
            eagleDifferenceTwo = personTwoEagle - personThreeEagle;
            cout << people[1] << " won the tie breaker and tie birdie breaker with " << people[0] << " and " << people[2] << " by having " << eagleDifference
                 << " more eagles than " << people[0] << " and " << eagleDifferenceTwo << " more eagles than "
                 << people[2] << endl;
          }


          else if ((personThreeEagle > personOneEagle) && (personThreeEagle > personTwoEagle))
          {
            eagleDifference = personThreeEagle - personOneEagle;
            eagleDifferenceTwo = personThreeEagle - personTwoEagle;
            cout << people[2] << " won the tie breaker with " << people[0] << " and " << people[1] << " by having " << eagleDifference
                              << " more eagles than " << people[0] << " and " << eagleDifferenceTwo << " more eagles than " 
                              << people[1] << endl;
          }


          else if ((personOneEagle == personThreeEagle) && (personOneEagle == personTwoEagle))
          {
            cout << "System overload. Unable to determine true winner. Unfortunately this system has declared " << people[0] << " and "
                 << people[1] << " and " << people[2] 
                 << " all winners. Feel free to do an extra round by yourself to determine true winner if you wish for there to be only one true winner" << endl;
          }
     }
  }
  







  //This will determine the winner if there is a tie between 1, 2, and 4
  if ((one == two) && (one == four))
  {

      if ((personOneBirdie > personTwoBirdie) && (personOneBirdie > personFourBirdie))
      {
        birdieDifference = personOneBirdie - personTwoBirdie;
        birdieDifferenceTwo = personOneBirdie - personFourBirdie;
        cout << people[0] << " won the tie breaker with " << people[1] << " and " << people[3] << " by having " << birdieDifference
             << " more birdies than " << people[1] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[3] << endl;
      }


      else if ((personTwoBirdie > personOneBirdie) && (personTwoBirdie > personFourBirdie))
      {
        birdieDifference = personTwoBirdie - personOneBirdie;
        birdieDifferenceTwo = personTwoBirdie - personFourBirdie;
        cout << people[1] << " won the tie breaker with " << people[0] << " and " << people[3] << " by having " << birdieDifference
             << " more birdies than " << people[0] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[3] << endl;
      }


      else if ((personFourBirdie > personOneBirdie) && (personFourBirdie > personTwoBirdie))
      {
        birdieDifference = personFourBirdie - personOneBirdie;
        birdieDifferenceTwo = personFourBirdie - personTwoBirdie;
        cout << people[3] << " won the tie breaker with " << people[0] << " and " << people[1] << " by having " << birdieDifference
             << " more birdies than " << people[0] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[1] << endl;
      }


      //If all players tied tie in birdies, then eagles are evaluated
      else if ((personOneBirdie == personTwoBirdie) && (personOneBirdie == personFourBirdie))
      {

          if ((personOneEagle > personTwoEagle) && (personOneEagle > personFourEagle))
          {
            eagleDifference = personOneEagle - personTwoEagle;
            eagleDifferenceTwo = personOneEagle - personFourEagle;
            cout << people[0] << " won the tie breaker and tie birdie breaker with " << people[1] << " and " << people[3] << " by having " << eagleDifference
                 << " more eagles than " << people[1] << " and " << eagleDifferenceTwo << " more eagles than "
                 << people[3] << endl;
          }


          else if ((personTwoEagle > personOneEagle) && (personTwoEagle > personFourEagle))
          {
            eagleDifference = personTwoEagle - personOneEagle;
            eagleDifferenceTwo = personTwoEagle - personFourEagle;
            cout << people[1] << " won the tie breaker and tie birdie breaker with " << people[0] << " and " << people[3] << " by having " << eagleDifference
                 << " more eagles than " << people[0] << " and " << eagleDifferenceTwo << " more eagles than "
                 << people[3] << endl;
          }
 

          else if ((personFourEagle > personOneEagle) && (personFourEagle > personTwoEagle))
          {
            eagleDifference = personFourEagle - personOneEagle;
            eagleDifferenceTwo = personFourEagle - personTwoEagle;
            cout << people[3] << " won the tie breaker with " << people[0] << " and " << people[1] << " by having " << eagleDifference
                              << " more eagles than " << people[0] << " and " << eagleDifferenceTwo << " more eagles than "
                              << people[1] << endl;
          }


          else if ((personOneEagle == personTwoEagle) && (personOneEagle == personFourEagle))
          {
            cout << "System overload. Unable to determine true winner. Unfortunately this system has declared " << people[0] << " and "
                 << people[1] << " and " << people[3]
                 << " all winners. Feel free to do an extra round by yourself to determine true winner if you wish for there to be only one true winner" << endl;
          }
     }
  }








  //This will determine if there is a tie breaker between players 1, 3, and 4
  if ((one == three) && (one == four))
  {

      if ((personOneBirdie > personThreeBirdie) && (personOneBirdie > personFourBirdie))
      {
        birdieDifference = personOneBirdie - personThreeBirdie;
        birdieDifferenceTwo = personOneBirdie - personFourBirdie;
        cout << people[0] << " won the tie breaker with " << people[2] << " and " << people[3] << " by having " << birdieDifference
             << " more birdies than " << people[2] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[3] << endl;
      }


      else if ((personThreeBirdie > personOneBirdie) && (personThreeBirdie > personFourBirdie))
      {
        birdieDifference = personThreeBirdie - personOneBirdie;
        birdieDifferenceTwo = personThreeBirdie - personFourBirdie;
        cout << people[2] << " won the tie breaker with " << people[0] << " and " << people[3] << " by having " << birdieDifference
             << " more birdies than " << people[0] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[3] << endl;
      }


      else if ((personFourBirdie > personOneBirdie) && (personFourBirdie > personThreeBirdie))
      {
        birdieDifference = personFourBirdie - personOneBirdie;
        birdieDifferenceTwo = personFourBirdie - personThreeBirdie;
        cout << people[3] << " won the tie breaker with " << people[0] << " and " << people[2] << " by having " << birdieDifference
             << " more birdies than " << people[0] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[2] << endl;
      }


      //If all players tied tie in birdies, then eagles are evaluated
      else if ((personOneBirdie == personThreeBirdie) && (personOneBirdie == personFourBirdie))

      {

          if ((personOneEagle > personThreeEagle) && (personOneEagle > personFourEagle))
          {
            eagleDifference = personOneEagle - personThreeEagle;
            eagleDifferenceTwo = personOneEagle - personFourEagle;
            cout << people[0] << " won the tie breaker and tie birdie breaker with " << people[2] << " and " << people[3] << " by having " << eagleDifference
                 << " more eagles than " << people[2] << " and " << eagleDifferenceTwo << " more eagles than "
                 << people[3] << endl;
          }


          else if ((personThreeEagle > personOneEagle) && (personThreeEagle > personFourEagle))
          {
            eagleDifference = personThreeEagle - personOneEagle;
            eagleDifferenceTwo = personThreeEagle - personFourEagle;
            cout << people[2] << " won the tie breaker and tie birdie breaker with " << people[0] << " and " << people[3] << " by having " << eagleDifference
                 << " more eagles than " << people[0] << " and " << eagleDifferenceTwo << " more eagles than "
                 << people[3] << endl;
          }


          else if ((personFourEagle > personOneEagle) && (personFourEagle > personThreeEagle))
          {
            eagleDifference = personFourEagle - personOneEagle;
            eagleDifferenceTwo = personFourEagle - personThreeEagle;
            cout << people[3] << " won the tie breaker with " << people[0] << " and " << people[2] << " by having " << eagleDifference
                              << " more eagles than " << people[0] << " and " << eagleDifferenceTwo << " more eagles than "
                              << people[2] << endl;
          }


          else if ((personOneEagle == personThreeEagle) && (personOneEagle == personFourEagle))
          {
            cout << "System overload. Unable to determine true winner. Unfortunately this system has declared " << people[0] << " and "
                 << people[2] << " and " << people[3]
                 << " all winners. Feel free to do an extra round by yourself to determine true winner if you wish for there to be only one true winner" << endl;
          }
     }
  }








  //This will determine if there is a tie breaker between players 2, 3, and 4
  if ((two == three) && (two == four))
  {

      if ((personTwoBirdie > personThreeBirdie) && (personTwoBirdie > personFourBirdie))
      {
        birdieDifference = personTwoBirdie - personThreeBirdie;
        birdieDifferenceTwo = personTwoBirdie - personFourBirdie;
        cout << people[1] << " won the tie breaker with " << people[2] << " and " << people[3] << " by having " << birdieDifference
             << " more birdies than " << people[2] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[3] << endl;
      }


      else if ((personThreeBirdie > personTwoBirdie) && (personThreeBirdie > personFourBirdie))
      {
        birdieDifference = personThreeBirdie - personTwoBirdie;
        birdieDifferenceTwo = personThreeBirdie - personFourBirdie;
        cout << people[2] << " won the tie breaker with " << people[1] << " and " << people[3] << " by having " << birdieDifference
             << " more birdies than " << people[1] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[3] << endl;
      }


      else if ((personFourBirdie > personTwoBirdie) && (personFourBirdie > personThreeBirdie))
      {
        birdieDifference = personFourBirdie - personTwoBirdie;
        birdieDifferenceTwo = personFourBirdie - personThreeBirdie;
        cout << people[3] << " won the tie breaker with " << people[1] << " and " << people[2] << " by having " << birdieDifference
             << " more birdies than " << people[1] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[2] << endl;
      }


      //If all players tied tie in birdies, then eagles are evaluated
      else if ((personTwoBirdie == personThreeBirdie) && (personTwoBirdie == personFourBirdie))
      {

          if ((personTwoEagle > personThreeEagle) && (personTwoEagle > personFourEagle))
          {
            eagleDifference = personTwoEagle - personThreeEagle;
            eagleDifferenceTwo = personTwoEagle - personFourEagle;
            cout << people[1] << " won the tie breaker and tie birdie breaker with " << people[2] << " and " << people[3] << " by having " << eagleDifference
                 << " more eagles than " << people[2] << " and " << eagleDifferenceTwo << " more eagles than "
                 << people[3] << endl;
          }


          else if ((personThreeEagle > personTwoEagle) && (personThreeEagle > personFourEagle))
          {
            eagleDifference = personThreeEagle - personTwoEagle;
            eagleDifferenceTwo = personThreeEagle - personFourEagle;
            cout << people[2] << " won the tie breaker and tie birdie breaker with " << people[1] << " and " << people[3] << " by having " << eagleDifference
                 << " more eagles than " << people[1] << " and " << eagleDifferenceTwo << " more eagles than "
                 << people[3] << endl;
          }


          else if ((personFourEagle > personTwoEagle) && (personFourEagle > personThreeEagle))
          {
            eagleDifference = personFourEagle - personTwoEagle;
            eagleDifferenceTwo = personFourEagle - personThreeEagle;
            cout << people[3] << " won the tie breaker with " << people[1] << " and " << people[2] << " by having " << eagleDifference
                              << " more eagles than " << people[1] << " and " << eagleDifferenceTwo << " more eagles than "
                              << people[2] << endl;
          }


          else if ((personTwoEagle == personThreeEagle) && (personTwoEagle == personFourEagle))
          {
            cout << "System overload. Unable to determine true winner. Unfortunately this system has declared " << people[1] << " and "
                 << people[2] << " and " << people[3]
                 << " all winners. Feel free to do an extra round by yourself to determine true winner if you wish for there to be only one true winner" << endl;
          }
     }
  }








  //This will determien if there is a tie breaker between all players
  if ((one == two) && (one == three) && (one == four))
  {

      if ((personOneBirdie > personTwoBirdie) && (personOneBirdie > personThreeBirdie) && (personOneBirdie > personFourBirdie))
      {
        birdieDifference = personOneBirdie - personTwoBirdie;
        birdieDifferenceTwo = personOneBirdie - personThreeBirdie;
        birdieDifferenceThree = personOneBirdie - personFourBirdie;
    
        cout << people[0] << " won the tie breaker with all players by having " << birdieDifference
             << " more birdies than " << people[1] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[2] << " and " << birdieDifferenceThree << " more birdies than " << people[3] << endl;      
      }


      else if ((personTwoBirdie > personOneBirdie) && (personTwoBirdie > personThreeBirdie) && (personTwoBirdie > personFourBirdie))
      {
        birdieDifference = personTwoBirdie - personOneBirdie;
        birdieDifferenceTwo = personTwoBirdie - personThreeBirdie;
        birdieDifferenceThree = personTwoBirdie - personFourBirdie;
        cout << people[1] << " won the tie breaker with all players by having " << birdieDifference
             << " more birdies than " << people[0] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[2] << " and " << birdieDifferenceThree << " more birdies than " << people[3] << endl;
      }


      else if ((personThreeBirdie > personOneBirdie) && (personThreeBirdie > personTwoBirdie) && (personThreeBirdie > personFourBirdie))
      {
        birdieDifference = personThreeBirdie - personOneBirdie;
        birdieDifferenceTwo = personThreeBirdie - personTwoBirdie;
        birdieDifferenceThree = personThreeBirdie - personFourBirdie;
        cout << people[2] << " won the tie breaker with all players by having " << birdieDifference
             << " more birdies than " << people[0] << " and " << birdieDifferenceTwo << " more birdies than "
             << people[1] << " and " << birdieDifferenceThree << " more birdies than " << people[3] << endl;
      }


      else if ((personFourBirdie > personOneBirdie) && (personFourBirdie > personTwoBirdie) && (personFourBirdie > personThreeBirdie))
      {
        birdieDifference = personFourBirdie - personOneBirdie;
        birdieDifferenceTwo = personFourBirdie - personTwoBirdie;
        birdieDifferenceThree = personFourBirdie - personThreeBirdie;
        cout << people[3] << " won the tie breaker with all players by having " << birdieDifference
             << " more birdies than " << people[0] << " and " << birdieDifferenceTwo << " more birdies than " 
             << people[1] << " and " << birdieDifferenceThree << " more birdies than " << people[2] << endl;
      }


      //If all players tied tie in birdies, then eagles are evaluated
      else if ((personOneBirdie == personTwoBirdie) && (personOneBirdie == personThreeBirdie) && (personOneBirdie == personFourBirdie))
      {

          if ((personOneEagle > personTwoEagle) && (personOneEagle > personThreeEagle) && (personOneEagle > personFourEagle))
          {
            eagleDifference = personOneEagle - personTwoEagle;
            eagleDifferenceTwo = personOneEagle - personThreeEagle;
            eagleDifferenceThree = personOneEagle - personFourEagle;
            cout << people[0] << " won the tie breaker and tie birdie breaker with all players by having " << eagleDifference
                 << " more eagles than " << people[1] << " and " << eagleDifferenceTwo << " more eagles than "
                 << people[2] << " and " << eagleDifferenceThree << " more eagles than " << people[3] << endl;
          }


          else if ((personTwoEagle > personOneEagle) && (personTwoEagle > personThreeEagle) && (personTwoEagle > personFourEagle))
          {
            eagleDifference = personTwoEagle - personOneEagle;
            eagleDifferenceTwo = personTwoEagle - personThreeEagle;
            eagleDifferenceThree = personTwoEagle - personFourEagle;
            cout << people[1] << " won the tie breaker and tie birdie breaker with all players by having " << eagleDifference
                 << " more eagles than " << people[0] << " and " << eagleDifferenceTwo << " more eagles than "
                 << people[2] << " and " << eagleDifferenceThree << " more eagles than " << people[3] << endl;
          }


          else if ((personThreeEagle > personOneEagle) && (personThreeEagle > personTwoEagle) && (personThreeEagle > personFourEagle))
          {
            eagleDifference = personThreeEagle - personOneEagle;
            eagleDifferenceTwo = personThreeEagle - personTwoEagle;
            eagleDifferenceThree = personThreeEagle - personFourEagle;
            cout << people[2] << " won the tie breaker and tie birdie breaker with all players by having " << eagleDifference
                 << " more eagles than " << people[0] << " and " << eagleDifferenceTwo << " more eagles than "
                 << people[1] << " and " << eagleDifferenceThree << " more eagles than " << people[3] << endl;
          }


          else if ((personFourEagle > personOneEagle) && (personFourEagle > personTwoEagle) && (personFourEagle > personThreeEagle))
          {
            eagleDifference = personFourEagle - personOneEagle;
            eagleDifferenceTwo = personFourEagle - personTwoEagle;
            eagleDifferenceThree = personFourEagle - personThreeEagle;
            cout << people[3] << " won the tie breaker and tie birdie breaker with all players by having " << eagleDifference
                 << " more eagles than " << people[0] << " and " << eagleDifferenceTwo << " more eagles than "
                 << people[1] << " and " << eagleDifferenceThree << " more eagles than " << people[2] << endl;
          }

          else if ((personOneEagle == personTwoEagle) && (personOneEagle == personThreeEagle) && (personOneEagle == personFourEagle))
          {
            cout << "System overload. Unable to determine true winner. Unfortunately this system has declared that all players win. Feel free to do an extra round by yourself to determine true winner if you wish for there to be only one true winner" << endl;
          }
     }
  }



}










//Function: creating and outputting the 9-hole subtotal (in parenthases) next to each player's name and their total score
void nineHoles(string people[], char one[], char two[], char three[], char four[], char five[], char six[], 
     char seven[], char eight[], char nine[], char ten[], char eleven[], char twelve[], char thirteen[], 
     char fourteen[], char fifteen[], char sixteen[], char seventeen[], char eighteen[], int oneTotal, 
     int twoTotal, int threeTotal, int fourTotal)
{

  int i;


  //Removing the char component from player one's scores so they add their actual numbers and not the ASCII table numbers that correlate with their value
  int aOne = one[0] - 48, bOne = two[0] - 48, cOne = three[0] - 48, dOne = four[0] - 48, eOne = five[0] - 48, fOne = six[0] - 48;
  int gOne = seven[0] - 48, hOne = eight[0] - 48, iOne = nine[0] - 48, jOne = ten[0] - 48, kOne = eleven[0] - 48, lOne = twelve[0] - 48;
  int mOne = thirteen[0] - 48, nOne = fourteen[0] - 48, oOne = fifteen[0] - 48, pOne = sixteen[0] - 48, qOne = seventeen[0] - 48;
  int rOne = eighteen[0] - 48;


  //Removing the char component from player two's scores so they add their actual numbers and not the ASCII table numbers that correlate with their value
  int aTwo = one[1] - 48, bTwo = two[1] - 48, cTwo = three[1] - 48, dTwo = four[1] - 48, eTwo = five[1] - 48, fTwo = six[1] - 48;
  int gTwo = seven[1] - 48, hTwo = eight[1] - 48, iTwo = nine[1] - 48, jTwo = ten[1] - 48, kTwo = eleven[1] - 48, lTwo = twelve[1] - 48;
  int mTwo = thirteen[1] - 48, nTwo = fourteen[1] - 48, oTwo = fifteen[1] - 48, pTwo = sixteen[1] - 48, qTwo = seventeen[1] - 48;
  int rTwo = eighteen[1] - 48;


  //Removing the char component from player three's scores so they add their actual numbers and not the ASCII table numbers that correlate with their value
  int aThree = one[2] - 48, bThree = two[2] - 48, cThree = three[2] - 48, dThree = four[2] - 48, eThree = five[2] - 48, fThree = six[2] - 48;
  int gThree = seven[2] - 48, hThree = eight[2] - 48, iThree = nine[2] - 48, jThree = ten[2] - 48, kThree = eleven[2] - 48, lThree = twelve[2] - 48;
  int mThree = thirteen[2] - 48, nThree = fourteen[2] - 48, oThree = fifteen[2] - 48, pThree = sixteen[2] - 48, qThree = seventeen[2] - 48;
  int rThree = eighteen[2] - 48;


  //Removing the char component from player four's scores so they add their actual numbers and not the ASCII table numbers that correlate with their value
  int aFour = one[3] - 48, bFour = two[3] - 48, cFour = three[3] - 48, dFour = four[3] - 48, eFour = five[3] - 48, fFour = six[3] - 48;
  int gFour = seven[3] - 48, hFour = eight[3] - 48, iFour = nine[3] - 48, jFour = ten[3] - 48, kFour = eleven[3] - 48, lFour = twelve[3] - 48;
  int mFour = thirteen[3] - 48, nFour = fourteen[3] - 48, oFour = fifteen[3] - 48, pFour = sixteen[3] - 48, qFour = seventeen[3] - 48;
  int rFour = eighteen[3] - 48;



  //Adding up first 9 hole subtotal for player one
  int oneFirst= aOne + bOne + cOne + dOne + eOne + fOne + gOne + hOne + iOne;

  
  //Adding up second 9 hole subtotal for player one
  int oneSecond = jOne + kOne + lOne + mOne + nOne + oOne + pOne + qOne + rOne;


  //Adding up first 9 hole subtotal for player two
  int twoFirst = aTwo + bTwo + cTwo + dTwo + eTwo + fTwo + gTwo + hTwo + iTwo;

 
  //Adding up second 9 hole subtotal for player two
  int twoSecond = jTwo + kTwo + lTwo + mTwo + nTwo + oTwo + pTwo + qTwo + rTwo;

 
  //Addign up first 9 hole subtotal for player three
  int threeFirst = aThree + bThree + cThree + dThree + eThree + fThree + gThree + hThree + iThree;

 
  //Adding up second 9 hole subtotal for player three
  int threeSecond = jThree + kThree + lThree + mThree + nThree + oThree + pThree + qThree + rThree;

 
  //Adding up first 9 hole subtotal for player four
  int fourFirst = aFour + bFour + cFour + dFour + eFour + fFour + gFour + hFour + iFour;


  //Adding up second 9 hole subtotal for player four
  int fourSecond = jFour + kFour + lFour + mFour + nFour + oFour + pFour + qFour + rFour;





  //Outputting my person names, their total, and their 9 subtotals --> Ex: (39 - 41) = first 9-subtotal is 39 strokes and the second 9-subtotal is 41 strokes

  cout << setw(7) << people[0] << setw(4) << oneTotal << setw(4) << "(" << oneFirst << " - " << oneSecond << ")" << endl;
  cout << setw(7) << people[1] << setw(4) << twoTotal << setw(4) << "(" << twoFirst << " - " << twoSecond << ")" << endl;
  cout << setw(7) << people[2] << setw(4) << threeTotal << setw(4) << "(" << threeFirst << " - " << threeSecond << ")" << endl;
  cout << setw(7) << people[3] << setw(4) << fourTotal << setw(4) << "(" << fourFirst << " - " << fourSecond << ")" << endl;





return;
}
