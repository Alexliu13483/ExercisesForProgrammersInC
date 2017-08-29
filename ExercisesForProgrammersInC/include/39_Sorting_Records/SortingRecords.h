/*
 * SortingRecords.h
 *
 *  Created on: 2017¦~8¤ë23¤é
 *      Author: Alex.Liu
 */

#ifndef INCLUDE_39_SORTING_RECORDS_SORTINGRECORDS_H_
#define INCLUDE_39_SORTING_RECORDS_SORTINGRECORDS_H_

void SortingRecords_create();
void SortingRecords_destroy();
void SortingRecords_sort(char * inputRecords);
int SortingRecords_CreateDatabase(char * inputData);
void SortingRecords_filter(char * strFilter, int * results);
void SortingRecords_printRecords(int * inxRecords);

#endif /* INCLUDE_39_SORTING_RECORDS_SORTINGRECORDS_H_ */
