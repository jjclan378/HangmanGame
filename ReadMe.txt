This project took me about 3 hours

Here is my outline of my code that I made while I was planning how I would complete this project

Main function
  welcomes players
  while the player wants to play
    call playHangmanGame to play the game, keeping track of how many games they have won
  once the player is done playing, thank them for playing and prompt them to enter any key to exit
  
generateRandomWord function (called in playHangmanGame function)
  selects a random word from our library
  makes sure that the word is not the same as the previous round's
  
doesUserWantToPlayAgain function (called in Main)
  asks the user if they want to play again or if they want to quit
  
updateUserFacingString function (called in playHangmanGame function)
  replaces all the dashes with the characters that have been correctly guessed by the user
  
checkIfTheyWon (called in playHangmanGame function)
  will check the string that has been updated with the user's correct guesses for dashes to find out if they have won or not
  
getUserGuess (called in playHangmanGame function)
  receive user input and make sure that it is valid
  
playHangmanGame (called in Main function)
  calls generateRandomWord to get new answer word
  reveals the size of the word that the user is to guess
  while the user has remaining guesses and they have not won yet
    call getUserGuess
    determine if the guess is a repeat guess, correct guess, incorrect guess, or if there has been in an error with the input
    keep track of number of used guesses and what letters have been guessed
  if the user wins, tell them how many guesses it took them
  
  
  
I separated the code into these function mainly to improve readability
I added a few features such as keeping track of the score and limited error handling because I thought it added to the game
    
I also added the gallows as part of the extra credit in a new function called printGallows, which simply 
has a switch case to find out which version of the text-based gallows to print out
