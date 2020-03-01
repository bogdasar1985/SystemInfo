#include "cpuinfo.h"

CpuInfo::CpuInfo(QObject *parent) : QObject(parent){};

QString CpuInfo::getCpuName()
{
    size_t sz = 0;
    char* result = nullptr;
    FILE* fl = fopen("/proc/cpuinfo", "r");
    while(getline(&result, &sz, fl) != -1)
    {
        if(strstr(result, "model name") != nullptr)
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
    char* str = nullptr;
    char mhz[20];
    FILE* fl = fopen("/proc/cpuinfo", "r");
    while(getline(&str, &sz, fl) != -1)
    {
        if(strstr(str, "cpu MHz") != nullptr)
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

int CpuInfo::getCacheSize()
{
    size_t sz = 0;
    char* str = nullptr;
    int result = -1;
    FILE* fl = fopen("/proc/cpuinfo", "r");
    while(getline(&str, &sz, fl) != -1)
    {
        if(strstr(str, "cache size") != nullptr)
        {
            sscanf(str, "cache size : %d", &result);
            break;
        }
    }
    free(str);
    fclose(fl);
    return result;
}

QString CpuInfo::getFlags()
{
    size_t sz = 0;
    char* result = nullptr;
    FILE* fl = fopen("/proc/cpuinfo", "r");
    while(getline(&result, &sz, fl) != -1)
    {
        if(strstr(result, "flags") != nullptr)
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
