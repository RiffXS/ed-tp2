#ifndef REPORT_H
#define REPORT_H

// Getting the Exam TAD
#include "exam.h"

// Define a forward declaration of a 'report' structure
typedef struct report Report;

// Function prototypes

// Creates a new Report and return a pointer to it
Report *report_create(int id, Exam *exam, int timestamp, int random);

// Inserts Report in a file
void report_file_insert(Report *r);

// Get the id of the report
int get_report_id(Report *report);

// Get the exam_id of the report
int get_report_exam_id(Report *report);

// Get the name of the condition of the report
char *get_report_condition_name(Report *report);

// Get the gravity of the condition of the report
int get_report_condition_gravity(Report *report);

// Get the timestamp of the report
int get_report_timestamp(Report *report);

#endif