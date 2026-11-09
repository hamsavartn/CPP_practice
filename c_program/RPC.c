#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void determine_winner(char* user, char* computer) {
    if (strcmp(user, computer) == 0) {
        printf("It's a tie!\n");
    } else if ((strcmp(user, "rock") == 0 && strcmp(computer, "scissors") == 0) ||
               (strcmp(user, "paper") == 0 && strcmp(computer, "rock") == 0) ||
               (strcmp(user, "scissors") == 0 && strcmp(computer, "paper") == 0)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

int main() {
    char* choices[] = {"rock", "paper", "scissors"};
    char user_choice[20];
    
    // Seed the random number generator
    srand(time(NULL));
    
    printf("--- Rock, Paper, Scissors ---\n");
    printf("Type 'quit' to exit the game.\n");
    
    while (1) {
        printf("\nEnter rock, paper, or scissors: ");
        scanf("%19s", user_choice);
        
        // Lowercase logic can be skipped if inputting exactly as requested
        if (strcmp(user_choice, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }
        
        // Validate user input
        if (strcmp(user_choice, "rock") != 0 && 
            strcmp(user_choice, "paper") != 0 && 
            strcmp(user_choice, "scissors") != 0) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }
        
        // Generate computer choice
        int random_index = rand() % 3;
        char* computer_choice = choices[random_index];
        printf("Computer chose: %s\n", computer_choice);
        
        determine_winner(user_choice, computer_choice);
    }
    
    return 0;
}
