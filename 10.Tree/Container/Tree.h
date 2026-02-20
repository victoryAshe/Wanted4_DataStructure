#pragma once

#include <iostream>

template<typename T>
class Tree
{
public:
	Tree(const T& data)
	{
		// Create Root Node.
		root = new Node<T>(data);
	}

	~Tree()
	{
		// Call the method deleting all of the children node of root node.
		DestroyRecursive(root);
	}

public:
	// 여기에서 작성되는 method를 OPP이론에서 Message라고 지칭.
	// Message => public method.
	// OOP => Object들이 message를 통해 소통하는 구조.

	// Add child node to the found parent node using the parameter's value
	bool AddChild(const T& parentData, const T& childData)
	{
		// Search parent Node.
		// Simulate the search method and call.
		Node<T>* outParent = nullptr;
		bool result = FindRecursive(parentData, root, outParent);

		// if success to search the parent: Add the child node to the parent node.
		if (result)
		{
			outParent->AddChild(childData);
			return true;
		}

		// if failed to search the parent:
		return false;
	}

	// Search.
	bool Find(const T& data, Node<T>*& outNode)
	{
		return FindRecursive(data, root, outNode);                                                                                                                                                                                                                                                             
	}
	
	// Remove.
	bool Remove(const T& data)
	{
		return RemoveRecursive(data, root);
	}

	// PreOrder-Traversal
	// depth: using for visually identifying the rank of the tree.
	void PreorderTraversal(int de                                      pth = 0)
	{
		// TODO: Simulation Recursively rounding method and Call.
		PreorderTraversalRecursive(root, depth);
	}

private:
	// data: Searching data.
	// node: currently Searching node.
	// outNode: return Node when the search succeed.
	// return value: the succession of the search.
	bool FindRecursive(const T& data, Node<T>* node, Node<T>*& outNode)
	{
		// Exit condition.
		if (!node)
		{
			outNode = nullptr;
			return false;
		}

		// Success to search.
		// if the node's value is the searching value.
		if (node->GetData() == data)
		{
			outNode = node;
			return true;
		}

		// Go down to the child node and recursively Find again.
		std::vector<Node<T>*>& children = node->GetChildren();
		const int length = static_cast<int>(children.size());
		for (int ix = 0; ix < length; ++ix)
		{
			bool result = FindRecursive(data, children[ix], outNode);
			if (result)
			{
				return true;
			}
		}

		// Fails to search.
		outNode = nullptr;
		return false;
	}

	// Recursively Remove method.
	// data: The target node's value to delete.
	// node: currently searching node.
	// 핵심 로직은 RemoveImplementation이라고 해서 옛날에는 RemoveImpl.이런 식으로 줄였었음.
	// 요즘 trend는 아님.
	bool RemoveRecursive(const T& data, Node<T>* node)
	{
		// Searh the node to delete.
		Node<T>* outNode = nullptr;
		bool result = FindRecursive(data, node, outNode);

		// Succeed to search.
		if (result)
		{
			// 1. delete current node from the parent node's children list.
			Node<T>* parent = outNode->GetParent();
			if (parent)
			{ 
				// Find the node from the children list.
				auto it = std::find(
					parent->GetChildren().begin(),
					parent->GetChildren().end(),
					outNode
				);

				// erase the node from the children list.
				parent->GetChildren().erase(it);
			}
			// Yet, the node itself exists.

			// 2. if this node has children, delete children either.
			std::vector<Node<T>*>& children = outNode->GetChildren();
			while (children.size() > 0)
			{
				outNode->RemoveChild(children[0]);
			}

			// 3. delete this node and clean-up the memory.
			SafeDelete(outNode);

			return true;
		}
		
		// Failed to search.
		return false;
	}

	// Recursively travel in pre-order.
	void PreorderTraversalRecursive(Node<T>* node, int depth = 0)
	{
		// Exit condition
		if (!node)
		{
			return;
		}

		// print the depth to visualize the rank.
		for (int ix = 0; ix < depth; ++ix)
		{
			std::cout << "  ";
		}

		// pre-order traversal: visit parent first.
		std::cout << node->GetData() << "\n";

		// visit children nodes.
		std::vector<Node<T>*>& children = node->GetChildren();
		const int length = static_cast<int>(children.size());
		if (length == 0)
		{
			return;
		}

		for (int ix = 0; ix < length; ++ix)
		{
			Node<T>* child = children[ix];
			PreorderTraversalRecursive(child, depth + 1);
		}

	}

	// Destroy the Tree. => Delete all of the node.
	void DestroyRecursive(Node<T>* node)
	{' '
		// 1. First of all, delete the children nodes.
		std::vector<Node<T>*>& children = node->GetChildren();
		while (children.size() > 0)
		{
			DestroyRecursive(children[0]);
		}

		// 2. Clean-up parent list.
		Node<T>* parent = node->GetParent();
		if (parent)
		{
			auto it = std::find(
				parent->GetChildren().begin(),
				parent->GetChildren().end(),
				node
			);
		}

		if (it != parent->GetChildren().end())
		{
			parent->GetChildren().erase(it);
		}


		// 3. Delete the node and clean-up the memory.
		SafeDelete(node);
	}

private:
	// Root Node.
	Node<T>* root = nullptr;
};