#include <stdio.h>

void displayQuestion(int q) {
    switch (q) {
        case 1:
            printf("Question 1: What is the output of SQUARE(2 + 3)?\n");
            break;
        case 2:
            printf("Question 2: What is the output of MAX(10, 15) * 2?\n");
            break;
        case 3:
            printf("Question 3: What does CONCAT(10, 20) evaluate to?\n");
            break;
        case 4:
            printf("Question 4: What does STR(Hello) evaluate to?\n");
            break;
        case 5:
            printf("Question 5: What is the output of #if DEBUG == 1 ? 'Debug' : 'Release'?\n");
            break;
        case 6:
            printf("Question 6: What is the output of #ifdef PI ? 'Defined' : 'Undefined'?\n");
            break;
        case 7:
            printf("Question 7: What is the output of #ifndef SQUARE ? 'Undefined' : 'Defined'?\n");
            break;
        case 8:
            printf("Question 8: What is the output of #if PI > 3 ? 'Yes' : 'No'?\n");
            break;
        case 9:
            printf("Question 9: What is the output of #if 0 ? 'True' : 'False'?\n");
            break;
        case 10:
            printf("Question 10: What is the output of #if 1 ? 'True' : 'False'?\n");
            break;
        case 11:
            printf("Question 11: What is the output of #define X 10; #undef X; #ifdef X ? 'Defined' : 'Undefined'?\n");
            break;
        case 12:
            printf("Question 12: What is the output of #define X 10; #if X == 10 ? 'Equal' : 'Not Equal'?\n");
            break;
        case 13:
            printf("Question 13: What is the output of #define X 10; #if X == 20 ? 'Equal' : 'Not Equal'?\n");
            break;
        case 14:
            printf("Question 14: What is the output of #define X 10; #if X != 10 ? 'Not Equal' : 'Equal'?\n");
            break;
        case 15:
            printf("Question 15: What is the output of #define X 10; #if X > 5 ? 'Greater' : 'Smaller'?\n");
            break;
        case 16:
            printf("Question 16: What is the output of #define X 10; #if X < 5 ? 'Smaller' : 'Greater'?\n");
            break;
        case 17:
            printf("Question 17: What is the output of #define X 10; #if X >= 10 ? 'Greater or Equal' : 'Smaller'?\n");
            break;
        case 18:
            printf("Question 18: What is the output of #define X 10; #if X <= 10 ? 'Smaller or Equal' : 'Greater'?\n");
            break;
        case 19:
            printf("Question 19: What is the output of #define X 10; #if X && 1 ? 'True' : 'False'?\n");
            break;
        case 20:
            printf("Question 20: What is the output of #define X 0; #if X || 1 ? 'True' : 'False'?\n");
            break;
        default:
            break;
    }
}

void main() {
    for (int i = 1; i <= 20; i++) {
        displayQuestion(i);
        printf("Press any key to continue to the next question...\n");
        getchar(); // Wait for user input
    }
}

void answers() {
    printf("\nAnswers:\n");
    printf("1. SQUARE(2 + 3) = 11 (not 25, due to macro expansion)\n");
    printf("2. MAX(10, 15) * 2 = 30\n");
    printf("3. CONCAT(10, 20) = 1020\n");
    printf("4. STR(Hello) = \"Hello\"\n");
    printf("5. #if DEBUG == 1 ? 'Debug' : 'Release' = 'Debug'\n");
    printf("6. #ifdef PI ? 'Defined' : 'Undefined' = 'Defined'\n");
    printf("7. #ifndef SQUARE ? 'Undefined' : 'Defined' = 'Defined'\n");
    printf("8. #if PI > 3 ? 'Yes' : 'No' = 'Yes'\n");
    printf("9. #if 0 ? 'True' : 'False' = 'False'\n");
    printf("10. #if 1 ? 'True' : 'False' = 'True'\n");
    printf("11. #define X 10; #undef X; #ifdef X ? 'Defined' : 'Undefined' = 'Undefined'\n");
    printf("12. #define X 10; #if X == 10 ? 'Equal' : 'Not Equal' = 'Equal'\n");
    printf("13. #define X 10; #if X == 20 ? 'Equal' : 'Not Equal' = 'Not Equal'\n");
    printf("14. #define X 10; #if X != 10 ? 'Not Equal' : 'Equal' = 'Equal'\n");
    printf("15. #define X 10; #if X > 5 ? 'Greater' : 'Smaller' = 'Greater'\n");
    printf("16. #define X 10; #if X < 5 ? 'Smaller' : 'Greater' = 'Greater'\n");
    printf("17. #define X 10; #if X >= 10 ? 'Greater or Equal' : 'Smaller' = 'Greater or Equal'\n");
    printf("18. #define X 10; #if X <= 10 ? 'Smaller or Equal' : 'Greater' = 'Smaller or Equal'\n");
    printf("19. #define X 10; #if X && 1 ? 'True' : 'False' = 'True'\n");
    printf("20. #define X 0; #if X || 1 ? 'True' : 'False' = 'True'\n");
}
