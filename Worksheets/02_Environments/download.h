/**
 * download.h - header file for download.c
 *
 * @author  Even A. Nilsen
 * @version 15.08.2016
 */

#ifndef DOWNLOAD_H
#define DOWNLOAD_H 

#define ELAPSED_TIME(time,startTime) ((time) - (startTime))
#define PERCENT_COMPLETE(bytes,totalBytes) (((bytes) * 100) / (totalBytes))
#define DOWNLOAD_SPEED(time,startTime,bytes) ((bytes) / ELAPSED_TIME((time),(startTime))) 
#define TOTAL_TIME(time,startTime,bytes,totalBytes) (((totalBytes) * ELAPSED_TIME((time),(startTime))) / (bytes))
#define REMAINING_TIME(time,startTime,bytes,totalBytes) (TOTAL_TIME((time),(startTime),(bytes),(totalBytes)) - ELAPSED_TIME((time),(startTime)))

#endif /* ifndef DOWNLOAD_H */
