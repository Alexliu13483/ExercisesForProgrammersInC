/*
 * EmployeeListRemoval.h
 *
 *  Created on: 2017�~8��3��
 *      Author: Alex.Liu
 */

#ifndef INCLUDE_34_EMPLOYEELISTREMOVAL_EMPLOYEELISTREMOVAL_H_
#define INCLUDE_34_EMPLOYEELISTREMOVAL_EMPLOYEELISTREMOVAL_H_

typedef struct {
	int num;
	char ** names;
} NameList;

void EmployeeListRemoval_create();
void EmployeeListRemoval_remove( NameList * namelist);

#endif /* INCLUDE_34_EMPLOYEELISTREMOVAL_EMPLOYEELISTREMOVAL_H_ */
