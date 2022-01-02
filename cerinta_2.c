#include "utils.h"

/**
 * TODO: Implementati o functie de cautare a unui nod in
 * 	functie de valoarea din acesta
 * @note   
 * @param  root: Radacina arborelui
 * @param  data: Valoarea de cautat
 * @retval Nodul cautat, daca nu este gasit se returneaza NULL
 */
BST *findNode(BST *root, int data)
{
    if (root == NULL)
        return root;
    
    if (root->data == data)
        return root;
    
    if (root->data > data)
        return findNode(root->left, data);
    
    if (root->data < data)
        return findNode(root->right, data);
    
    return NULL;
}
/**
 * TODO: Implementati o functie ce returneaza nodul ce stocheaza
 * 	valoarea maxima din arborele/subarborele primit ca parametru
 * @note   
 * @param  root: - Radacina arborelui/subarborelui
 * @retval - Nodul cu valoarea maxima din arbore/subarbore
 */
BST *findMax(BST *root)
{
    BST *x = root;
    while (x->right != NULL)
        x = x->right;
    return x;
}

/**
 * TODO: Implementati o functie ce returneaza nodul ce stocheaza
 * 	valoarea minima din arborele/subarborele primit ca parametru
 * @note   
 * @param  root: - Radacina arborelui/subarborelui
 * @retval - Nodul cu valoarea minima din arbore/subarbore
 */
BST *findMin(BST *root)
{
    BST *x = root;
    while (x->left != NULL)
        x = x->left;
    return x;
}

/**
 * TODO: Implementati o functie ce returneaza succesorul in inordine al
 * 	nodului primit ca parametru
 * @note   
 * @param  root: Nodul al carui succesor trebuie gasit
 * @retval Succesorul nodului root
 */
BST *findSuccesor(BST *root)
{
    if (root->right != NULL)
        return findMin(root->right);

    BST *p = root->parent;
    
    while (p != NULL && root == p->right)
    {
        root = p;
        p = p->parent;
    }
    return p;
}

/**
 * TODO: Implementati o functie ce returneaza predecesorul in inordine al
 * 	nodului primit ca parametru
 * @note   
 * @param  root: Nodul al carui predecesor trebuie gasit
 * @retval Predecesorul nodului root
 */
BST *findPredecessor(BST *root)
{
    if (root->left != NULL)
        return findMax(root->left);

    BST *p = root->parent;
    while (p != NULL && root == p->left)
    {
        root = p;
        p = p->parent;
    }
    return p;
}
