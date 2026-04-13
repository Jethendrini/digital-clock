
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#else
#include <unistd.h>
#endif

// Convert country → timezone
const char* getTimezone(char country[]) {
    if (strcmp(country, "india") == 0)
        return "Asia/Kolkata";
    else if (strcmp(country, "usa") == 0)
        return "America/New_York";
    else if (strcmp(country, "uk") == 0)
        return "Europe/London";
    else if (strcmp(country, "japan") == 0)
        return "Asia/Tokyo";
    else if (strcmp(country, "australia") == 0)
        return "Australia/Sydney";
    else
        return NULL;
}

int main() {
    char country[50];

    printf("Enter country (india, usa, uk, japan, australia): ");
    scanf("%s", country);

    const char* tz = getTimezone(country);

    if (tz == NULL) {
        printf("Country not supported!\n");
        return 1;
    }

    while (1) {

        // ----- COUNTRY TIME -----
        setenv("TZ", tz, 1);
        tzset();
        time_t now = time(NULL);
        struct tm *local = localtime(&now);

        int country_hour = local->tm_hour;
        int country_min = local->tm_min;
        int country_sec = local->tm_sec;

        // ----- IST TIME -----
        setenv("TZ", "Asia/Kolkata", 1);
        tzset();
        time_t now2 = time(NULL);
        struct tm *ist = localtime(&now2);

        int ist_hour = ist->tm_hour;
        int ist_min = ist->tm_min;
        int ist_sec = ist->tm_sec;

        printf("\r%s Time: %02d:%02d:%02d | IST: %02d:%02d:%02d",
               country,
               country_hour, country_min, country_sec,
               ist_hour, ist_min, ist_sec);

        fflush(stdout);
        sleep(1);
    }

    return 0;
}
