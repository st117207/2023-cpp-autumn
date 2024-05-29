#include<iostream>

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int data, Node* left = nullptr, Node* right = nullptr) :
		data(data), left(left), right(right) {}
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		if (node == nullptr)
		{
			stream << "EMPTY";
		}
		else
		{
			stream << node->data;
		}
		return stream;
	}
};

class BTree
{
public:
	BTree() : root(nullptr) {}
	BTree(const BTree& other) {
		root = copyTree(other.root);
	}
	BTree(BTree&& other) noexcept : root(nullptr) {
		root = other.root;
		other.root = nullptr;
	}
	~BTree()
	{
		dispose(root);
	}

	BTree& operator=(const BTree& other)
	{
		if (this != &other) { 
			dispose(root);
			root = copyTree(other.root);
		}
		return *this;
	}
	bool operator==(const BTree& other) 
	{
		return Equal(root, other.root);
	}

	void Add(int data)
	{
		add(root, data);
	}
	void Remove(int data)
	{
		Node* node = extractNode(searchNode(root, data));
		if (node != nullptr)
		{
			delete node;
		}
	}
	void RotateLeft(int data)
	{
		rotateLeft(searchNode(root, data));
	}
	friend std::ostream& operator<<(std::ostream& stream, BTree& tree)
	{
		stream << "__________Start of output___________" << std::endl;
		tree.printLineTree(stream, tree.root);
		stream << std::endl;
		stream << "_______________________________" << std::endl;
		tree.printVerticalTree(stream, tree.root);
		stream << "__________End of output___________" << std::endl;
		return stream;
	}
private:
	Node* root;
	void dispose(Node*& node)
	{
		if (node != nullptr) 
		{
			dispose(node->left);
			dispose(node->right);
			delete node;
		}
	}
	bool Equal(Node* node1, Node* node2)  
	{
		if (node1 == nullptr && node2 == nullptr)
		{
			return true;
		}
		if (node1 == nullptr || node2 == nullptr)
		{
			return false;
		}

		return (node1->data == node2->data) && Equal(node1->left, node2->left) && Equal(node1->right, node2->right);
	}
	Node* copyTree(Node* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		Node* temp = new Node(node->data);
		temp->left = copyTree(node->left);
		temp->right = copyTree(node->right);
		return temp;
	}
	void add(Node*& node, int data)
	{
		if (node == nullptr)
		{
			node = new Node(data);
		}
		else if (node->data > data)
		{
			add(node->left, data);
		}
		else if (node->data < data)
		{
			add(node->right, data);
		}
	}
	void printVerticalTree(std::ostream& stream, Node*& node, int depth = 0)
	{
		if (node == nullptr)
		{
			return;
		}
		printVerticalTree(stream, node->left, depth + 1);
		for (int i = 0; i < depth; ++i)
		{
			stream << "\t";
		}
		stream << node << std::endl;
		printVerticalTree(stream, node->right, depth + 1);
	}
	void printLineTree(std::ostream& stream, Node*& node)
	{
		if (node == nullptr)
		{
			return;
		}
		printLineTree(stream, node->left);
		stream << node << " ";
		printLineTree(stream, node->right);
	}
	void rotateLeft(Node*& node)
	{
		if (node == nullptr || node->right == nullptr)
		{
			return;
		}
		Node* temp = node->right;
		node->right = node->right->left;
		temp->left = node;
		node = temp;
	}
	Node*& searchNode(Node*& node, int data)
	{
		if (node == nullptr || node->data == data)
		{
			return node;
		}
		if (node->data > data)
		{
			return searchNode(node->left, data);
		}
		else
		{
			return searchNode(node->right, data);
		}
	}
	Node* extractNode(Node*& node)
	{
		if (node == nullptr)
		{
			return node;
		}
		if (node->left == nullptr && node->right == nullptr)
		{
			Node* temp = node;
			node = nullptr;
			return temp;
		}
		if (node->left == nullptr)
		{
			Node* temp = node;
			node = node->right;
			temp->right = temp->left = nullptr;
			return temp;
		}
		if (node->right == nullptr)
		{
			Node* temp = node;
			node = node->left;
			temp->right = temp->left = nullptr;
			return temp;
		}
		Node* leftMostRight = nullptr;
		if (node->right->left == nullptr)
		{
			leftMostRight = extractNode(node->right);
		}
		else
		{
			leftMostRight = node->right;
			while (leftMostRight->left->left != nullptr)
			{
				leftMostRight = leftMostRight->left;
			}
			leftMostRight = extractNode(leftMostRight->left);
		}
		Node* res = node;
		leftMostRight->left = node->left;
		leftMostRight->right = node->right;
		node = leftMostRight;
		return res;
	}
};

int main(int argc, char* argv[])
{
	return EXIT_SUCCESS;
}