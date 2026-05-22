/*  === AGE LOGGER ===
 *  
 * |= DOCUMENTATION =|
 * 
 * A terminal utility that asks for user age, validates input,
 * and logs the age with a timestamp to age.log.
 * 
 * Settings (change at the top of main()):
 * - MAX_ATTEMPTS : max retries on invalid input (default 3)
 * - MAX_AGE      : max allowed age (127)
 * - MIN_AGE      : min allowed age (0)
- ADULT_AGE    : age threshold for "Baby" message (14)
*/

// ====== Library ========
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
// =======================

// ===== Color ===========
#define RED   "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE  "\033[34m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
// =======================

// ===== Program setting (change this) =====
#define MAX_ATTEMPTS   3
#define MIN_AGE        0
#define MAX_AGE        127
#define ADULT_AGE      14
#define LOG_FILENAME   "age.log"
// =========================================

// === Function ============================
int validate_age(const int *input) {
    for (size_t i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
        if (!isdigit((unsigned char)input[i])) {
         write(2, RED "Only numbers\n" RESET, strlen(RED "Only numbers\n" RESET));
        return 1;
        }
    }
    return 1; 
}
// ========================================

struct LogEntry {
    int age;
    time_t timestamp;
};

int attempts = 0;
    int main(void) {
    extern int is_valid_age(int age);

        struct LogEntry entry;
        
        write(1, CYAN "=== Age logger === \n" RESET, strlen(CYAN "=== Age logger ===\n" RESET));
        
        int *age = (int*)malloc(sizeof(int));
                if (age == NULL) {
                    perror("malloc");
                    return 1;
                }

        //Ограничение попыток на ввод
        //Если хотите другое количество попыток то измените 3 //
        while (attempts < MAX_ATTEMPTS) { 
            write(1, YELLOW "Enter the age: \n",
            strlen("Enter the age: " RESET));
            
        //Вывод количества попыток
            char attempts_msg[64];
            sprintf(attempts_msg, YELLOW "Attempts left: %d\n" RESET, MAX_ATTEMPTS - attempts);
            
            write(1, attempts_msg, strlen(attempts_msg));
                if (stdout == NULL) {
                    perror("stdout");
                    return 1;
                }
                if (scanf("%d", age) == 1) break;
                     write(2, RED "Invalid input\n RESET", 14);
                     attempts++;
                     while (getchar() != '\n');
                }
        
        //Если изменить 3, вы измените количество попыток ввода
                if (attempts == 3) { 
                    write(2, RED "To many attempts\n RESET", 17);
                    return 1;
                }
            
        //Проверяеи возраст пользователя
                if (is_valid(age)) {
                    perror("age");
                    return 1;
                }
                
         //Если хотите другой минимальный возраст то измените 14 на другое число
                if (*age < ADULT_AGE) {
                    write(2, RED "Baby\n RESET", 5);
                    return 1;
                }
                
                if (scanf("%d", age) != 1) {
                    write(2, RED "invalid input\n RESET", 14);
                    return 1;
                }
        
            write(1, GREEN "Successful\n RESET", 11);

        FILE *file = fopen("age.log", "a");
                if (file == NULL) {
                    perror("fopen");
                    return 1;
                }
                
        //Записываем время когда ввели возраст
        time_t now = time(NULL);
        char *time_str = ctime(&now);
                if (time_str == NULL) {
                    perror ("time_str");
                    return 1;
                }
        
        size_t *buffer = (size_t*)malloc(sizeof(size_t));
                if (buffer == NULL) {
                    perror("buffer");
                    return 1;
                }
                
        //Записываем данные в журнал
            fprintf(file, "%s - %d\n", time_str, *age);
            fprintf(stdout, "%s - %d\n", time_str, *age);
            
            fprintf(file, "%d\n", *age);
            fprintf(stdout, "%d\n", *age);
        fclose(file);
        
        free(age);
        free(buffer);
        
        write(1, "=== Log saved succesfully ===\n", 23);
        write(1, "Goodbye!\n", 7);
    return 0;
    }