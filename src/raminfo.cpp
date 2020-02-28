#include "raminfo.h"

RamInfo::RamInfo(QObject *parent) : QObject(parent){}

int RamInfo::getTotalRam()
{
    size_t sz = 0;
    char* buf = NULL;
    int result = 0;
    FILE* fl = fopen("/proc/meminfo", "r");
    while(getline(&buf, &sz, fl) != -1)
    {
        if(strstr(buf, "MemTotal") != NULL)
        {
            sscanf(buf, "MemTotal: %d KB", &result);
            break;
        }
    }
    fclose(fl);
    free(buf);
    return result;
};
