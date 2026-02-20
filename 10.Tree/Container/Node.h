#pragma once

#include <vector>

// For convienience to delete a node.
template <typename T>
void SafeDelete(T*& t)
{
	if (t)
	{
		delete t;
		t = nullptr;
	}
}

// a Node class composits a tree.
template<typename T> 
class Node
{

public:

	Node(const T& data)
		:data(data)
	{
	}

	// Clean-up data.
	~Node()
	{
		data = T();
		parent = nullptr;
		childeren.clear();
	}

public:


	// Add Children Node with a parameter.
	// Wrapper Function: 다른 함수를 외부에서 감싸는 형태.
	void AddChild(const T& data)
	{
		// Call Function below.
		AddChild(new Node<T>(data));
	}

	// Add Children Node with a node.
	void AddChilde(Node<T>* newChild)
	{
		// Set current Node as a parent node.
		newChild->SetParent(this);

		// Add new child node into the children node list.
		children.emplace_back(newChild);
	}

	// Remove Node.
	void RemoveChild(Node<T>* child)
	{
		// Search the node
	}

	// Getter/Setter.
	inline T GetData() const { return data; }
	inline std::vector<Node<T>*>& GetChildren() const { return children; }
	inline Node<T>* GetParent() const { return parent; }
	inline void SetParent(Node<T>* newParent) { parent = newParent; }

private:

	// Recursively Delete Node.
	// When to use: Call itself, and its data range reduces.
	// Warning 01: It must have a exit condition.
	// Warning 02: It has a warning of stack overflow. (because it usese call stack.)
	// It is good for understanding a logic, 
	// but it's better to change the logic to for-loop or something else.
	void RemoveChildRecursive(Node<T>* child)
	{
		// Exit condition.
		if (!child)
		{
			return;
		}

		// Check the Node below.
		std::vector<Node<T>*>& children = child->GetChildren();

		// Number of cases.
		
		// case 01: no children.
		if (children.size() == 0)
		{
			// Search the target node at the chldren node list.
			auto& parentVector = child->GetParent()->GetChildren();
			auto childIt = std::find(parentVector.begin(),
				parentVector.end(),
				child
			);

			// if search succeed, delete from child node list                                                                                                                                                                                                                                                                                                                                                                     .
			if (childIt != parentVector.end())
			{
				parentVector.erase(childIt);
			}

			// Delte node.
			SafeDelte(child);
			return;
		}

		// case 02: it has child node.


		// Finish
	}

private:
	// a data to savve into a node.
	T data;

	// reference value of parent.
	Node<T>* parent = nullptr;

	// dynamic array of children nodes.
	std::vector<Node<T>*> children;

};