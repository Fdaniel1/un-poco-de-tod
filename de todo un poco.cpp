#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;
typedef struct{
	int cd;
	char nom[30],ape[30];
}data;
struct pila{
	data dato;
	struct pila *sig;
};
typedef struct pila nodo;
typedef nodo *punt_nodo;
void meter(punt_nodo *, data);
void sacar(nodo *);
void chau(punt_nodo *);
void donde(nodo *);
main(){
	nodo *l=NULL;
	data pija;
	char opc=' ';
	do{
		system("cls");
		cout<<"1. Insertar"<<endl;
		cout<<"2. Buscar"<<endl;
		cout<<"3. Eliminar"<<endl;
		cout<<"4. Mostrar"<<endl;
		cout<<"5. Salir"<<endl;
		opc=getch();
		switch(opc){
			case'1':
				system("cls");
				cout<<"Ingrese Nombre"<<"	"<<"Apellido"<<"	"<<"Cedula"<<endl;
				scanf("%s %s %d",pija.nom,pija.ape,pija.cd);
				meter(&l, pija);
				break;
			case'2':
				donde(l);
				break;
			case'3':
				chau(&l);
				break;
			case'4':
				sacar(l);
				break;
		}
	}while(opc==5);	
}
void meter(punt_nodo *l, data n){
	nodo *aux;
	aux=(nodo *)malloc(sizeof(struct pila));
	aux->dato=n;
	if((*l)==NULL){
		(*l)=aux;
		aux->sig=NULL;
	}else{
		aux->sig=(*l);
		(*l)=aux;
	}
	system("pause");
	getch();
}
void sacar(nodo *l){
	system("cls");
	FILE*Ar;
	Ar=fopen("Polola_net.txt","w");
	if(Ar==NULL){
		cout<<"Re trucho tu archivo pibe"<<endl;
	}
	if(l==NULL){
		cout<<"No existe nodo para mostrar"<<endl;
	}else{
		while(l!=NULL){
			fprintf(Ar,"\n %s %s %d",l->dato.nom,l->dato.ape,l->dato.cd);
			printf("\n %s %s %d",l->dato.nom,l->dato.ape,l->dato.cd);
			l=l->sig;
		}
	}
	system("pause");
	getch();
}
void chau(punt_nodo *l){
	system("cls");
	nodo *aux;
	if((*l)!=NULL){
		aux=(*l);
		(*l)=(*l)->sig;
		free(aux);
		cout<<"Nodo eliminado"<<endl;
	}
	system("pause");
	getch();
}
void donde(nodo *l){
	system("cls");
	data q;
	int sw=0;
	cout<<"Ingrese nombre a buscar"<<endl;
	cin>>q.nom;
	while(l!=NULL){
		if(strcmp(q.nom,l->dato.nom)==0){
			cout<<"Valor encontrado";
			cout<<q.nom;
			sw=1;
		}
		l=l->sig;
		if(sw==0){
			cout<<"Valor no encontrado"<<endl;
		}
	}
	system("pause");	
	getch();
}


