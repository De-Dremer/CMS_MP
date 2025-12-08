#include <stdio.h>
#include <stdlib.h>
#include "model.h"

BST_NODE *getnode()
{
    BST_NODE *temp = (BST_NODE *)malloc(sizeof(BST_NODE));
    if (!temp)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    temp->left = temp->right = NULL;
    temp->citizen_ptr = NULL;
    temp->citizen_id = 0;

    return temp;
}

BST_NODE *bst_insert(BST_NODE *root, Citizen *cit)
{
    if (cit == NULL)
        return root;

    BST_NODE *new = getnode();
    if (!new) return root;

    new->citizen_id = cit->citizen_id;
    new->citizen_ptr = cit;

    if (root == NULL)
        return new;

    BST_NODE *cur = root;
    BST_NODE *pre = NULL;

    while (cur != NULL)
    {
        pre = cur;

        if (cit->citizen_id < cur->citizen_id)
            cur = cur->left;

        else if (cit->citizen_id > cur->citizen_id)
            cur = cur->right;

        else
        {
            printf("Citizen ID %d already exists in BST. Duplicate ignored.\n",
                   cit->citizen_id);
            free(new);
            return root;
        }
    }

    if (cit->citizen_id < pre->citizen_id)
        pre->left = new;
    else
        pre->right = new;

    return root;
}

BST_NODE *bst_search(BST_NODE *root, int id)
{
    if (root == NULL)
        return NULL;

    if (id == root->citizen_id)
        return root;

    if (id < root->citizen_id)
        return bst_search(root->left, id);

    return bst_search(root->right, id);
}
