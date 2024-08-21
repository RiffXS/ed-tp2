#ifndef EXAM_H
#define EXAM_H

// Define a forward declaration of a 'exam' structure
typedef struct exam Exam;

// Function prototypes

// Create a new Exam and return a pointer to it
Exam *exam_create(int id, int patient_id, int rx_id, int timestamp);

// Free the memory associated with the exam
void exam_destroy(Exam *exam);

// Get the ID of the exam
int get_exam_id(Exam *exam);

// Get the ID of the pacient associated with the exam
int get_exam_patient_id(Exam *exam);

// Get the X-ray machine ID for the exam
int get_exam_rx_id(Exam *exam);

// Get the time of realization of the exam
int get_exam_timestamp(Exam *exam);

// End of conditional compilation directives
#endif