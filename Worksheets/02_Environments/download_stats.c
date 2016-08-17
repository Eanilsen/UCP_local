#include <stdio.h>

#include "download_stats.h"

int elapsed_time(int time, int startTime)
{
    int elapsedTime;
    elapsedTime = time - startTime;

    return elapsedTime;
}

double percent_complete(double bytes, double totalBytes)
{
    return ((bytes * 100) / totalBytes);
}

double download_speed(int time, int startTime, double bytes)
{
    double elapsedTime, downloadSpeed; 

    elapsedTime = (double)elapsed_time(time, startTime);
    downloadSpeed = bytes / elapsedTime;

    return downloadSpeed;
}

double total_time(int time, int startTime, double bytes, double totalBytes)
{
    double elapsedTime, totalTime;

    elapsedTime = (double)elapsed_time(time, startTime);
    totalTime = totalBytes * elapsedTime / bytes;

    return totalTime;
}

double remaining_time(int time, int startTime, double bytes, double totalBytes)
{
    double totalTime, elapsedTime, remainingTime;

    totalTime = total_time(time, startTime, bytes, totalBytes);
    elapsedTime = (double)elapsed_time(time, startTime);
    remainingTime = totalTime - elapsedTime;

    return remainingTime;
}
