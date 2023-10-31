#include "binary_trees.h"

/**
 * binary_tree_depth - function that measures the height of a BT
 * @tree: pointer to the root node of the tree
 * Return: height
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *itereator;
	size_t depth = 0;

	if (!tree)
		return (0);
	itereator = tree;
	while (itereator->parent)
	{
		depth++;
		itereator = itereator->parent;
	}
	return (depth);
}