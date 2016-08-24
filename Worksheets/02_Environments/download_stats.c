/**
 * @brief Answers to question 3
 *
 * @author Even A. Nilsen
 * @version 15.08.2016
 */

#include <stdio.h>

#include "download_stats.h"

/**
 * Takes current time and start time in seconds elapsed since 1970 and returns
 * the elapsed download time
 * @param time current time
 * @param startTime when the download started
 * @return elapsedTime
 */
int elapsed_time(int time, int startTime)
{
    int elapsedTime;
    elapsedTime = time - startTime;

    return elapsedTime;
}

/**
 * Calculates the percentage of completeness using simple arithmetic
 * @param bytes amount of downloaded bytes
 * @param totalBytes file size in bytes
 * @return percentComplete
 */
double percent_complete(double bytes, double totalBytes)
{
    double percentComplete;
    percentComplete = ((bytes * 100) / totalBytes);

    return percentComplete;
}

/**
 * Calculates the current download speed in seconds
 * @param time current time
 * @param startTime when the download started
 * @param totalBytes file size in bytes
 * @return downloadSpeed
 */
double download_speed(int time, int startTime, double bytes)
{
    double elapsedTime, downloadSpeed; 

    elapsedTime = (double)elapsed_time(time, startTime);
    downloadSpeed = bytes / elapsedTime;

    return downloadSpeed;
}

/**
 * Calculates the estimated total time in seconds
 * @param time current time
 * @param startTime when the download started
 * @param bytes amount of downloaded bytes
 * @param totalBytes file size in bytes
 * @return totalTime
 */
double total_time(int time, int startTime, double bytes, double totalBytes)
{
    double elapsedTime, totalTime;

    elapsedTime = (double)elapsed_time(time, startTime);
    totalTime = totalBytes * elapsedTime / bytes;

    return totalTime;
}

/**
 * Calculates the estimated remaining time
 * @param time current time
 * @param startTime when the download started
 * @param bytes amount of downloaded bytes
 * @param totalBytes file size in bytes
 * @return remainingTime
 */
double remaining_time(int time, int startTime, double bytes, double totalBytes)
{
    double totalTime, elapsedTime, remainingTime;

    totalTime = total_time(time, startTime, bytes, totalBytes);
    elapsedTime = (double)elapsed_time(time, startTime);
    remainingTime = totalTime - elapsedTime;

    return remainingTime;
}
