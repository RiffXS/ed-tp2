#ifndef PATIENT_H
#define PATIENT_H

// Getting 'tm' structure
#include <time.h>

// Define a forward declaration of a 'patient' structure
typedef struct patient Patient;

// Function prototypes

// Create a new Patient and return a pointer to it
Patient *create_patient(int id, const char *name, struct tm *birthdate);

// Free the memory associated with the patient
void destroy_patient(Patient* patient);

// Get the ID of the patient
int get_patient_id(Patient* patient);

// Get the Name of the patient
const char *get_patient_name(Patient* patient);

// Get the birthdate of the patient
struct tm *get_patient_birthdate(Patient* patient);

// Define the Queue and QueueNode data structures
typedef struct queue Queue;          // Represents a queue
typedef struct queue_node QueueNode; // Represents a node in the queue
// Operations on the linked list

// Creates a new empty queue and returns a pointer to it
Queue *q_create();

// Checks if the specified queue q is empty and returns 1 if true, 0 otherwise
int q_is_empty(Queue *q);

// Enqueues a float value x into the specified queue q
void q_enqueue(Queue *q, Patient *patient);

// Dequeues and returns a float value from the specified queue q
Patient *q_dequeue(Queue *q);

// Free the memory associated with the specified queue q
void q_free(Queue *q);

// Prints the elements of the specified queue q
void q_print(Queue *q);

// Transfer a patient from the patient queue to the exam queue
void transfer_patient_to_exam(Queue *patient_queue, Queue *exam_queue);

// End of conditional compilation directives
#endif


