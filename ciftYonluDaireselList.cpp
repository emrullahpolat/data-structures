#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#define max 100
using namespace std;

typedef struct num_node{
	int data;
	num_node *next;
	num_node *prev;
};

void menu(){
	
	printf("\n         VERI YAPILARI DERSI ODEVI");
	printf("\n1: Yeni sayi ekleme");
	printf("\n2: Sayi arama");
	printf("\n3: Elemanlari duz lisele");
	printf("\n4: Elemanlari tersten listele");
	printf("\n5: Eleman sayisini ogrenme");
	printf("\n6: Elemen silme");
	printf("\n7: Cikis");
	printf("\n\nSeciminiz: ");
	
}		//void fonksiyon bitiþi


void arama(num_node *r, int sayi){
	num_node *iter = r;
	if(r == NULL){
			printf("Liste Bostur...");
	}else{
		    if(r->data == sayi){
		    	printf("ARANAN SAYI VAR");	
		    }else{
		    	while(iter->next != r && iter->next->data != sayi){
					iter = iter->next;
				}
				if(iter->next == r){
					printf("ARANAN SAYI YOK");		
				}
		    	printf("ARANAN SAYI VAR");
			}
			
	}
	
	
} //void fonksiyon bitiþi

int elemanSayisi(num_node *r){
	num_node *iter = r;
	int i = 1;
	if(r == NULL){
		printf("\nBagli Listede Eleman Yoktur...");
		return 0;
	}else{
		if(iter->next == r){
			i=1;
		}
		while(iter->next != r){
			i++;
			iter = iter->next;	
		}		
		printf("\n%d Eleman Vardir Bagli Listede...",i);
		
		return i;
	}
		
}		//void fonksiyon bitisi

void sondanBasaYazdir(num_node *r){
	int i=elemanSayisi(r);
	
	num_node *iter = r;
	if(r == NULL){
		printf("Liste Bostur...");
	}else{
		printf("\nliste yazdiriliyor...");
	
		while(iter->prev != r){
			printf("\n%d. sayi : %d ",i,iter->prev->data);
			iter = iter->prev;	
			i--;
		}
		printf("\n%d. sayi : %d",i,iter->prev->data);
	}
		
}		//void fonksiyon bitiþi

void bastanSonaYazdir(num_node *r){
	int i=0;
	num_node *iter = r;
	if(r == NULL){
		printf("Liste bostur...");
	}else{
		printf("\nliste yazdiriliyor...");
	
		while(iter->next != r){
			i++;
			printf("\n%d. sayi : %d ",i,iter->data);
			iter = iter->next;	
		}
		printf("\n%d. sayi : %d",i+1,iter->data);
	}
		
}		//void fonksiyon bitiþi


num_node *ekle(num_node *r, int sayi){
	if(r == NULL ){ //ilk eleman eklemek için
		r = (num_node *)malloc (sizeof(num_node));
		r->next = r;
		r->prev = r;
		r->data = sayi;
		return r;
	}
	
	if(r != NULL){ 
		num_node *iter = r;
		while(iter->next != r){
			iter = iter->next;
		}
		num_node *temp = (num_node *)malloc (sizeof(num_node));
		temp->next = iter->next;
		iter->next = temp;
		
		temp->prev = iter;
		temp->next->prev = temp;
		
		temp->data = sayi;
		return r;
	}
}		//void fonksiyon bitiþi

num_node *sil(num_node *r, int sayi){
	num_node *temp;
	num_node *iter = r;
	if(r == NULL){
		printf("\nListe Bostur...");
	}else{
		if(r->data == sayi){
		temp = r;
		r = r->next;
		free(temp);
		return r;
		}
		while(iter->next != r && iter->next->data != sayi){
			iter = iter->next;
		}
		if(iter->next == r){
			printf("\nsayi bulunamadi...");
			return r;
		}
		temp = iter->next;
		iter->next = iter->next->next;
		iter->next->prev = iter->next;
		free(temp);
		return r;
	}
		
}	//void fonksiyon bitiþi


int main(){
	num_node *root;		//kök node seçimi için oluþturuldu
	num_node *iter;		//döngüler için geçici bir gezgin node iþaretcisi oluþturdum
	root=NULL;
	
	int temp;
	string satir = "";
	ifstream input("deneme.txt");
	input>>temp;
	root = ekle(root,temp);
	

	while(getline(input,satir)){
		input>>temp;
		//cout << temp;
		root = ekle(root,temp);
	}
	
	
	input.close();
	
	int sayi;
	int secim;		
	do{
		menu();
		secim = 0;
		scanf("%d",&secim);
		switch(secim){
			case 1:
				printf("\nEklenecek sayiyi giriniz : ");
				scanf("%d",&sayi);				
				root = ekle(root,sayi);
				break;
			case 2:
				printf("\nAranacak sayiyi giriniz : ");
				scanf("%d",&sayi);
				arama(root,sayi);
				break;
			case 3:
				bastanSonaYazdir(root);
				break;
			case 4:
				sondanBasaYazdir(root);
				break;
			case 5:
				elemanSayisi(root);
				break;
			case 6:
				printf("Silmek istenen sayiyi giriniz : ");
				scanf("%d",&sayi);
				sil(root,sayi);
				break;
			
			default:
				break;
		}
	}while(secim != 7);
	
		
}


