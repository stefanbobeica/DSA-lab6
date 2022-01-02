#include "utils.h"

/**
 * TODO: Implementati o functie ce creaza un arbore balansat din datele
 * 	din fisierul f. Arborele nu trebuie sa respecte alta proprietate decat
 *  cea mentionala anterior 
 * @note   
 * @param  N: Numarul de noduri ale arborelui
 * @param  *f: Fisierul din care sunt citite datele de intrare 
 * @retval	Nodul radacina al arborelui creat 
 */
BST *createBalanced(int N, FILE *f)
{
    int val;
    if (N > 0)
    {
        BST *root = (BST *)malloc(sizeof(BST));
        fscanf(f, "%d", &val);
        (root->data) = val;
        root->left = createBalanced(N / 2, f);
        root->right = createBalanced(N - 1 - N / 2, f);
        return root;
    }
    else
        return NULL;
}

/**
 * TODO:   Implementati o functie ce testeaza daca un arbore binar este
 * 	un arbore binar de cautare.
 * @note   
 * @param  root: Radacina arborelui
 * @param  max_value: Valoarea maxima intalnita pana la nodul curent
 * @param  min_value: Valoarea minima intalnita pana la nodul curent
 * @retval - true daca arborele este un BST, false in caz contrar
 */
bool checkBST(BST *root, int max_value, int min_value)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data < min_value || root->data > max_value)
    {
        return false;
    }

    return checkBST(root->left, root->data, min_value) &&
           checkBST(root->right, max_value, root->data);
}

/**
 * TODO:  Implementati o functie ce aloca memorie pentru un nod 
 * 	si salveaza datele in acesta
 * @note   
 * @param  data: Datele ce trebuie stocate in nod
 * @retval Nodul creat
 */

BST *createBSTNode(int data)
{
    BST *aux;
    aux = (BST *)malloc(sizeof(BST));
    aux->data = data;
    aux->left = NULL;
    aux->right = NULL;
    aux->parent = NULL;
    return aux;
}
/**
 * TODO: Implementati o functie ce insereaza un nod nou intr-un BST cu
 * 	pastrarea proprietatiilor acestui tip de arbore binar
 * @note   
 * @param  root: Nodul radacina
 * @param  data: Valoarea ce trebuie inserata in arbore
 * @retval Radacina arborelui modificat anterior
 */
BST *insertInBST(BST *root, int data)
{
    BST *p, *q;
    if (root == NULL)
        return createBSTNode(data);

    if (root->data > data)
    {
        p = insertInBST(root->left, data);
        root->left = p;
        p->parent = root;
    }
    else if (root->data < data)
    {
        q = insertInBST(root->right, data);
        root->right = q;
        q->parent = root;
    }

    return root;
}