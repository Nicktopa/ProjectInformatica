#include "mappa.h"
#include "player.h"
#include <iostream>


void first_node(){ //inizializzazione primo nodo della mappa, da dove tutti partono.
ptr_lista_mappa p;
p=new lista_mappa;
p->x=0;
p->y=0;
p->left=NULL;
p->right=NULL;
p->up=NULL;
p->down=NULL;
global_minus_x=0;
	inizializza_tabnodipresenti(p); //crea la lista che contiene tutti i nodi presenti nella mappa
//	inizializzazione_posizione_giocatori();//funzione che inizializza la posizione di ogni giocatore al nodo di partenza(x=0,y=0) VA NEL PLAYER.cpp

}

void inizializza_tabnodipresenti(ptr_lista_mappa p){	//inserisce nella tabella dei nodi presenti il primo nodo (x=0 y=0)
	head=new tabnodipresenti;
	head->p_nodo=p;
	head->next=NULL;
}



void spostamento(){  //funzione in cui il gicoatore sceglie la direzione di spostamento
	char scelta;
	do{
	cout<<"scegli il movimento scrivendo: u=up; d=down; l=left; r=right";
	cin>>scelta;			//inserisce la scelta
	if(scelta=="d"){
		if(player->p_pos_player->down==null) create_new_node(scelta);	//se dalla posizione del giocatore, il nodo nella direzione dove si vuol spostare non esiste (->down=NULL) si crea quel nodo
		else existing_node(scelta);	//in questo caso il nodo dove si vuol spostare esiste, quindi non si dovrà creare nessun nodo, si sposterà semplicemente.
	};
	else if(scelta=="u"){
		if(player->p_pos_player->up==null) create_new_node(scelta);
		else existing_node(scelta);
	};
	else if(scelta=="l"){
		if(player->p_pos_player->left==null) create_new_node(scelta);
		else existing_node(scelta);
	};
	else if(scelta=="r"){
		if(player->p_pos_player->right==null) create_new_node(scelta);
		else existing_node(scelta);
	};
	while(scelta!="d" && scelta!="u" && scelta!="l" && scelta!="r"); //ciclo continuo se sbaglia la scelta con una lettera errata.
}

void add_node_tabnodipresenti(ptr_lista_mappa p_adding_node){		//Funzione di inserimento nella tabella dei nodi del nodo creato
	ptr_tabnodipresenti p;
	if(head->next==NULL){	//se la tabella ha un solo elemento (x=0 e y=0)
		if(p_adding_node->x < 0  || p_adding_node->y > 0){	//il nodo si aggiunge alla testa
			p=new tabnodipresenti;
			p->p_nodo=p_adding_node;
			p->next=head;
			head=p;
		}
		else{		//il nodo si aggiunge alla coda
			p=new tabnodipresenti;
			head->next=p;
			p->p_nodo=p_adding_node;
			p->next=NULL;
		}
	}
	else{		//se la tabella ha più di un solo elemento
		
		if(p_adding_node->y > head->p_nodo->y){	//controllo che il nodo head non abbia y MINORE del nodo da aggiungere, se è minore significa che devo aggiungere in testa.
			p=new tabnodipresenti;
			p->p_nodo=p_adding_node;
			p->next=head;
			head=p;
		}
		else if(p_adding_node->y = head->p_nodo->y){	//controllo che il nodo head non abbia y UGUALE del nodo da aggiungere, se è uguale 
			if(p_adding_node->x < head->p_nodo->x){		//controllo la x del nodo da aggiungere che sia minore della x del nodo head. Se è minore significa che devo aggiungere in testa.
				p=new tabnodipresenti;
				p->p_nodo=p_adding_node;
				p->next=head;
				head=p;
			}
		}
		else{
			ptr_tabnodipresenti p_prec;
			p=head;
			p=p->next;
			p_prec=head;
			while(p->p_nodo->y > p_adding_node->y && p!=NULL){
				p=p->next;
				p_prec=p_prec->next;
			}
				if(p!=NULL){	//inserimento tra due nodi
					while(p->p_nodo->x < p_adding_node->x && p!=NULL && p->p_nodo->y == p_prec->p_nodo->y)
						p=p->next;
						p_prec=p_prec->next;
					}
						if(p->p_nodo->x > p_adding_node->x || p->p_nodo->y == p_prec->p_nodo->y){
							p_prec->next=new tabnodipresenti;
							p_prec=p_prec->next;
							p_prec->p_nodo=p_adding_node;
							p_prec->next=p;


						}
						else {
							p=new tabnodipresenti;
							p_prec->next=p;
							p->p_nodo=p_adding_node;
							p->next=NULL;
						}

				}
				else{		//sarà un inserimento in coda
					p=new tabnodipresenti;
					p_prec->next=p;
					p->p_nodo=p_adding_node;
					p->next=NULL;
				}
		}

	}

}


void create_new_node(char scelta){
	ptr_lista_mappa p;	//dichiaro un puntatore al nodo della mappa
	p=player->p_pos_player;	//p è uguale alla posizione del giocatore prima che si sposti
	if (scelta=="u"){ //scelta su
		player->p_pos_player->up=new lista_mappa;
		player->p_pos_player=player->p_pos_player->up; //la posizione del giocatore punta al nodo dove si è spostato
		player->p_pos_player->down=p;	//si crea il collegamento di ritorno tra i due nodi 
			player->p_pos_player->y=p->y+1; //la coordinata y del nuovo nodo sarà incrementata di 1 rispetto al nodo precedente perchè è up.
			player->p_pos_player->x=p->x;	//la coordinata x del nuovo nodo sarà uguale al nodo precedente perchè è up.
				add_node_tabnodipresenti(player->p_pos_player);	
				linknode(player->p_pos_player, scelta);
	}
	else if(scelta=="l"){	//scelta sinistra
		player->p_pos_player->left=new lista_mappa;
		player->p_pos_player=player->p_pos_player->left;
		player->p_pos_player->right=p;
			player->p_pos_player->y=p->y; //la coordinata y del nuovo nodo sarà uguale al nodo precedente perchè è left.
			player->p_pos_player->x=p->x-1;	//la coordinata x del nuovo nodo sarà decrementata di 1 rispetto al nodo precedente perchè è left.
					if(player->p_pos_player->x < global_minus_x) {global_minus_x = player->p_pos_player->x;} //imposto la global_minus_x se il nuovo nodo è in una x minore. 
				add_node_tabnodipresenti(player->p_pos_player);
				linknode(player->p_pos_player, scelta);
	}
	else if(scelta=="d"){	//scelta giù
		player->p_pos_player->down=new lista_mappa;
		player->p_pos_player=player->p_pos_player->down;
		player->p_pos_player->up=p;
			player->p_pos_player->y=p->y-1; //la coordinata y del nuovo nodo sarà decrementata di 1 rispetto al nodo precedente perchè è down.
			player->p_pos_player->x=p->x;	//la coordinata x del nuovo nodo sarà uguale al nodo precedente perchè è down.
				add_node_tabnodipresenti(player->p_pos_player);
				linknode(player->p_pos_player, scelta);
	}
	else {	//scelta destra
		player->p_pos_player->right=new lista_mappa;
		player->p_pos_player=player->p_pos_player->right;
		player->p_pos_player->left=p;
			player->p_pos_player->y=p->y; //la coordinata y del nuovo nodo sarà uguale al nodo precedente perchè è right.
			player->p_pos_player->x=p->x+1;	//la coordinata x del nuovo nodo sarà incrementata di 1 rispetto al nodo precedente perchè è right.
				add_node_tabnodipresenti(player->p_pos_player);
				linknode(player->p_pos_player, scelta);
	}

}
void linknode(ptr_lista_mappa new_node, char scelta){
	ptr_lista_mappa nodelinking;
	int ricercax, ricercay;
	if (scelta=="u"){		//!!!!!!!!!!controllare gli incrementi e decrementi delle x e y da ricercare!!!!
		//inizio ricerca left
		ricercax=new_node->x;
		ricercay=new_node->y;
		ricercay++;
		nodelinking=ricerca(ricercay, ricercax);
			new_node->left=nodelinking
			if(nodelinking!=NULL) nodelinking->right=new_node;
		//inizio ricerca up
		ricercax=new_node->x;
		ricercax--;
		ricercay=new_node->y;
		nodelinking=ricerca(ricercay, ricercax);
			new_node->up=nodelinking
			if(nodelinking!=NULL) nodelinking->down=new_node;
		//inizio ricerca right
		ricercax=new_node->x;
		ricercax++;
		ricercay=new_node->y;
		nodelinking=ricerca(ricercay, ricercax);
			new_node->right=nodelinking
			if(nodelinking!=NULL) nodelinking->left=new_node;
	}
	else if(scelta=="l"){

	}
	else if(scelta=="d"){

	}
	else {

	}
}

ptr_lista_mappa ricerca(int y, int x){ 	//funzione di ricerca di un nodo con determinate coordinate per effettuare il linknode
	ptr_tabnodipresenti p;	//dichiaro puntatore di ricerca
	p=head;		
	if(p->p_nodo->y==y && p->p_nodo->x==x){		//controllo uguaglianza del primo nodo della lista
		return p->p_nodo;		//ritorno il nodo della lista_mappa
	}
	do{		//controllo gli altri nodi della lista visitandoli uno ad uno **
		p=p->next;
			if(p->p_nodo->y==y && p->p_nodo->x==x){
			return p->p_nodo;
			}
	}while(p!=NULL);	//**finchè non avrò visitato tutti i nodi.
	return NULL;	//nesun nodo è stato trovato, quindi ritorno NULL
}


void existing_node (char scelta){
	if (scelta=="u"){ //scelta su
		player->p_pos_player=player->p_pos_player->up;		
	}
	else if(scelta=="l"){	//scelta sinistra
		player->p_pos_player=player->p_pos_player->left;
	}
	else if(scelta=="d"){	//scelta giù
		player->p_pos_player=player->p_pos_player->down;
	}
	else {	//scelta destra
		player->p_pos_player=player->p_pos_player->right;
	}
}
