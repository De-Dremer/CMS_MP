#include<stdlib.h>
#include<stdio.h>
#include<model.h>

BST_NODE* getnode()
{
    BST_NODE *temp=(BST_NODE*)malloc(sizeof(BST_NODE));
    if(temp==NULL){printf("No memory\n");
    return;}
    return temp;
}

BST_NODE* bst_insert(BST_NODE *root,int cit_id)
{
    BST_NODE *pre=NULL;
    BST_NODE *cur=NULL;
    BST_NODE *new=getnode();
    new->citizen_id=cit_id;
    new->left=new->right=NULL;
    if(root==NULL)return new;

    cur=root;
    while(cur!=NULL)
    {
        pre=cur;
        if(new->citizen_id < cur->citizen_id)
        {
            cur=cur->left;
        }
        else if(new->citizen_id > cur->citizen_id)
        {
            cur=cur->right;
        }
    }
    if(new->citizen_id< pre->citizen_id){
        pre->left = new;
    }
    else{
        pre->right=new;

    }
    return root;

}

BST_NODE* bst_search(BST_NODE *root,int id)
{
    if(root== NULL)return NULL;
    if (id==root->citizen_id)return root;
    if(id<root->citizen_id)
        return bst_search(root->left,id);
    else{
        return bst_search(root->right,id);
    }
}