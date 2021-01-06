#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

/* utility that allocates a new Node 
   with the given key  */
struct node* newnode(int key)
{
  struct node* n = malloc(sizeof(struct node));
  
    n->key = key;
    n->left = n->right = NULL;
    return (n);
}


/* Function to convert binary tree into
// linked list by altering the right node
// and making left node point to NULL
*/
void flatten(struct node* root)
{
  /*    // base condition- return if root is NULL
    // or if it is a leaf node
    */
    if (root == NULL || root->left == NULL &&
                        root->right == NULL) {
        return;
    }

    printf("beg key %d\n", root->key);

    /*    // if root->left exists then we have 
    // to make it root->right
    */
    if (root->left != NULL) {
 
        printf("left X %d\n", root->left->key);
        // move left recursively
        flatten(root->left);
        printf("key 2 root %d\n", root->key);
        // store the node root->right
	struct node* tmpright = root->right;
	printf("tmpright %d\n", tmpright->key);
        root->right = root->left;
        root->left = NULL;

/*   // find the position to insert
    // the stored value   
*/
        struct node* t = root->right;
        while (t->right != NULL) {
            t = t->right;
        }
 
	/*        // insert the stored value*/
	printf("t %d\n", t->key);
        t->right = tmpright;
    }
 
/*    // now call the same function
    // for root->right
    */
    printf("flatten on right key %d\n", root->right->key);    
    flatten(root->right);
}


/*
          1
        /   \
       2     5
      / \     \
     3   4     6
*/





int
main()
{
    struct node* root = newnode(1);

    root->left = newnode(2);
    root->right = newnode(5);
    root->left->left = newnode(3);
    root->left->right = newnode(4);
    root->right->right = newnode(6);
    flatten(root);

    /*
    cout << "The Inorder traversal after "
            "flattening binary tree ";
    inorder(root);
    */
    return 0;
}
