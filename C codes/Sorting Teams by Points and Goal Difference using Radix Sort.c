#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POINTS 100 // maximum number of points a team can have
#define MAX_GOAL_DIFFERENCE 50 // maximum goal difference a team can have

// Structure representing a team
typedef struct team {
  char name[50];
  int points;
  int goal_difference;
  struct team *next;
} team_t;

// Function prototypes
team_t *radix_sort(team_t *head);
team_t *counting_sort(team_t *head, int exp);

int main(void) {
  // Create a linked list of teams
  team_t *head = NULL;
  team_t *current = NULL;

  // Add some teams to the linked list
  current = head = malloc(sizeof(team_t));
  strcpy(current->name, "Team A");
  current->points = 50;
  current->goal_difference = 20;
  current->next = malloc(sizeof(team_t));
  current = current->next;

  strcpy(current->name, "Team B");
  current->points = 60;
  current->goal_difference = -10;
  current->next = malloc(sizeof(team_t));
  current = current->next;

  strcpy(current->name, "Team C");
  current->points = 40;
  current->goal_difference = 15;
  current->next = malloc(sizeof(team_t));
  current = current->next;

  strcpy(current->name, "Team D");
  current->points = 30;
  current->goal_difference = -5;
  current->next = NULL;

  // Sort the linked list of teams using radix sort
  head = radix_sort(head);

  // Print the sorted list of teams
  current = head;
  while (current != NULL) {
    printf("%s %d %d\n", current->name, current->points, current->goal_difference);
    current = current->next;
  }

  return 0;
}

// Radix sort function for linked lists
team_t *radix_sort(team_t *head) {
  // Create a temporary linked list
  team_t *temp_head = NULL;

  // Sort the linked list by points
  temp_head = counting_sort(head, 1);

  // Sort the linked list by goal difference
  temp_head = counting_sort(temp_head, 2);

  return temp_head;
}

// Counting sort function for linked lists
team_t *counting_sort(team_t *head, int exp) {
  // Create a temporary linked list and an array to count the number of occurrences of each key
  team_t *temp_head = NULL;
  team_t *current = NULL;
  int count[MAX_POINTS + MAX_GOAL_DIFFERENCE + 1] = {0};

  // Count the number of occurrences
current = head;
while (current != NULL) {
int key;
if (exp == 1) {
key = current->points;
} else {
key = MAX_POINTS + current->goal_difference;
}
count[key]++;
current = current->next;
}

// Calculate the starting indices for each key
for (int i = 1; i <= MAX_POINTS + MAX_GOAL_DIFFERENCE; i++) {
count[i] += count[i - 1];
}

// Build the sorted linked list
current = head;
while (current != NULL) {
int key;
if (exp == 1) {
key = current->points;
} else {
key = MAX_POINTS + current->goal_difference;
}
team_t *node = malloc(sizeof(team_t));
strcpy(node->name, current->name);
node->points = current->points;
node->goal_difference = current->goal_difference;
node->next = temp_head;
temp_head = node;
current = current->next;
}

// Return the sorted linked list
return temp_head;
}
