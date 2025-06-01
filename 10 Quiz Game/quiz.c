#include <stdio.h>
#include <stdlib.h> // for using exit(0)
#include <string.h>
#include <ctype.h> // for using toupper()
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define MAX_QUES_LEN 300
#define MAX_OPTION_LEN 100

volatile int timeout_happened = 0;

const char *COLOR_END = "\033[0m"; // Reset text formatting to default

const char *RED = "\033[1;31m"; // Set text color to bright red

const char *GREEN = "\033[1;32m"; // Set text color to bright green

const char *YELLOW = "\033[1;33m"; // Set text color to bright yellow

const char *BLUE = "\033[1;34m"; // Set text color to bright blue

const char *PINK = "\033[1;35m";
// Set text color to bright magenta (pink)

const char *AQUA = "\033[1;36m"; // Set text color to bright cyan (aqua)

// Define a structure to represent a single question
typedef struct
{
    char text[MAX_QUES_LEN];         // The question text
    char options[4][MAX_OPTION_LEN]; // Array holding four options for the question
    char correct_option;             // Correct answer option (A, B, C, or D)
    int timeout;                     // Time allowed to answer the question (in seconds)
    int prize_money;                 // Prize money awarded for answering correctly
} Question;

// Function prototypes
int read_questions(char *file_name, Question **questions); // Reads questions from a file
void print_formatted_question(Question question);          // Displays a question with formatting
void play_game(Question *questions, int no_of_questions);  // Main function to play the game
int use_lifeline(Question *question, int *lifeline);       // Function to use available lifelines

// Global variable to hold original terminal settings
struct termios old_props;

// Terminal handling function prototypes
void reset_terminal_attributes(); // Resets terminal settings to original state
void set_terminal_attributes();   // Changes terminal settings (disable echo and canonical mode)

// Entry point of the program
int main()
{
    srand(time(NULL)); // Seed the random number generator for randomness (used in lifeline)

    set_terminal_attributes(); // Change terminal settings (non-canonical, no echo)

    // Print game welcome message in pink color
    printf("\t\t%sLet's play Who Wants To Be A Millionaire!!!%s", PINK, COLOR_END);

    Question *questions; // Pointer to store array of questions

    // Read questions from the file "questions.txt"
    int no_of_questions = read_questions("questions.txt", &questions);

    // Start playing the game with the loaded questions
    play_game(questions, no_of_questions);

    exit(0); // Exit the program successfully
}

// Signal handler function to be called when the alarm (timeout) occurs
void timeout_handler()
{
    timeout_happened = 1; // Set the global timeout flag to indicate that timeout has occurred

    // Inform the user that time has run out using red colored text
    printf("%s\n\nTime out!!!!!  Press Any Key...%s\n", RED, COLOR_END);

    fflush(stdout); // Force flush the output buffer to ensure the message is displayed immediately
}

// Function to play the quiz game using the provided list of questions
void play_game(Question *questions, int no_of_questions)
{
    int money_won = 0;       // Tracks total money won by the player
    int lifeline[] = {1, 1}; // Tracks availability of lifelines: [50/50, Skip Question]

    signal(SIGALRM, timeout_handler); // Set up a handler function to manage timeout alarm signal

    for (int i = 0; i < no_of_questions; i++)
    {
        print_formatted_question(questions[i]); // Display the current question and options
        alarm(questions[i].timeout);            // Set alarm for question timeout
        char ch = getchar();                    // Take user input (single character)
        alarm(0);                               // Cancel the alarm once input is received
        printf("%c", ch);                       // Echo the typed character
        ch = toupper(ch);                       // Convert character to uppercase for easier comparison

        if (timeout_happened == 1) // Check if time ran out before answering
        {
            break;
        }

        if (ch == 'L') // If user wants to use a lifeline
        {
            int value = use_lifeline(&questions[i], lifeline);
            if (value != 2) // If lifeline was 50/50 (not Skip), ask the same question again
            {
                i--;
            }
            continue;
        }

        if (ch == questions[i].correct_option) // Check if answer is correct
        {
            printf("%s\nCorrect!%s", GREEN, COLOR_END);
            money_won = questions[i].prize_money; // Update money won
            printf("\n%sYou have won: $ %d%s", BLUE, money_won, COLOR_END);
        }
        else // Answer is wrong
        {
            printf("%s\nWrong! Correct answer is %c.%s", RED, questions[i].correct_option, COLOR_END);
            break;
        }
    }
    // Game ends — show total money won
    printf("\n\n%sGame Over! Your total winnings are: $ %d%s\n", BLUE, money_won, COLOR_END);
}

// Function to use lifelines during the game
int use_lifeline(Question *question, int *lifeline)
{
    // Display available lifelines
    printf("\n\n%sAvailable Lifelines:%s", PINK, COLOR_END);
    if (lifeline[0])
        printf("\n%s1. Fifty-Fifty (50/50)%s", PINK, COLOR_END);
    if (lifeline[1])
        printf("\n%s2. Skip the Question%s", PINK, COLOR_END);
    printf("\n%sChoose a lifeline or 0 to return: %s", PINK, COLOR_END);

    char ch = getchar(); // Take user choice
    printf("%c", ch);    // Echo the choice

    switch (ch)
    {
    case '1':
        if (lifeline[0]) // If 50/50 lifeline is available
        {
            lifeline[0] = 0; // Mark 50/50 as used
            int removed = 0;
            while (removed < 2) // Remove two incorrect options
            {
                int num = rand() % 4; // Randomly pick an option
                if ((num + 'A') != question->correct_option &&
                    question->options[num][0] != '\0')
                {
                    question->options[num][0] = '\0'; // Erase the wrong option
                    removed++;
                }
            }
            return 1; // Indicate 50/50 used
        }
        break;

    case '2':
        if (lifeline[1]) // If Skip lifeline is available
        {
            lifeline[1] = 0; // Mark Skip as used
            return 2;        // Indicate question skipped
        }
        break;

    default:
        printf("\n%sReturning to the Question.%s", PINK, COLOR_END); // Invalid lifeline choice
        break;
    }
    return 0; // If no valid lifeline used
}

// Function to print a question and its options in a formatted way with colors
void print_formatted_question(Question question)
{
    // Print the question text in Yellow color
    printf("\n\n%s%s%s", YELLOW, question.text, COLOR_END); // The question text is printed in yellow

    // Loop through the four options and print each option with the corresponding letter (A, B, C, D)
    for (int i = 0; i < 4; i++)
    {
        if (question.options[i][0] != '\0') // Check if the option is not empty
        {
            // Print each option in Aqua color with its respective letter (A, B, C, D)
            printf("%s%c. %s%s", AQUA, ('A' + i), question.options[i], COLOR_END);
        }
    }

    // Print a message about the time left to answer in Yellow color
    printf("\n%sHurry!! You have only %d Seconds to answer..%s", YELLOW, question.timeout, COLOR_END);

    // Print a prompt to enter the answer or use a lifeline in Green color
    printf("\n%sEnter your answer (A, B, C, or D) or L for lifeline: %s", GREEN, COLOR_END);
}

// Function to read questions from a file and load them into memory
int read_questions(char *file_name, Question **questions)
{
    // Open the file in read mode
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("\nUnable to open the questions bank.");
        exit(0); // Exit if file could not be opened
    }

    char str[MAX_QUES_LEN];
    int no_of_lines = 0;

    // Count total number of lines in the file
    while (fgets(str, MAX_QUES_LEN, file))
    {
        no_of_lines++;
    }

    // Each question has 8 lines (question text, 4 options, correct option, timeout, prize)
    int no_of_questions = no_of_lines / 8;

    // Dynamically allocate memory for all questions
    *questions = (Question *)malloc(no_of_questions * sizeof(Question));

    // Reset file pointer to beginning of file
    rewind(file);

    // Read each question and its data
    for (int i = 0; i < no_of_questions; i++)
    {
        // Read the question text
        fgets((*questions)[i].text, MAX_QUES_LEN, file);

        // Read the 4 options
        for (int j = 0; j < 4; j++)
        {
            fgets((*questions)[i].options[j], MAX_OPTION_LEN, file);
        }

        // Read the correct option (e.g., 'A', 'B', etc.)
        char option[10];
        fgets(option, 10, file);
        (*questions)[i].correct_option = option[0];

        // Read the timeout value (seconds) and convert to integer
        char timeout[10];
        fgets(timeout, 10, file);
        (*questions)[i].timeout = atoi(timeout);

        // Read the prize money and convert to integer
        char prize_money[10];
        fgets(prize_money, 10, file);
        (*questions)[i].prize_money = atoi(prize_money);
    }

    // Close the file after reading
    fclose(file);

    // Return the total number of questions read
    return no_of_questions;
}

// Function to modify the terminal behavior (disable echo and canonical mode)
void set_terminal_attributes()
{
    // Save current terminal properties into old_props
    tcgetattr(STDIN_FILENO, &old_props);

    // Register the reset function to be called automatically at program exit
    atexit(reset_terminal_attributes);

    // Create a copy of old_props to modify
    struct termios new_props = old_props;

    // Disable ECHO (do not show typed characters) and ICANON (process input immediately)
    new_props.c_lflag &= ~(ECHO | ICANON);

    // Apply the new terminal settings immediately
    tcsetattr(STDIN_FILENO, TCSANOW, &new_props);
}

// Function to restore the original terminal behavior
void reset_terminal_attributes()
{
    // Reset the terminal settings to previously saved properties
    tcsetattr(STDIN_FILENO, TCSANOW, &old_props);
}
