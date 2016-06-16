/*lista giocatori dove andranno le loro info:
 - nome, 
 - puntatore della sua posizione in nodo della mappa,
*** poi eventuali caratteristiche del gioco ***
*/

struct player{	
	ptr_lista_mappa p_pos_player;	//puntatore che punta al nodo della mappa in cui il giocatore è presente
	string nome;
//	...
	player *next;
}
typedef player* ptr_player;