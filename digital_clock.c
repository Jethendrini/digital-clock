
#include <stdio.h>
#include <string.h>
#include <time.h>

long getOffsetSeconds(const char *country) {
    if (strcmp(country, "india") == 0)
        return 19800;      // +5:30
    else if (strcmp(country, "usa") == 0)
        return -18000;     // -5:00
    else if (strcmp(country, "uk") == 0)
        return 0;          // GMT
    else if (strcmp(country, "japan") == 0)
        return 32400;     // +9:00
    else if (strcmp(country, "china") == 0)
        return 28800;     // +8:00
    else if (strcmp(country, "singapore") == 0)
        return 28800;     // +8:00
    else if (strcmp(country, "saudi") == 0)
        return 10800;     // +3:00
    else
        return 0;
}

void printTime(const char *label, time_t t) {
    struct tm *tm_info = gmtime(&t);

    printf("%s %02d:%02d:%02d\n",
           label,
           tm_info->tm_hour,
           tm_info->tm_min,
           tm_info->tm_sec);
}

int main() {
    char country[50];

    printf("Enter country name: ");
    scanf("%s", country);

    time_t now = time(NULL);   // current UTC-based time

    long offset = getOffsetSeconds(country);
    time_t country_time = now + offset;

    printf("\n--- CURRENT WORLD TIME ---\n");
    printTime(country, country_time);

    return 0;
}
