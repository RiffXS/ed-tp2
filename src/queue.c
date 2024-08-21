// Getting the definitions for the functions
#include "queue.h"

// Getting the definitions for the TADs Patient and Exam
#include "exam.h"
#include "patient.h"

// Getting the standard C libraries
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// PatientQueue functions

// Defining struct for the PatientQueue
struct patient_queue {
  PatientQueueNode *front; // 
  PatientQueueNode *rear;  // 
};

// Defining struct for the PatientQueueNode
struct patient_queue_node {
  Patient *info;           // A Patient value stored in the node.
  PatientQueueNode *next; // A pointer to the next node in the queue.
};

// Create a new PatientQueue and return a pointer to it
PatientQueue *pq_create() {
  // Allocating the memory for PatientQueue
  PatientQueue *pq = (PatientQueue *)malloc(sizeof(PatientQueue));

  // Defining the front and rear of PatientQueue as NULL
  pq->front = pq->rear = NULL;

  // Returning created PatientQueue
  return pq;
}

// Verifies if the PatientQueue is empty
int pq_is_empty(PatientQueue *pq) {
  return pq->front == NULL;
}

// Free the memory associated with the PatientQueue
void pq_destroy(PatientQueue *pq) {
  // Getting the start of the PatientQueue
  PatientQueueNode *p = pq->front;

  // Freeing the memory for the PatientQueueNode
  while (p != NULL) {
    PatientQueueNode *t = p->next;
    patient_destroy(p->info);
    free(p);
    p = t;
  }

  // Freeing the memory for PatientQueue
  free(pq);
}

// Enqueues a Patient to the end of the queue
void pq_enqueue(PatientQueue *pq, Patient *p) {
  // Creating a new queue node
  PatientQueueNode *node = (PatientQueueNode *)malloc(sizeof(PatientQueueNode));

  // Inserting the values into the node
  node->info = p;
  node->next = NULL;

  // Verifying if the Queue is empty to enqueue the Patient to the correct place
  if (pq_is_empty(pq))
    pq->front = node;
  else
    pq->rear->next = node;

  // Putting Patient to the end of the Queue
  pq->rear = node;
}

// Dequeues the Patient at the front and returns it
Patient *pq_dequeue(PatientQueue *pq) {
  assert(!pq_is_empty(pq));

  // Getting the values to return and to free
  Patient *p = pq->front->info;
  PatientQueueNode *node = pq->front; // Storing for removal

  // Verifies if the queue only has one element, if yes, front and rear are NULL, if not, front->next is the new front
  if (pq->front != pq->rear)
    pq->front = pq->front->next;
  else
    pq->front = pq->rear = NULL;

  // Frees the memory for the node
  free(node);

  // Returns the Patient
  return p;
}

void pq_print(PatientQueue *pq) {
  for (PatientQueueNode *p = pq->front; p != NULL; p = p->next) {
    printf("%d %s %d\n", get_patient_id(p->info), get_patient_name(p->info), get_patient_timestamp(p->info));
  }
}

// ExamPriorityQueue functions

// Defining struct for ExamPriorityQueue
struct exam_priority_queue {
  ExamPriorityQueueNode *front;
  ExamPriorityQueueNode *rear;
};

// Definig struct for ExamPriorityQueueNode
struct exam_priority_queue_node {
  Exam *info;
  ExamPriorityQueueNode *next;
};
