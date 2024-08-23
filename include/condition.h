#ifndef CONDITION_H
#define CONDITION_H

// Define a forward declaration of a 'condition'
typedef struct condition Condition;

// Function to create a new Condition and return a pointer to it
Condition *condition_create();

// Function to define a condition based on a random number
void condition_define(Condition *c, int random);

// Function to return the name of the condition
char *get_condition_name(Condition *condition);

// Function to return the gravity of the condition
int get_condition_gravity(Condition *condition);

#endif