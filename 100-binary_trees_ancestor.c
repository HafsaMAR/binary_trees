#include "binary_trees.h"

/**
 * binary_tree__node_height - function that measures the height of a BT
 * @tree: pointer to the root node of the tree
 * Return: height
 */
size_t binary_tree__node_height(const binary_tree_t *tree)
{
	binary_tree_t *iterator;
	size_t height = 0;

	if (!tree || !tree->parent)
		return (0);
	iterator = (binary_tree_t *)tree;
	while (iterator->parent)
	{
		iterator = iterator->parent;
		height++;
	}
	return (height);
}

/**
 * binary_trees_ancestor - function that finds the lowest common ancestor
 * @first: first node
 * @second: seconde node
 * Return: pointer to the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	int diff;
	binary_tree_t *lowest, *highest;

	if (!first || !second)
		return (NULL);

	diff = binary_tree__node_height(first) - binary_tree__node_height(second);

	if (diff > 0)
	{
		lowest = (binary_tree_t *)second;
		highest = (binary_tree_t *)first;
	}
	else
	{
		lowest = (binary_tree_t *)first;
		highest = (binary_tree_t *)second;
		diff = abs(diff);
	}
	while (diff > 0)
	{
		diff--;
		highest = highest->parent;
	}
	while (highest->parent && lowest->parent)
	{
		if (highest == lowest)
			return (highest);
		else if (highest->parent == lowest->parent)
		{
			return (highest->parent);
		}
		highest = highest->parent;
		lowest = lowest->parent;
	}
	return (NULL);
}
