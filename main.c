#include <stdio.h>
#include <time.h>
#include <string.h>


int main() {
    FILE *fin = fopen("my.txt", "r");
    if (fin == NULL) {
        printf("The file is empty.");
        return 0;
    }
    char c = fgetc(fin);
    unsigned long long int error_cnt = 0;
    int i = 0;
    time_t t = 5000;
    struct tm *a = localtime(&t);
    printf_s("%04d/%02d/%02d %02d:%02d:%02d\n",
             a->tm_year + 1900, a->tm_mon + 1, a->tm_mday, a->tm_hour, a->tm_min, a->tm_sec);
    a->tm_mday += 30000;
    time_t next = mktime(a);
    a = localtime(&next);

    printf_s("%04d/%02d/%02d %02d:%02d:%02d\n",
             a->tm_year + 1900, a->tm_mon + 1, a->tm_mday, a->tm_hour, a->tm_min, a->tm_sec);
    return 0;
}
