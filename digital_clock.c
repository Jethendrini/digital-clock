
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    setenv("TZ", "Asia/Kolkata", 1);
    tzset();

    while(1) {
        time_t now = time(NULL);
        struct tm local = *localtime(&now);

        printf("\rDigital Clock (IST): %02d:%02d:%02d",
               local.tm_hour,
               local.tm_min,
               local.tm_sec);

        fflush(stdout);
        sleep(1);
    }
    return 0;
}
