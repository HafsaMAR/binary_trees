#include "binary_trees.h"

/**
 * binary_tree_leaves - function that measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: size success or 0 otherwise
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf;

	if (!tree)
		return (0);

	leaf = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
	if (tree->left == NULL && tree->right == NULL)
	{
		leaf++;
	}

	return (leaf);
}
