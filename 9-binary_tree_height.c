#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a BT
 * @tree: pointer to the root node of the tree
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	left_height++;
	right_height = binary_tree_height(tree->right);
	right_height++;
	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}
