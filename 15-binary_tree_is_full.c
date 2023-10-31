#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks whether a binary tree is full
 * @tree: pointer to the root node of the tree
 * Return: 1 (full binary tree) 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	binary_tree_is_full(tree->left);
	binary_tree_is_full(tree->right);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	return (0);
}
