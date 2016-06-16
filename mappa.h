 
struct lista_mappa{
	int x; //coordinata x
	int y;	//coordinata y
	lista_mappa *left;
	lista_mappa *down;
	lista_mappa *right;
	lista_mappa *up;	
};
typedef lista_mappa* ptr_lista_mappa;  //non so se va bene nel file .hpp; se non va bene, spostare in mappa.cpp


struct tabnodipresenti{
	ptr_lista_mappa p_nodo;
	tab_pos_nodes *next;
};
typedef tabnodipresenti* ptr_tabnodipresenti;	//non so se va bene nel file .hpp; se non va bene, spostare in mappa.cpp
	ptr_tabnodipresenti head;

int global_minus_x;