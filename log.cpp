#include "log.h"
#include "stack.h"
#include <time.h>

FILE* get_log_file()
{
    time_t timer = time(NULL);
    struct tm* time = localtime(&timer);


    static int is_got = 0;
   // const char* filename = ".log/log_file.txt";
   // printf("%ld", timer);
    char filename[100] = "";
    /*sprintf(filename, ".log/log_file_%d_%d_%d_%d_%d_%d_.txt", time->tm_year + 1900, time->tm_mon + 1,
            time->tm_mday, time->tm_hour, time->tm_min, time->tm_sec);*/
    sprintf(filename, ".log/%d_%d_%d_%d_%d_log.txt", time->tm_hour, time->tm_min, time->tm_mday,
            time->tm_mon+1, time->tm_year+1900);
    //printf("%s", filename);

    if(is_got == 0)
    {
        is_got = 1;
        FILE* file;

        if(PRINT_IN_CONSOLE == 0)
            file = fopen(filename, "w");
        else
            file = stdout;

        return file;
    }
    else
    {
        FILE* file;
        if(PRINT_IN_CONSOLE == 0)
            file = fopen(filename, "a");
        else
            file = stdout;

        return file;
    }
}
