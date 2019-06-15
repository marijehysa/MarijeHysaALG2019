#include <iostream>
#include <fstream>
#include<string>
using namespace std;

struct node{
	string key;
	node* left;
	node*right;	
};
node *newNode(string key){
	node*tmp=new node;
	tmp->key=key;
	tmp->right=NULL;
	tmp->left=NULL;
	return tmp;
}
bool exist (node*root,string text){
	if(root==NULL){
		return false;
	}
	if (root ->key==text){
		return true;
	}
	bool a1=exist (root->right,text);
	bool a2 =exist(root->left,text);	
	return a1||a2;
}
void pasRendore (node*root){
	if (root!=NULL){
		pasRendore(root->left);
		pasRendore(root->right);
		cout<<root->key<<endl;
	}
}
void add(node*root,string text){
	while(root!=NULL){
		if (!root->left){
			root->left=newNode(text);
			break;
		}
		if(!root->right){
			root->right=newNode(text);
			break;
		}
		root=root->left;
	}
}

int main(){
	ifstream in;
	string word;
	node*Pema=newNode(" ");
	int count;	
	in.open("skedar1.txt");
	if(in.is_open()){
		while (!in.eof()){
			in>>word;
			if(exist(Pema,word)==false){
				count++;
				add(Pema,word);
			}
		}
		pasRendore(Pema);
		cout<<count<<"  fjale te ndryshme."<<endl;	
	}
	else{
		cout<<"Error!!!";
	}
	in.close();
	return 0;
}











