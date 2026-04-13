
#include <stdio.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#else
#include <unistd.h>
#endif

long getOffsetSeconds(const char *country) {
    if (strcmp(country, "india") == 0)
        return 19800;
    else if (strcmp(country, "usa") == 0)
        return -18000;
    else if (strcmp(country, "uk") == 0)
        return 0;
    else if (strcmp(country, "japan") == 0)
        return 32400;
    else if (strcmp(country, "china") == 0)
        return 28800;
    else if (strcmp(country, "singapore") == 0)
        return 28800;
    else if (strcmp(country, "saudi") == 0)
        return 10800;
    else
        return 0;
}

int main() {
    char country[50];

    printf("Enter country name: ");
    scanf("%s", country);

    long offset = getOffsetSeconds(country);

    while (1) {
        time_t now = time(NULL);

        time_t local_time = now + offset;
        struct tm *t = gmtime(&local_time);

        printf("\r%s Time: %02d:%02d:%02d",
               country,
               t->tm_hour,
               t->tm_min,
               t->tm_sec);

        fflush(stdout);
        sleep(1);
    }

    return 0;
}
