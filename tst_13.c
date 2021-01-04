#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  struct node *left;
  struct node *right;
  int value;
};

struct node *new_node(int val, struct node *left, struct node *right)
{
  struct node *newnode;

  newnode = malloc(sizeof(struct node));
  newnode->left = left;
  newnode->right = right;
  newnode->value = val;
  return newnode;
}

void
print_value(struct node *root, int x[], int *level)
{
  if (root == NULL)
    return;
  print_value(root->left, x, level);
  x[*level] = root->value;
  *level += 1;
  print_value(root->right, x, level);
}

int
main(int argc, char **argv)
{
  struct node *root, *left, *right;
  struct node *level_left, *level_right;
  int y[6], levels;

  level_left = new_node(1, NULL, NULL);
  level_right = new_node(2, NULL, NULL);  
  left = new_node(3, level_left, NULL);
  left->right = level_right;
  root = new_node(5, left, level_right);
  print_value(root, y, &levels);
  printf("levels = %d\n", levels);
  for (int i = 0; i<5; i++)
    printf("%d ", y[i]);
  return 0;
}  
