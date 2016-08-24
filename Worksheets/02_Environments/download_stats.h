/**
 * @brief Answers to question 3
 *
 * @author Even A. Nilsen
 * @version 15.08.2016
 */

#ifndef DOWNLOAD_STATS_H
#define DOWNLOAD_STATS_H 

int elapsed_time(int time, int startTime);
double percent_complete(double bytes, double totalBytes);
double download_speed(int time, int startTime, double bytes);
double total_time(int time, int startTime, double bytes, double totalBytes);
double remaining_time(int time, int startTime, double bytes, double totalBytes);

#endif /* ifndef DOWNLOAD_STATS_H */
