
#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
class node{
	public:
		string data;
		node *left, *right, *previous;
};
class BST{
	public:
		node *root;
	public:
		BST(){
			root = NULL;
		}
//compare strings
	int biggerString(string str1, string str2){
		int com = str1.compare(str2);				//return 0 if both are same and 1 if str2 is bigger and -1 if str1 is bigger
		return com;
	}
// creating BST of string (from file data).
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
	system("color 84");
	BST B;
	
	string line;
	ifstream mfile("spellDic.txt");
	if (mfile.is_open()){
		while(getline(mfile,line)){
    		B.creatList(line);
    	}
    	mfile.close();
	}
	else cout << "Unable to open file";
	B.printInorder(B.root);
	return 0;
}
