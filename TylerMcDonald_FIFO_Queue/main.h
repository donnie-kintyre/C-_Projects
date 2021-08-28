/*
 * Name: Tyler McDonald
 * Test 1
 * Purpose: Create a FIFO Queue using Linked Lists
 */
 #ifndef MAIN_H
 #define MAIN_H

 #include <iostream>     /* cout, endl */
 #include <stdlib.h>     /* srand, rand */
 #include <time.h>       /* time */

 #include "fifo.h"

 #define TEST_CASE_BASE 20
 #define TEST_CASE_OFFSET 5
 #define MAX_ID 1000
#define BUFFER_SIZE 16

 using std::cout;
 using std::endl;

 void make_test_cases(int*, char**, int);
void display_test_cases(int*, char**, int);

 #endif /* MAIN_H */
