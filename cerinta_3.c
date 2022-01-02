#include "utils.h"

/**
 * TODO: Returnati prin intermediul parametrului arr un vector ce contine toate
 * 	nodurile din arborele binar de cautare cu valori aflate in intervalul [min_value, max_value]  
 * @note   
 * @param  root: Radacina arborelui/subarborelui 
 * @param  arr: Vectorul cu valorile cerute
 * @param  *size: Pozitia pe care inseram la etapa curenta
 * @param  max_value: Pragul superior
 * @param  min_value: Pragul inferior
 * @retval None
 */
void bstToArray(BST *root, BST **arr, int *size, int max_value, int min_value)
{
    if (root == NULL)
        return;
    
    bstToArray(root->left, arr, size, max_value, min_value);
    
    if(root->data>max_value) return;
    
    if (min_value <= root->data && max_value >= root->data)
        
        arr[(*size)++] = root;
    
    bstToArray(root->right, arr, size, max_value, min_value);
     
}

/**
 * TODO: Implementati o functie ce returneaza numarul de noduri ce stocheaza
 * 	valori din intervalul [min_value, max_value]
 * @note   
 * @param  root: Radacina arborelui/subarborelui 
 * @param  max_value: Pragul superior
 * @param  min_value: Pragul inferior
 * @retval Numarul de noduri cu valori in [min_value, max_value] 
 *  din arbore/subarbore
 */
int numberOfNodesInBetween(BST *root, int max_value, int min_value)
{
    if (!root)
        return 0;
    if (root->data == max_value && root->data == min_value)
        return 1;
    if (root->data <= max_value && root->data >= min_value)
        return 1 + numberOfNodesInBetween(root->left, max_value, min_value) +
               numberOfNodesInBetween(root->right, max_value, min_value);

    else if (root->data < min_value)
        return numberOfNodesInBetween(root->right, max_value, min_value);

    else
        return numberOfNodesInBetween(root->right, max_value, min_value);
}
