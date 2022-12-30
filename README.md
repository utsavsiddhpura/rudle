#HOW TO RUN?

1. First download both files and keep them in the same folder. 
2. Open terminal or cmd in the same folder.
3. First compile the program with the command: g++ wordle.cpp -o wordle
4. Run the program with the command: ./wordle
5. The program will exit once the 6 trials are over or you win.
6. Repeat from 1. to play again.

#RULES:

1. You have six trials to guess a 5 letter word.
2. For each trial word, when you enter the word, you will get the status of each letter in the word.
3. X beside a letter means the letter doesn't belong to the desired word.
4. Y beside a letter means the letter does belong to the desired word but the possition is different.
5. G beside a letter means the letter is the same and in the same position as the letter in the desired word.

#OPTIMIZATION:

You can add new 5 letter words in the words.txt file to extend your set of words.
