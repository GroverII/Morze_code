#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

//создание Ноде
struct Node 
{
	int data;
	Node *left, *right;
};

//Первый элемент
Node *CreateNode(int i){
	Node *newNode;
	newNode = new Node;
	newNode->data=i;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;	
}

//Всё дерево
void PrintTree(Node *cur){
	if(!cur)return;
	PrintTree(cur->left);
	cout<<cur->data<<" ";
	PrintTree(cur->right);
}

//Присоеденить один элемент
void AddNode(Node *cur, Node *NNode){
	Node *Temp;
	Temp=cur;
	if(Temp->data>=NNode->data) {
		if(!Temp->left){
			cur->left=NNode;
		}
		else {
			Temp=cur->left;
			AddNode(Temp, NNode);
		}
	}
	else {
		if(!Temp->right){
			cur->right=NNode;
		}
		else {
			Temp=cur->right;
			AddNode(Temp,NNode);
		}
	}
}

//Количество элементов
int Count(Node *root, int k){
	if(!root) return k;
	else {
		k=Count(root->left, k);
		k++;
		k=Count(root->right, k);
	}
}

void finding(Node *root, Node *find, string s){
	Node *cur;
	cur=root;
		if(cur->data==find->data) {
			ofstream file1;
			file1.open("MorzeCode.txt", ios::app);
			if(!file1){cout<<"Nav!"; system("pause>nul"); exit(1);}
			file1<<s<<"|";
			cout<<s<<"|";
			file1.close();
		}
			
		else if(cur->left || cur->right)
		{
			if(cur->data>find->data && cur->left) {
				s+=".";
				finding(root->left, find, s);
			}	
			else if(cur->data<find->data && cur->right) 
			{
				s+="-";
				finding(root->right, find, s);
			}
		}
}

void StartOfEnc(char* mas, int n, Node *root){
	int b;
	string s;
	Node *find=NULL;
	for(int i=0; i<n; i++){
		cout<<mas[i];
	}
	cout<<endl;
	for(int i=0; i<n; i++){
		s="";
		b=(int)mas[i];
		switch(b){
			case(65):
				find=CreateNode(14);
				finding(root, find, s);
				break;
			case(66):
				find=CreateNode(21);
				finding(root, find, s);
				break;
			case(67):
				find=CreateNode(25);
				finding(root, find, s);
				break;
			case(68):
				find=CreateNode(22);
				finding(root, find, s);
				break;
			case(69):
				find=CreateNode(11);
				finding(root, find, s);
				break;
			case(70):
				find=CreateNode(8);
				finding(root, find, s);
				break;
			case(71):
				find=CreateNode(31);
				finding(root, find, s);
				break;
			case(72):
				find=CreateNode(2);
				finding(root, find, s);
				break;
			case(73):
				find=CreateNode(7);
				finding(root, find, s);
				break;
			case(74):
				find=CreateNode(17);
				finding(root, find, s);
				break;
			case(75):
				find=CreateNode(26);
				finding(root, find, s);
				break;
			case(76):
				find=CreateNode(12);
				finding(root, find, s);
				break;
			case(77):
				find=CreateNode(33);
				finding(root, find, s);
				break;
			case(78):
				find=CreateNode(24);
				finding(root, find, s);
				break;
			case(79):
				find=CreateNode(35);
				finding(root, find, s);
				break;
			case(80):
				find=CreateNode(15);
				finding(root, find, s);
				break;
			case(81):
				find=CreateNode(32);
				finding(root, find, s);
				break;
			case(82):
				find=CreateNode(13);
				finding(root, find, s);
				break;
			case(83):
				find=CreateNode(4);
				finding(root, find, s);
				break;
			case(84):
				find=CreateNode(28);
				finding(root, find, s);
				break;
			case(85):
				find=CreateNode(9);
				finding(root, find, s);
				break;
			case(86):
				find=CreateNode(5);
				finding(root, find, s);
				break;
			case(87):
				find=CreateNode(16);
				finding(root, find, s);
				break;
			case(88):
				find=CreateNode(23);
				finding(root, find, s);
				break;
			case(89):
				find=CreateNode(27);
				finding(root, find, s);
				break;
			case(90):
				find=CreateNode(30);
				finding(root, find, s);
				break;
			case(48):
				find=CreateNode(37);
				finding(root, find, s);
				break;
			case(49):
				find=CreateNode(18);
				finding(root, find, s);
				break;
			case(50):
				find=CreateNode(10);
				finding(root, find, s);
				break;
			case(51):
				find=CreateNode(6);
				finding(root, find, s);
				break;
			case(52):
				find=CreateNode(3);
				finding(root, find, s);
				break;
			case(53):
				find=CreateNode(1);
				finding(root, find, s);
				break;
			case(54):
				find=CreateNode(20);
				finding(root, find, s);
				break;
			case(55):
				find=CreateNode(29);
				finding(root, find, s);
				break;
			case(56):
				find=CreateNode(34);
				finding(root, find, s);
				break;
			case(57):
				find=CreateNode(36);
				finding(root, find, s);
				break;
			default:
				break;
		}
	}
}

void textM(Node *root){
	ifstream file1;
	char mas[1000];
	int n;
	file1.open("Text.txt");
	if(!file1){cout<<"Nav!"; system("pause>nul"); exit(1);}
	//get inf and size of inf
	while(!file1.eof()){
	file1.getline(mas,1000,'\n');
	n=file1.gcount();
	//start enctiption
	StartOfEnc(mas, n, root);
	}
	file1.close();
}

int check(Node *root, char* mas, int j, int i){
	Node *cur;
	cur=root;
	string s;
	if(mas[i]!='\0' && cur->data!=NULL && i==j) {
			return cur->data;
		}		
	else if((mas[i]=='.' || mas[i]=='-') && i<j)
		{
			if(mas[i]=='.') {
				return check(root->left, mas, j, i+1);
			}
				
			else if(mas[i]=='-') 
			{
				return check(root->right, mas, j, i+1);
			}
			else 
				return 0;
		}
	else 
		return 0;
}

void NewFile(char* newmas, int k){
	ofstream file1;
	file1.open("NewText.txt");
	if(!file1){cout<<"Nav!"; system("pause>nul"); exit(1);}
	cout<<endl;
	for(int i=0; i<k; i++){
		file1<<newmas[i];
		cout<<newmas[i];
	}
	file1.close();
}

void Dec(char* mas, int n, Node *root){
	string s[n];
	int b, j=0, k=0;
	char newmas[n];
	Node *find=NULL;
	for(int i=0; i<n; i++){
		while(mas[j]!='|') j++;
		b=check(root, mas, j, i);
		j++;
		while(mas[i]!='|') i++;
		switch(b){
			case(14):
				newmas[k]='A';
				k++;
				break;
			case(21):
				newmas[k]='B';
				k++;
				break;
			case(25):
				newmas[k]='C';
				k++;
				break;
			case(22):
				newmas[k]='D';
				k++;
				break;
			case(11):
				newmas[k]='E';
				k++;
				break;
			case(8):
				newmas[k]='F';
				k++;
				break;
			case(31):
				newmas[k]='G';
				k++;
				break;
			case(2):
				newmas[k]='H';
				k++;
				break;
			case(7):
				newmas[k]='I';
				k++;
				break;
			case(17):
				newmas[k]='J';
				k++;
				break;
			case(26):
				newmas[k]='K';
				k++;
				break;
			case(12):
				newmas[k]='L';
				k++;
				break;
			case(33):
				newmas[k]='M';
				k++;
				break;
			case(24):
				newmas[k]='N';
				k++;
				break;
			case(35):
				newmas[k]='O';
				k++;
				break;
			case(15):
				newmas[k]='P';
				k++;
				break;
			case(32):
				newmas[k]='Q';
				k++;
				break;
			case(13):
				newmas[k]='R';
				k++;
				break;
			case(4):
				newmas[k]='S';
				k++;
				break;
			case(28):
				newmas[k]='T';
				k++;
				break;
			case(9):
				newmas[k]='U';
				k++;
				break;
			case(5):
				newmas[k]='V';
				k++;
				break;
			case(16):
				newmas[k]='W';
				k++;
				break;
			case(23):
				newmas[k]='X';
				k++;
				break;
			case(27):
				newmas[k]='Y';
				k++;
				break;
			case(30):
				newmas[k]='Z';
				k++;
				break;
			case(37):
				newmas[k]='0';
				k++;
				break;
			case(18):
				newmas[k]='1';
				k++;
				break;
			case(10):
				newmas[k]='2';
				k++;
				break;
			case(6):
				newmas[k]='3';
				k++;
				break;
			case(3):
				newmas[k]='4';
				k++;
				break;
			case(1):
				newmas[k]='5';
				k++;
				break;
			case(20):
				newmas[k]='6';
				k++;
				break;
			case(29):
				newmas[k]='7';
				k++;
				break;
			case(34):
				newmas[k]='8';
				k++;
				break;
			case(36):
				newmas[k]='9';
				k++;
				break;
			default:
				break;
		}
	}
	NewFile(newmas, k);
}

void textMD(Node *root){
	ifstream file1;
	char mas[1000];
	int n;
	file1.open("MorzeCode.txt");
	if(!file1){cout<<"Nav!"; system("pause>nul"); exit(1);}
	//get inf and size of inf
	while(!file1.eof()){
	file1.getline(mas,1000,'\n');
	n=file1.gcount();
	//start enctiption
	Dec(mas, n, root);
	}
	file1.close();
}

int main(){
bool menu=true, rev=false;
int i=128, j=126;
Node *root=NULL, *NNode=NULL;

root=CreateNode(19);
//1
NNode=CreateNode(11);
AddNode(root, NNode);

NNode=CreateNode(7);
AddNode(root, NNode);

NNode=CreateNode(14);
AddNode(root, NNode);

NNode=CreateNode(4);
AddNode(root, NNode);

NNode=CreateNode(9);
AddNode(root, NNode);

NNode=CreateNode(13);
AddNode(root, NNode);

NNode=CreateNode(16);
AddNode(root, NNode);

NNode=CreateNode(2);
AddNode(root, NNode);

NNode=CreateNode(5);
AddNode(root, NNode);

NNode=CreateNode(8);
AddNode(root, NNode);

NNode=CreateNode(12);
AddNode(root, NNode);

NNode=CreateNode(15);
AddNode(root, NNode);

NNode=CreateNode(17);
AddNode(root, NNode);

NNode=CreateNode(1);
AddNode(root, NNode);

NNode=CreateNode(3);
AddNode(root, NNode);

NNode=CreateNode(6);
AddNode(root, NNode);

NNode=CreateNode(10);
AddNode(root, NNode);

NNode=CreateNode(18);
AddNode(root, NNode);

NNode=CreateNode(28);
AddNode(root, NNode);

NNode=CreateNode(24);
AddNode(root, NNode);

NNode=CreateNode(33);
AddNode(root, NNode);

NNode=CreateNode(22);
AddNode(root, NNode);

NNode=CreateNode(26);
AddNode(root, NNode);

NNode=CreateNode(31);
AddNode(root, NNode);

NNode=CreateNode(35);
AddNode(root, NNode);

NNode=CreateNode(21);
AddNode(root, NNode);

NNode=CreateNode(23);
AddNode(root, NNode);

NNode=CreateNode(25);
AddNode(root, NNode);

NNode=CreateNode(27);
AddNode(root, NNode);

NNode=CreateNode(30);
AddNode(root, NNode);

NNode=CreateNode(32);
AddNode(root, NNode);

NNode=CreateNode(20);
AddNode(root, NNode);

NNode=CreateNode(29);
AddNode(root, NNode);

NNode=CreateNode(34);
AddNode(root, NNode);

NNode=CreateNode(36);
AddNode(root, NNode);

NNode=CreateNode(37);
AddNode(root, NNode);

ofstream file1;
file1.open("MorzeCode.txt");
if(!file1){cout<<"Nav!"; system("pause>nul"); exit(1);}
file1.close();
textM(root);
textMD(root);
return 0;
}
