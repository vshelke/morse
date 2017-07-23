#include <iostream>
using namespace std;

//-----------------------------Tree--------------------------------

struct node {
	int data;
	node* left;
	node* right;
};

node* NewNode(int data) {
	node* tmp = new node();
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	return tmp;
}

node* insert(node* root, int data) {
	
	if (root == NULL)
		root = NewNode(data);
	
	else if ( data <= root->data) 
		root->left = insert(root->left, data);
	
	else
		root->right = insert(root->right, data);

	return root;
}

//-----------------------------------------------------------------

//----------------------------Morse Converter----------------------

void morse(node* root, int val) {
	if ( root == NULL || root->data == val) return;

	if (val < root->data) {
		cout << '-';
		return morse(root->left, val);
	} else {
		cout << '.';
		return morse(root->right, val);
	}
}

int change(char x) {
char ref[] = {" o.mqgztykcnxdb#jwpa$rle-ufivsh"};
	for (int i = 0;i<31; i++) 
		if (ref[i] == x) 
			return i;
}

//-----------------------------------------------------------------

//----------------------Initialization of tree---------------------

/**
	The tree is built to adjust the Morse code tree.
	You can change the logic in init() to suit your own tree which is not morse
*/

node* init(node* root) {
	int i = 15,diff = 16,nos = 2,tmp;
	root = insert(root, i);
	tmp = i;
	while (i != 30) {
		i = tmp/2;
		root = insert(root, i);
		tmp = i;
		for (int j =0;j<nos-1;j++) {
			i += diff;
			root = insert(root, i);
		}
		nos *=2;
		diff /= 2;
	}
	return root;
}

//----------------------------------------------------------------

int main() {
	node* root = NULL;
	string str;

	root = init(root);
	cout <<"-------------------------------------------------------"<<'\n';					   
	cout <<"|                    Morse Converter                  |"<<'\n';
	cout <<"-------------------------------------------------------"<<'\n';
	while (1) {
		cout << '\n'<<"Enter String: ";
		getline(cin, str);
		if (str == "exit")	break;
		cout << "Morse code: ";
		for (int i =0 ;str[i] !='\0';i++){ 
			morse(root, change(str[i]));
			cout << ' ';
		}
	}
	return 0;
}

/**
  ~~
 |^^|
 <\/>
  /\
  		~ Always believe in yourself !! 
*/