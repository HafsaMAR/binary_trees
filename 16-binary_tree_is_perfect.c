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

/**
 * binary_tree_is_perfect - function that checks
 * whether a binary tree is perfect
 * @tree: pointer to the root node of the BT
 * Return: 1 success 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left && tree->right &&
		binary_tree_height(tree->left) == binary_tree_height(tree->right))
	{
		return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	return (0);
}
