#ifndef BTREE_H
#define BTREE_H
#include "Headers.h"
#include "Exception.h"
template <typename T>
class Node
{
private:
	T data_;
	Node* right_;
	Node* left_;
	Node* parent_;
	friend Iterator<T>;
	friend BTree<T>;
};

template <typename T>
class BTree
{
public:
	BTree()
	{
		root_ = nullptr;
		size_ = 0;
	}
	~BTree() {}

	//Adds a node to the tree in an orderly manner
	void Push(T data)
	{
		Node<T>* temp = root_;
		try
		{
			if (root_ == nullptr)
			{
				root_ = InsertNode(data, nullptr);
				size_++;
			}
			else
			{
				temp = root_;
				while (temp != nullptr)
				{
					if (data > temp->data_)
					{
						if (temp->right_ != nullptr)
						{
							temp = temp->right_;
							continue;
						}
						else
						{
							temp->right_ = InsertNode(data, temp);
							size_++;
							return;
						}
					}
					else if (data < temp->data_)
					{
						if (temp->left_ != nullptr)
						{
							temp = temp->left_;
							continue;
						}
						else
						{
							temp->left_ = InsertNode(data, temp);
							size_++;
							return;
						}
					}
					else
					{
						throw Exception("A node with this data already exists");
					}
				}
			}
		}
		catch (Exception error)
		{
			error.PrintError();
		}

	}

	//Inserts an arbitrary node through a pointer to the parent
	Node<T>* InsertNode(T data, Node<T>* parent)
	{
		Node<T>* temp = new Node<T>;
		temp->data_ = data;
		temp->left_ = nullptr;
		temp->right_ = nullptr;
		temp->parent_ = parent;
		return temp;
	}

	//Removes a specific node
	void DeleteNode(Node<T>* node)
	{
		if (node->left_ && node->right_)
		{
			Node<T>* locMax = RightMost(node->left_);
			node->data_ = locMax->data_;
			DeleteNode(locMax);
			return;
		}
		else if (node->left_)
		{
			if (node == node->parent_->left_)
			{
				node->parent_->left_ = node->left_;
				node->left_->parent_ = node->parent_;
			}
			else
			{
				node->parent_->right_ = node->left_;
				node->left_->parent_ = node->parent_;
			}
		}
		else if (node->right_)
		{
			if (node == node->parent_->right_)
			{
				node->parent_->right_ = node->right_;
				node->right_->parent_ = node->parent_;
			}
			else
			{
				node->parent_->left_ = node->right_;
				node->right_->parent_ = node->parent_;
			}
		}
		else
		{
			if (node == node->parent_->left_)
			{
				node->parent_->left_ = nullptr;
			}
			else
			{
				node->parent_->right_ = nullptr;
			}
		}
		delete node;
		size_--;
	}

	//Removes a specific node by stored data
	void DeleteNode(T data)
	{
		Node<T>* temp = FindNode(data);
		if (temp != nullptr)
		{
			DeleteNode(temp);
		}
	}

	//Find an arbitrary node by data
	Node<T>* FindNode(T data)
	{
		Node<T>* temp = root_;
		try
		{
			while (temp != nullptr)
			{
				if (temp->data_ > data)
				{
					temp = temp->left_;
					continue;
				}
				else if (temp->data_ < data)
				{
					temp = temp->right_;
					continue;
				}
				else
				{
					cout << "The desired value exists: ";
					return temp;
				}
			}
			throw Exception("The value you are looking for does not exist");
		}
		catch (Exception error)
		{
			error.PrintError();
			return nullptr;
		}
	}

	//Printing tree items in ascending order by id
	void Print()
	{
		Iterator<T> it = this->LeftMost();
		while (true)
		{
			if (it == this->RightMost())
			{
				std::cout << it.GetData();
				break;
			}
			std::cout << it.GetData();
			try
			{
				it.NextNode();
			}
			catch (...)
			{
				std::cout << "Exception happend" << std::endl;
				return;
			}
		}
	}

	//Returns an iterator to the leftmost link
	Iterator<T> LeftMost()
	{
		Node<T>* temp(root_);
		while (temp->left_ != nullptr)
		{
			temp = temp->left_;
		}
		return temp;
	}

	//Returns an iterator to the rightmost link
	Iterator<T> RightMost()
	{
		Node<T>* temp = root_;
		while (temp->right_ != nullptr)
		{
			temp = temp->right_;
		}
		return temp;
	}

	//Returns an node pointer to the rightmost link
	Node<T>* RightMost(Node<T>* root)
	{
		while (root->right_) {
			root = root->right_;
		}
		return root;
	}

	void WriteTreeIntoBinFile(File& file)
	{
		try {
			if (!file.IsOpen())
			{
				throw Exception("File is not open");
			}
			else
			{
				Iterator<T> it = this->LeftMost();
				while (true)
				{
					if (it == this->RightMost())
					{
						file.Insert(&(it.GetData()));
						break;
					}
					file.Insert(&(it.GetData()));
					try
					{
						it.NextNode();
					}
					catch (...)
					{
						std::cout << "Error happend" << std::endl;
						return;
					}
				}
			}
		}
		catch (Exception error)
		{
			error.PrintError();
			Terminate();
		}
	}
private:
	Node<T>* root_;
	int size_;
};

template <typename T>
class Iterator
{
public:
	Iterator()
	{
		node_ = nullptr;
	}
	Iterator(Node<T>* node)
	{
		this->node_ = node;
	}
	Iterator(BTree<T>* btree)
	{
		this->btree_ = btree;
	}
	~Iterator()
	{
		node_ = nullptr;
	}

	friend BTree<T>;

	bool operator == (Iterator it)
	{
		return (node_ == it.node_) ? true : false;
	}
	bool operator != (Iterator it)
	{
		return !(operator == it);
	}
	Iterator& operator=(const Iterator& it)
	{
		node_ = it.node_;
		return *this;
	}
	T& operator*()
	{
		if (node_ == nullptr)
		{
			throw Exception("Empty iterator");
		}
		return node_->data_;
	}
	T* operator->()
	{
		if (node == nullptr)
		{
			throw Exception("Empty iterator");
		}
		return &node_->data_;
	}
	Iterator& operator++()
	{
		if (node_ == nullptr)
		{
			throw Exception("Empty iterator");
		}
		this->NextNode();
		return *this;
	}
	Iterator& operator[](int i)
	{
		node_ = FindNode(T(i, "", 0, 0));
		if (node_)
		{
			return *this;
		}
	}

	//Returns the data that the node contains
	T GetData()
	{
		try
		{
			if (node_ == nullptr)
			{
				throw Exception("node is null pointer");
			}
			else
			{
				return node_->data_;
			}
		}
		catch (Exception error)
		{
			error.PrintError();
		}
	}

	//Changing data
	void ChangeData(const string& name, const int mass)
	{
		Shoes& temp = node_->data_;
		temp.set_name(name);
		temp.set_mass(mass);
	}

	//Prints the data of the current node
	void PrintData()
	{
		if (node_)
			cout << node_->data_;
	}

	void Print()
	{
		btree_->Print();
	}
	void Push(T data)
	{
		btree_->Push(data);
	}
	Node<T>* FindNode(T data)
	{
		node_ = btree_->FindNode(data);
		if (node_ != nullptr)
		{
			cout << node_->data_;
		}
		return node_;
	}
	void DeleteNode()
	{
		btree_->DeleteNode(node_);
	}

	//Returns the data that the current node contains 
	void NextNode()
	{
		if (node_->right_ != nullptr)
		{
			node_ = node_->right_;
			while (node_->left_ != nullptr)
			{
				node_ = node_->left_;
			}
		}
		else
		{
			if (node_->parent_ == nullptr)
			{
				return;
			}
			if ((node_->parent_->left_) && (node_->parent_->left_ == node_))
			{
				node_ = node_->parent_;
				return;
			}
			else
			{
				if ((node_->parent_->right_) && (node_->parent_->right_ == node_))
				{
					while (node_->data_ > node_->parent_->data_)
					{
						node_ = node_->parent_;
						if (node_->parent_ == nullptr)
						{
							return;
						}
					}
					node_ = node_->parent_;
					return;
				}
			}
		}
	}
private:
	Node<T>* node_;
	BTree<T>* btree_;
};
#endif