#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRIES 6

void Hangman(int mistakes)
{
    char body[7];
    switch(mistakes){
    case 1:
        body[0] = '\\'; break;
    case 2:
        body[1] = '/';  break;
    case 3:
        body[2] = '\\'; break;
    case 4:
        body[3] = '|';  break;
    case 5:
        body[4] = '/';  break;
    case 6:
        body[5] = ')';
        body[6] = '(';
        break;
    default:
        break;
    }

    printf("\t__________\n"
           "\t|         |\n"
           "\t|        %c %c\n"
           "\t|        %c%c%c\n"
           "\t|        %c %c\n"
           "\t|             \n"
           "\t|             \n",body[6],body[5],body[4],body[3],body[2],body[1],body[0]);
}

int main() {
    //Some Rules
    printf("\t\t HANGMAN  GAME\n\n");
    printf("\t Rules : \n");
    printf("- Maximum 5 mistakes are allowed.\n");
    printf("- All alphabet are in lower case.\n\n");

    // Get a word from the user
    char word[MAX_WORD_LENGTH + 1];
    printf("Enter a word: ");
    scanf("%s", word);

    // Initialize the game variables
    int word_length = strlen(word);
    char guessed_word[MAX_WORD_LENGTH];
    int num_guesses = 0;
    int num_correct_guesses = 0;
    int gameover = 0;

    // Initialize the guessed word to all underscores
    for (int i = 0; i < word_length; i++) {
        guessed_word[i] = '_';
    }
    guessed_word[word_length] = '\0';

    // Play the game
    while (!gameover) {
        // Display the current state of the game
        printf("Word: %s\n", guessed_word);
        printf("Guesses left: %d\n", MAX_TRIES - num_guesses);

        // Get a guess from the user
        printf("Enter a letter: ");
        char guess;
        scanf(" %c", &guess);

        // Check if the guess is correct
        int correct_guess = 0;
        for (int i = 0; i < word_length; i++) {
            if (word[i] == guess) {
                guessed_word[i] = guess;
                correct_guess = 1;
                num_correct_guesses++;
            }
        }

        // Update the game variables based on the guess
        if (correct_guess) {
            printf("Correct!\n");
        } else {
            printf("Incorrect!\n");
            num_guesses++;
            Hangman(num_guesses);
        }

        // Check if the game is over
        if (num_guesses >= MAX_TRIES) {
            printf("You lose! The word was %s.\n", word);
            gameover = 1;
        } else if (num_correct_guesses == word_length) {
            printf("You win! The word was %s.\n", word);
            gameover = 1;
        }
    }

    return 0;
}
