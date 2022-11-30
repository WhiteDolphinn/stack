#include "log.h"
#include "stack.h"
#include <time.h>
#include <assert.h>

FILE* get_log_file()
{
    time_t timer = time(NULL);
    struct tm* time = localtime(&timer);


    static int is_got = 0;

    char filename[100] = "";

    sprintf(filename, ".log/%d_%d_%d_%d_%d_log.txt", time->tm_hour, time->tm_min, time->tm_mday,
            time->tm_mon+1, time->tm_year+1900);

    if(is_got == 0)
    {
        is_got = 1;
        FILE* file = nullptr;

        if(PRINT_IN_CONSOLE == 0)
            file = fopen(filename, "w");
        else
            file = stdout;

        if(file == nullptr)
        {
            printf("I can't open log file.\n");
            printf("Please, create directory .log\n");
            assert(0);
        }

        return file;
    }
    else
    {
        FILE* file;
        if(PRINT_IN_CONSOLE == 0)
            file = fopen(filename, "a");
        else
            file = stdout;

        if(file == nullptr)
        {
            printf("I can't open log file.\n");
            printf("Please, create directory .log\n");
            assert(0);
        }

        return file;
    }
}
