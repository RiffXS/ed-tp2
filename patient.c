#include "patient.h"

#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

// Structure of 'patient'
struct patient {
    int id;
    char* name;
    struct tm* birthdate;
};

// Create a new patient and return a pointer to it
Patient *create_patient(int id, const char *name, struct tm *birthdate) {
    Patient *new_patient = (Patient *)malloc(sizeof(Patient));

    if (new_patient == NULL) {
        printf("Erro ao alocar memória para o paciente.\n");
        exit(1);
    }

    new_patient->id = id;
    new_patient->name = strdup(name);
    new_patient->birthdate = birthdate;

    return new_patient;
}

// Free the memory associated with patient
void destroy_patient(Patient* patient) {
    if (patient != NULL) {
        free(patient->name);
        free(patient);
    }
}

// Get the patient ID
int get_patient_id(Patient* patient) {
    return patient->id;
}

// Get the patient Name
const char *get_patient_name(Patient* patient) {
    return patient->name;
}

// Get the patient Birthdate
struct tm *get_patient_birthdate(Patient* patient) {
    return patient->birthdate;
}

// DAQUI PRA BAIXO É A IMPLEMENTAÇÃO DA FILA

// Define the structure for the queue.
struct queue
{
   QueueNode *front; // Pointer to the front of the queue.
   QueueNode *rear;  // Pointer to the rear of the queue.
};

// Define a structure for a node in the linked list.
struct queue_node
{
   Patient *patient; // Pointer to the patient data.
   QueueNode *next; // A pointer to the next node in the linked list.
};

// Function to create a new empty queue.
Queue *q_create()
{
   Queue *q = (Queue *)malloc(sizeof(Queue)); // Allocate memory for the queue structure.
   q->front = q->rear = NULL;                 // Initialize the front and rear pointers to NULL, indicating an empty queue.
   return q;
}

// Function to check whether the queue is empty.
int q_is_empty(Queue *q)
{
   return q->front == NULL;
}

// Function to enqueue a patient into the queue.
void q_enqueue(Queue *q, Patient *patient){
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->patient = patient;
    node->next = NULL;
    if (q_is_empty(q))
          q->front = node;
       else
          q->rear->next = node;

       q->rear = node;
}

Patient *q_dequeue(Queue *q) {
    assert(!q_is_empty(q)); // Verifica se a fila não está vazia.

    Patient *patient = q->front->patient; // Obtém o ponteiro para o paciente armazenado no nó da frente.
    QueueNode *p = q->front; // Armazena o nó da frente para removê-lo depois.

    if (q->front != q->rear)
        q->front = q->front->next; // Move o ponteiro 'front' para o próximo nó da fila.
    else
        q->front = q->rear = NULL; // Se havia apenas um nó, esvazia a fila.

    free(p); // Libera a memória do nó removido.
    return patient; // Retorna o ponteiro para o paciente.
}

// Function to free the memory used by the queue.
void q_free(Queue *q)
{
   QueueNode *p = q->front;
   while (p != NULL)
   {
      QueueNode *t = p->next; // Store a reference to the next node.
      free(p);                // Free the memory allocated for the current node.
      p = t;                  // Move to the next node.
   }
   free(q); // Free the memory allocated for the queue structure itself.
}

void q_print(Queue *q)
{
    for (QueueNode *p = q->front; p != NULL; p = p->next) {
        printf("ID: %d, Nome: %s",
               p->patient->id,
               p->patient->name);
    }
   printf("\n");
}

void transfer_patient_to_exam(Queue *patient_queue, Queue *exam_queue) {
    // Remove o primeiro paciente da fila de pacientes
    Patient *patient = q_dequeue(patient_queue);

    if (patient != NULL) {
        // Adiciona o paciente à fila de exames
        q_enqueue(exam_queue, patient);
        printf("Paciente %s (ID: %d) transferido para a fila de exames.\n", patient->name, patient->id);
    } else {
        printf("Nenhum paciente na fila para transferir.\n");
    }
}

void random_symptom (Queue *exam_queue) {

    char sympthom[20];
    int gravidade;
    
    // Inicializa a semente com o valor do relógio atual
    srand(time(NULL));

    // Gera e imprime um número aleatório entre 0 e 1
    double random_number = (double)rand() / RAND_MAX;
    printf("%.6f\n", random_number);

    if (random_number <= 0.3)
        gravidade = 1;
        snprintf(sympthom, sizeof(sympthom), "Saúde Normal");
    if (random_number <= 0.5)
        gravidade = 2;
        snprintf(sympthom, sizeof(sympthom), "Bronquite");
    if (random_number <= 0.6)
        gravidade = 3;
        snprintf(sympthom, sizeof(sympthom), "Pneumonia");
    if (random_number <= 0.7)
        gravidade = 4;
        snprintf(sympthom, sizeof(sympthom), "COVID");
    if (random_number <= 0.75)
        gravidade = 4;
        snprintf(sympthom, sizeof(sympthom), "Embolia pulmonar");
    if (random_number <= 0.8)
        gravidade = 4;
        snprintf(sympthom, sizeof(sympthom), "Derrame pleural");
    if (random_number <= 0.85)
        gravidade = 5;
        snprintf(sympthom, sizeof(sympthom), "Fibrose pulmonar");
    if (random_number <= 0.9)
        gravidade = 5;
        snprintf(sympthom, sizeof(sympthom), "Tuberculose");
    if (random_number <= 1)
        gravidade = 6;
        snprintf(sympthom, sizeof(sympthom), "Câncer de pulmão");
}