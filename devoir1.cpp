#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

//defining the structure of each column in our table
struct occ{
string value;
int cpt;
};

//the prototype of the function to add element to our vector
vector<occ> add(vector<occ> vect, string x,int y);

int main (){
string posOne,posTwo;
fstream file1,file2;

cout << "SIMLARITY FILES TEST" <<endl;
cout << " " << endl;

cout << "ENTER YOUR FIRST FILE position" <<endl;
getline(cin,posOne);
file1.open(posOne,ios::in);
//testing if the file exist 
	while(!file1){
	cout << "ENTER the right position of file 1 please" <<endl;
	getline(cin,posOne);
	file1.open(posOne,ios::in);
	}	
cout << " " << endl;

cout << "ENTER YOUR SECOND FILE position" <<endl;
getline(cin,posTwo);
file2.open(posTwo,ios::in);
	while(!file2){
	cout << "ENTER the right position of file 2 please" <<endl;
	getline(cin,posTwo);
	file2.open(posTwo,ios::in);
	}

//creating of the two vectors where we will copy our files conetents
vector<occ> cpFile1;vector<occ> cpFile2;
 int k;
//testing if the files are empty
if((file1.eof()) && (file2.eof()) ) {
cout << " one of the two files is empty...check them again please" << endl;
}
	else{
		string word1,word2;
		 bool find;
		
		while(!file1.eof()){
		
			file1 >> word1;
			k=0;
			find=false;
			
			//testing if the word is already in the vector
			while(k< cpFile1.size()){
			
			if (cpFile1[k].value == word1)
			{find=true;
			cpFile1[k].cpt+=1;
			}
			k++;
			}
			//if the value does not exist we add it in our vector		
			if(find==false){
			cpFile1=add(cpFile1,word1,1);}
			 
			 }
			 
			 file1.close();
			 
			 while(!file2.eof()){
			file2 >> word2;
			k=0;
			find=false;
			
			while(k< cpFile2.size()){
			
			if (cpFile2[k].value == word2)
			{find=true;
			cpFile2[k].cpt+=1;
			}
			k++;
			}
			
			if(find==false){
			cpFile2=add(cpFile2,word2,1);}
			 
		}			
		file2.close(); 
	}



int produit(0);

//counting similarities between the two vectors 

for(int i=0; i<cpFile1.size();i++){
 k=0;

while( k< cpFile2.size()) {
	if(cpFile1[i].value == cpFile2[k].value){
	
	produit+=(cpFile1[i].cpt * cpFile2[k].cpt); 
	break;
	}
k++;}

} 


int f1(0),f2(0);
for(int i=0 ; i<cpFile1.size();i++){
f1+= (pow(cpFile1[i].cpt,2));
}
for(int i=0 ; i<cpFile2.size();i++){
f2+= (pow(cpFile2[i].cpt,2));
}
  
//after having the product we divide it on the multiplication length of the two vectors and introduce our cos function

cout << " . . . " << endl;
if (produit == 0) { cout << " there is no similarity between the two files " << endl;
 }
else { 
int result =100*(produit/(sqrt(f1)*sqrt(f2))) ;
cout <<" the similarity between file 1 & file 2 is up to "<<result <<"%" << endl;
 
/*
this formula does not work : (180/3.14159)*acos((produit/(cpFile1.size()*cpFile2.size()))) 
but i tried many ways with different cases in vectors and it does not give me the right number

*/
}
 
return 0;
}

//defining our adding function to the vector ( since its a vector we can not write .push_back directly ) 
vector<occ> add(vector<occ> vect,string x,int y){

occ one;
one.value=x;
one.cpt=y;
vect.push_back(one);
return vect;
}