// Program to delete node in an AVL binary tree


#include <iostream>
using namespace std;

struct Node
{
	int data, height;
	Node *left, *right;
};

Node* newNode(int data)	// Allocation of new Node
{
	Node* node = new Node();
	node->data = data;
	node->height = 1;	// Initial Height is 1. Since it isn't attached to any child or parent
	node->left = NULL;	// No Left Child Initially
	node->right = NULL;	// No Right Child Initially
	return(node);
}

int height(Node *temp)	// Checks for Tree Height
{
	if (temp == NULL)
		return 0;
	return temp->height;
}

int max(int a, int b)	// Returns the Maximum Number
{
	return (a > b) ? a : b;
}

int getBalance(Node *temp)	// Calculates the Balance Factor for a Specific Node
{
	if (temp == NULL)
		return 0;
	return height(temp->left) - height(temp->right);
}

Node * minValueNode(Node* node)		// Returns the Node with Smallest Value
{
	Node* temp = node;
	while (temp->left != NULL)	// Moving to the LeftMost Child Since that will be Smallest
		temp = temp->left;
	return temp;
}

void preOrder(Node *root)	// Prints the Pre-Order Traversal of the Tree (Root, Left and Right)
{
	if (root != NULL)
	{
		cout << root->data << " ";	// Printing Root
		preOrder(root->left);		// Printing Left Child	(Recursion in Left Branch)
		preOrder(root->right);		// Printing Right Child (Recursion in Right Branch)
	}
}

void inOrder(Node *root)	// Prints the In-Order Traversal of the Tree (Left, Root and Right)
{
	if (root != NULL)
	{
		inOrder(root->left);		// Printing Left Child	(Recursion in Left Branch)
		cout << root->data << " ";	// Printing Root
		inOrder(root->right);		// Printing Right Child (Recursion in Right Branch)
	}
}

void postOrder(Node *root)	// Prints the Post-Order Traversal of the Tree (Left, Right and Root)
{
	if (root != NULL)
	{
		postOrder(root->left);		// Printing Left Child	(Recursion in Left Branch)
		postOrder(root->right);		// Printing Right Child (Recursion in Right Branch)
		cout << root->data << " ";	// Printing Root
	}
}

/* --------------------------------- ROTATION DIAGRAM ---------------------------------

		z                               y
	   / \       Right Rotation		   / \
	  y   b      – - – - – - – >	  x   z
	 / \         < - - - - - - -		 / \
	x   a        Left Rotation          a   b

*/

Node *rotateRight(Node *z)	// Right Rotation Function
{
	Node *y = z->left;	// 'z' is the Root and 'y' is Left Child of 'z'
	Node *a = y->right;	// 'a' is the Right Child of 'y'

	y->right = z;	// Rotate Right at 'z' Node
	z->left = a;	// Replacing Position of 'a'

	z->height = max( height(z->left), height(z->right) ) + 1;	// Updating Height of 'z' (Old Root)
	y->height = max( height(y->left), height(y->right) ) + 1;	// Updating Height of 'y' (New Root)

	return y;	// Returns the New Root Node
}

Node *rotateLeft(Node *y)	// Left Rotation Function
{
	Node *z = y->right;	// 'y' is the Root and 'z' is Right Child of 'y'
	Node *a = z->left;	// 'a' is the Left Child of 'z'

	z->left = y;	// Rotate Left at 'y' Node
	y->right = a;	// Replacing Position of 'a'

	y->height = max( height(y->left), height(y->right) ) + 1;	// Updating Height of 'y' (Old Root)
	z->height = max( height(z->left), height(z->right) ) + 1;	// Updating Height of 'z' (New Root)

	return z;	// Returns the New Root Node
}


Node* insert(Node* node, int data)	// Inserts a Node according to Binary Search Tree Rules
{
	// --------------------------------- INSERTION INTO TREE ---------------------------------

	if (node == NULL)			// Empty Tree Initially
		return(newNode(data));

	if (data < node->data)		// Coming Data Less than Root Node
		node->left = insert(node->left, data);		// Recursion for Deep into the Left Branch

	else if (data > node->data)	// Coming Data Less than Root Node
		node->right = insert(node->right, data);	// Recursion for Deep into the Right Branch 

	else						// Equal Data not allowed
		return node;

	node->height = 1 + max( height(node->left), height(node->right) ); // Height of this Parent (Parent for new Node) is Increased by 1

	// --------------------------------- BALANCE SETTLEMENT ---------------------------------

	int balance = getBalance(node);	// Check Balance after Insertion

	if (balance != 0)
	{
		if (balance > 1 && data < node->left->data)			// Left Left (Case-I)
			return rotateRight(node);						// Single Right Rotation

		else if (balance < -1 && data > node->right->data)	// Right Right (Case-IV)
			return rotateLeft(node);						// Single Left Rotation

		else if (balance > 1 && data > node->left->data)	// Right Left (Case-II: An insertion into left subtree of the right child )
		{													// 1st Left Rotation and then Right Rotation
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}

		else if (balance < -1 && data < node->right->data)	// Left Right (Case-III: An insertion into right subtree of the left child )
		{													// 1st Right Rotation and then Left Rotation
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}
	}
	
	return node;
}

Node* deleteNode(Node* root, int data)		// Deletion of a Node with Specific Data
{
	// --------------------------------- DELETION FROM TREE ---------------------------------

	if (root == NULL)			// Empty Tree
		return root;

	if (data < root->data)		// Data to be Deleted is Less than Root Node
		root->left = deleteNode(root->left, data);

	else if (data > root->data)	// Data to be Deleted is Greater than Root Node
		root->right = deleteNode(root->right, data);

	else						// Data to be Deleted is Same as of Root Node
	{
		if ((root->left == NULL) ||	(root->right == NULL))	// Node with Single or No Child
		{
			Node *temp = root->left ? root->left : root->right;	// If there's Left Child, Assign Left Child to temp, else Right Child

			if (temp == NULL)	// No Child
			{
				temp = root;
				root = NULL;
			}
			else	// One Child
				*root = *temp;	// Make Child Node, Root Node
				
			free(temp);
		}

		else	// Node with Both Children
		{
			Node* temp = minValueNode(root->right);				// Getting the Inorder Successor (Smallest in Right Subtree)
			root->data = temp->data;							// Copy the Inorder Successor's Data to this Node
			root->right = deleteNode(root->right, temp->data);	// Delete the Inorder Successor
			free(temp);
		}
	}

	root->height = 1 + max( height(root->left), height(root->right) );	// Height of the Current Node is Updated

	// --------------------------------- BALANCE SETTLEMENT ---------------------------------

	int balance = getBalance(root);		// Check Balance after Deletion

	if (balance != 0)
	{
		if (balance > 1 && getBalance(root->left) >= 0)		// Left Left Case
			return rotateRight(root);

		if (balance < -1 && getBalance(root->right) <= 0)	// Right Right Case
			return rotateLeft(root);

		if (balance > 1 && getBalance(root->left) < 0)		// Left Right Case
		{
			root->left = rotateLeft(root->left);
			return rotateRight(root);
		}

		if (balance < -1 && getBalance(root->right) > 0)	// Right Left Case
		{
			root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
	}

	return root;	// Root of Modified SubTree
}

int main()
{
	Node *root = NULL;
	int data, del;

	while (true) 
	{
		cout << "Enter an Integer to Insert in the AVL Tree (To Exit, Press -99): ";
		cin >> data;
		if (data == -99)
			break;
		root = insert(root, data);
	}

	/* If we Construct Tree in Order: 9 5 10 0 6 11 -1 1 2 
	   Then the Constructed AVL Tree would be

				9
			   / \
			  1   10
			 / \   \
			0   5   11
		   /   / \
		 -1   2   6
	*/

	cout << endl<<"Preorder Traversal of the Constructed AVL Tree is: ";
	preOrder(root);
	cout << endl;

	cout << endl << "Please Enter Data to be Deleted: ";
	cin >> del;

	root = deleteNode(root, 10);

	/* If we Delete 10, the New AVL Tree will be

			1
		   / \
		  0   9
		 /   / \
	   -1   5	11
		   / \
		  2   6
	*/

	cout << "Preorder Traversal after Deletion of " << del << " is: ";
	preOrder(root);
	cout << endl;

	return 0;
}
