# Hangman
C++ Hangman, runs in command console.

This game generates two vectors from two text files, hints.txt and words.txt. Each file can be easily customized and modified as needed.

Each file is read line by line so the first line in hints.txt will pair with the first line of word.txt. The lines are terminated when a 'return/enter' character is read. 

*Spaces are allowed
*Each word being guessed is case sensitive!
*make sure the list does not end with a blank line -- Do not press return after the last word/hint
*The words / hints must be on the same line for them to be paired correctly.

A random number is generated and used as the index to select a word/hint pair. The word is then used to display a series of asterisks matching the length of the word -- blank spaces are displayed if there is a space in the word.

'1' can be input to display a hint for the player
and case sensitive characters can be input - this is incase there is a proper noun - in this case the name of a State.

*Each letter being entered is displayed for the player.
*The game will display repeated chracters - if there are multiple 'e' it only has to be input one time - unless the word includes a capital 'E'
*The player will not be penalized for entering a previously used character.
*The player has 7 'lives' - the hangman will be fully visible on the 6th failed entry - the 7th life is to make each round last a little longer, sort of a last ditch effort to save the hangman.

*********
KNOWN ISSUE
*********
if the player were for some reason enter a string of non-repeating characters and either solve the word or lose the game - the game will treat the remaining characters in the buffer as input for the following prompt and execute accordingly. 

