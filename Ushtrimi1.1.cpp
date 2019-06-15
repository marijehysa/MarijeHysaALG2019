#include <iostream>
#include <string>
#include <fstream>
using namespace std;

 struct liste
 {
 	 string key;
 	 liste*pas;
 };
  liste * newListe(string key){
  	liste*e = new liste;
  	e->key= key;
  	e->pas=NULL;
  }
   void print(liste*n){
   	while(n!=NULL){
   		cout<<n->key<<endl;
   		n=n->pas;
	   }
	   cout<<endl;
   }
   
   void shto(liste*n,string p){
   	liste*tmp=newListe(p);
   	   	if (n==NULL){
   		n->key=p;
   		n->pas=NULL;
	   }else{
	   	while(n->pas!=NULL){
	   		n=n->pas;
		   }
		   n->pas=tmp;
	   }
   }
   bool search (liste*koke,string f){
   	liste*tmp=koke;
   	while(tmp!=NULL){
   		if(tmp->key==f){
   			return true;	
		   }
		   tmp=tmp->pas;
	   }
	   return false;
   }
  int main(){
  	ifstream in ;
  	 liste *n=newListe(" ");
  	 int count=0;
  	 string word;
  	 in.open("skedar1.txt");
  	 if(in.is_open()){
  	 	while(!in.eof()){
  	 		cout<<"Vendos fjalen:"<<endl;
  	 		in>>word;
  	 		
  	 		if(search(n,word)==false){
  	 		
  	 			shto(n,word);
  	 			
  	 				count++;
			   }
		   } 
		   print(n);
		   cout<<count<<"fjale te ndryshme."<<endl;
		   in.close();
	   }
	  else{
	  	cout<<"Error!"<<endl;
	  } 
	  in.close();
	  return 0;
  } 
   
   
   
   
   
   
   
   
   
   
