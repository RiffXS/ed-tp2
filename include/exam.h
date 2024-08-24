#ifndef EXAM_H
#define EXAM_H

// Getting the Condition TAD
#include "condition.h"

// Define a forward declaration of a 'exam' structure
typedef struct exam Exam;

// Function prototypes

// Create a new Exam and return a pointer to it
Exam *exam_create(int id, int patient_id, int xr_id, Condition *condition_IA, int timestamp);

// Inserts Exam in a file
void exam_file_insert(Exam *e);

// Free the memory associated with the exam
void exam_destroy(Exam *exam);

// Get the ID of the exam
int get_exam_id(Exam *exam);

// Get the ID of the pacient associated with the exam
int get_exam_patient_id(Exam *exam);

// Get the X-ray machine ID for the exam
int get_exam_xr_id(Exam *exam);

// Get the condition diagnosed
Condition *get_exam_condition(Exam *exam);

// Get the name of the condition diagnosed
char *get_exam_condition_name(Exam *exam);

// Get the gravity of the condition diagnosed
int get_exam_condition_gravity(Exam *exam);

// Get the time of realization of the exam
int get_exam_timestamp(Exam *exam);

// End of conditional compilation directives
#endif