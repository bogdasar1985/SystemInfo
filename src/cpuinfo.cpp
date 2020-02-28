#include "cpuinfo.h"

CpuInfo::CpuInfo(QObject *parent) : QObject(parent){};

QString CpuInfo::getCpuName() const
{
    size_t sz = 0;
    char* result = NULL;
    FILE* fl = fopen("/proc/cpuinfo", "r");
    while(getline(&result, &sz, fl) != -1)
    {
        if(strstr(result, "model name") != NULL)
        {
            sscanf(result, "model name : %[^\n]s", result);
            break;
        }
    }
    QString res(result);
    fclose(fl);
    free(result);
    return res;
}

QString CpuInfo::getCpuMHz()
{
    size_t sz = 0;
    char* str = NULL;
    char mhz[20];
    FILE* fl = fopen("/proc/cpuinfo", "r");
    while(getline(&str, &sz, fl) != -1)
    {
        if(strstr(str, "cpu MHz") != NULL)
        {
            sscanf(str, "cpu MHz : %s", mhz);
            break;
        }
    }
    free(str);
    fclose(fl);
    QString result(mhz);
    return result;
}

int CpuInfo::getCacheSize() const
{
    size_t sz = 0;
    char* str = NULL;
    int result = -1;
    FILE* fl = fopen("/proc/cpuinfo", "r");
    while(getline(&str, &sz, fl) != -1)
    {
        if(strstr(str, "cache size") != NULL)
        {
            sscanf(str, "cache size : %d", &result);
            break;
        }
    }
    free(str);
    fclose(fl);
    return result;
}

QString CpuInfo::getFlags() const
{
    size_t sz = 0;
    char* result = NULL;
    FILE* fl = fopen("/proc/cpuinfo", "r");
    while(getline(&result, &sz, fl) != -1)
    {
        if(strstr(result, "flags") != NULL)
        {
            sscanf(result, "flags : %[^\n]s", result);
            break;
        }
    }
    QString res(result);
    fclose(fl);
    free(result);
    return res;
}
