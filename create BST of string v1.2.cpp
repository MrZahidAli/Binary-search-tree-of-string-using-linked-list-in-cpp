//(BST) Binary search tree using linked list

// 1- creating BST of string using linked list in cpp
// 2- printing BST: inorder, preorder, postorder

#include<iostream>
using namespace std;
class node{
	public:
		string data;
		node *left, *right, *previous;
};
class linkList{
	public:
		node *root;
	public:
		linkList(){
			root = NULL;
		}
//compare strings
	int biggerString(string str1, string str2){
		int com = str1.compare(str2);
		return com;
	}
// 1- creating BST
		void creatList(string value){
			node *temp = new node;
			node *copyRoot = root;
			temp -> data = value;
			temp -> left = NULL;
			temp -> right = NULL;
			if(root == NULL){
				root = temp;
				copyRoot = temp;
			}
			else{
				while(copyRoot != NULL ){
					if(biggerString(temp -> data, copyRoot -> data) == 1){   //temp -> data < copyRoot -> data 
						if(copyRoot -> left == NULL){
							copyRoot -> left = temp;
							temp -> previous = copyRoot;
							return;
						}else{
							copyRoot = copyRoot -> left;
						}
					}else{
						if(copyRoot -> right == NULL){
							copyRoot -> right = temp;
							temp -> previous = copyRoot;
							return;
						}else{
							copyRoot = copyRoot -> right;
						}
					}
				}
			}
			
		}
// 2- printing BST in inorder
		void printInorder(node *temp){
			if(temp != NULL){
				printInorder(temp -> left);
				cout << endl << temp -> data;
				printInorder(temp -> right);
			}
		}
// 2- printing BST in postorder
		void printPostorder(node *temp){
			if(temp != NULL){
				printInorder(temp -> left);
				printInorder(temp -> right);
				cout << temp -> data;
			}
		}
// 2- printing BST in preorder
		void printPreorder(node *temp){
			if(temp != NULL){
				cout << temp -> data;
				printInorder(temp -> left);
				printInorder(temp -> right);
			}
		}
};
int main(){
	linkList B;
	B.creatList("zahid");
	B.creatList("aahid");
	B.creatList("bahid");
	B.printInorder(B.root);
	return 0;
}
