#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct node{
	string key;
	 node*left;
	 node*right;
};
node*newNode(string key){
	node*tmp=new node;
	tmp->key=key;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
};
bool exists (node *r,string text){
	if(r==NULL){
	return false;
}
if(r->key== text){
	return true;
}
bool a1 = exists (r->left,text);
bool a2= exists (r-> right,text);
 return a1||a2;
}
void  paraRendore(node*r){
	if(r!=NULL){
		cout <<r->key<<endl;
		paraRendore(r->left);
		paraRendore(r->right);
	}
}
void add(node*tmp,string d){
	while(tmp!=NULL){
		if(tmp->left==NULL){
			tmp->left==newNode(d);
			break;
		}
	else{
		tmp=tmp->left;
	}
	if(tmp->right==NULL){
		tmp->right=newNode(d);
		break;
	}else{
		tmp=tmp->right;
	}
  }
}
int main(){
	 ifstream in;
	  node *n = newNode("");
	  string word;
	   int count =0;	   
	   	in.open("skedar1.txt");
	if(in.is_open()){
		while (!in.eof()){
			in>>word;
			if(exists(n,word)==false){
				add(n,word);
				count++;
			}
		}
		paraRendore(n);
		cout<<count<<" fjale te ndryshme."<<endl;
	}
	else{
		cout<<"Error!";
	}
	in.close();
	return 0;
} 
