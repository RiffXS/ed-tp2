// Getting the definition for the funcitons
#include "condition.h"

// Necessary libraries
#include <stdlib.h>

// Structure of Condition
struct condition {
  char *name;
  int gravity;
};

// Function to create a new Condition and return a pointer to it
Condition *condition_create() {
  Condition *c = (Condition *)malloc(sizeof(Condition));

  c->name = "";
  c->gravity = 0;

  return c;
}

// Function to define a condition based on a random number
void condition_define(Condition *c, int random) {
  if (random <= 300) {
    c->name = "Saude Normal";
    c->gravity = 1;

  } else if (random > 300 && random <= 500) {
    c->name = "Bronquite";
    c->gravity = 2;

  } else if (random > 500 && random <= 600) {
    c->name = "Pneumonia";
    c->gravity = 3;

  } else if (random > 600 && random <= 700) {
    c->name = "COVID";
    c->gravity = 4;

  } else if (random > 700 && random <= 750) {
    c->name = "Embolia pulmonar";
    c->gravity = 4;

  } else if (random > 750 && random <= 800) {
    c->name = "Derrame pleural";
    c->gravity = 4;

  } else if (random > 800 && random <= 850) {
    c->name = "Fibrose pulmonar";
    c->gravity = 5;

  } else if (random > 850 && random <= 900) {
    c->name = "Tuberculose";
    c->gravity = 5;

  } else if (random > 900 && random <= 1000) {
    c->name = "Cancer de pulmao";
    c->gravity = 6;

  }
}

// Function to return the name of the condition
char *get_condition_name(Condition *condition) {
  return condition->name;
}

// Function to return the gravity of the condition
int get_condition_gravity(Condition *condition) {
  return condition->gravity;
}
