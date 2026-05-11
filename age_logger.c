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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

int age;
int attempts = 0;
    int main(void) {
        write(1, "=== Age logger ===\n", 23);
        
        int *age = malloc(sizeof(int));
                if (age == NULL) {
                    perror("malloc");
                    return 1;
                }
        
        //Ограничение попыток на ввод
        //Если хотите другое количество попыток то измените 3 //
        while (attempts < 3) { 
            write(1, "Enter the age: \n",
            strlen("Enter the age: "));
                if (stdout == NULL) {
                    perror("stdout");
                    return 1;
                }
          
                if (scanf("%d", age) == 1) break;
                     write(2, "Invalid input\n", 14);
                     attempts++;
                     while (getchar() != '\n');
                }
        
        //Если изменить 3, вы измените количество попыток ввода
                if (attempts == 3) { 
                    write(2, "To many attempts\n", 17);
                    return 1;
                }
            
        //Проверяеи возраст пользователя
                if (*age < 0 || *age > 127) {
                    perror("age\n");
                    return 1;
                }
                
         //Если хотите другой минимальный возраст то измените 14 на другое число
                if (*age < 14) {
                    write(2, "Baby\n", 5);
                    return 1;
                }
                
                if (scanf("%d", &age) != 1) {
                    write(2, "invalid input\n", 14);
                    return 1;
                }
        
        //Проверка на числа
        int validate_age(const char *input) {
            for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
                if (!isdigit(input[i])) {
                    write(2, "Only number\n", 13);
                    return 1;
                }
            }
        }
        
            write(1, "Successful\n", 11);
                if (write == NULL) {
                    perror("write");
                    return 1;
                }

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
        
        size_t *buffer = malloc(sizeof(size_t));
                if (buffer == NULL) {
                    perror("buffer");
                    return 1;
                }
                
        //Записываем данные в журнал
            fprintf(file, "%s - %d\n", time_str, age);
            fprintf(stdout, "%s - %d\n", time_str, age);
            
            fprintf(file, "%d\n", age);
            fprintf(stdout, "%d\n", age);
        fclose(file);
        
        free(age);
        free(buffer);
        
        write(1, "=== Log saved succesfully ===\n", 23);
        write(1, "Goodbye!\n", 7);
    return 0;
}
