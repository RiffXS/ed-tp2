#ifndef QUEUE_H
#define QUEUE_H

// Getting Patient and Exam TADs
#include "exam.h"
#include "patient.h"


// PatientQueue functions

// Define a forward declaration of a 'patient_queue' and 'patient_queue_node' structures
typedef struct patient_queue PatientQueue;
typedef struct patient_queue_node PatientQueueNode;

// Function prototypes

// Create a new PatientQueue and return a pointer to it
PatientQueue *pq_create();

// Verifies if the PatientQueue is empty
int pq_is_empty(PatientQueue *pq);

// Free the memory associated with the PatientQueue
void pq_destroy(PatientQueue *pq);

// Enqueues a Patient to the end of the queue
void pq_enqueue(PatientQueue *pq, Patient *p);

// Dequeues the Patient at the front and returns it
Patient *pq_dequeue(PatientQueue *pq);

// Prints the PatientQueue
void pq_print(PatientQueue *pq);

// ExamPriorityQueue functions

// Define a forward declaration of a 'exam_priority_queue' and 'exam_priority_queue_node' structures
typedef struct exam_priority_queue ExamPriorityQueue;
typedef struct exam_priority_queue_node ExamPriorityQueueNode;

// Create a new ExamPriorityQueue and return a pointer to it
ExamPriorityQueue *epq_create();

// Free the memory associated with the ExamPriorityQueue
void epq_destroy(ExamPriorityQueue *epq);

// Enqueues an Exam to the end of the queue
void epq_enqueue(ExamPriorityQueue *epq, Exam *e);

// Dequeues the Exam at the front and returns it
Exam *epq_dequeue(ExamPriorityQueue *epq);

#endif