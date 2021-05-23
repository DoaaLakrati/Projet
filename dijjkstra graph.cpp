#include<iostream>
using namespace std;

int sommet, src,chemin[100][100];
int dist[100];
bool visite[100]={0};
int parent[100];
void init()
{

	
	  for( int i=0 ; i<sommet ; i++){
	  	parent[i]=i;
	  	dist[i]=999;
	  }
	  dist[src]=0;
}
int getPlusProche(){
	int minvaleur=999;
	int minnoeud=0;
	for(int i=0 ; i<sommet ; i++){
		if(!visite[i]&&dist[i]<minvaleur){
			minvaleur=dist[i];
			minnoeud=i;
		}
	}
	return minnoeud;
}
 void dijkstra(){
 	int PlusProche,adj;
 	for(int i=0 ; i<sommet ; i++){
 		PlusProche=getPlusProche();
 		visite[PlusProche]=true;
 		for(adj=0 ; adj<sommet ; adj++){
 			if(chemin[PlusProche][adj]!=999&&dist[adj]>dist[PlusProche]+chemin[PlusProche][adj]){
 				dist[adj]=dist[PlusProche]+chemin[PlusProche][adj];
 				parent[adj]=PlusProche;
			 }
		 }
	 }
 }
void Affichage()
{
	int i,parnoeud;
	cout<<"Noeud : \t\t\t Chemin : \t\t\t Parcours:\n ";
	for(i=0 ; i<sommet; i++){
		cout<<i<<"\t\t\t"<<dist[i]<<"\t\t\t"<<" ";
		cout<<i<<" ";
		parnoeud=parent[i];
		while(parnoeud!=src){
			cout<<"<--"<<parnoeud<<" ";
			parnoeud=parent[parnoeud];
		}
		cout<<endl;
	}
}
int main(void){
	
	int i,j;
	cout<<"*******************************************   Algorithme de dijksra   *************************************************" <<endl;
	cout<<"\n\n\n\n";
	
	cout<<"Qu'elle est le nombre de sommets de votre graphe : "<<endl;
	cin>>sommet;
	cout<<"\n\n";
	cout<<"***saisie de la matrice des distances*** \n"<<endl;
	cout<< "veuillez respecter ces consignes lors de remplissage de votre matrice :"<<endl;
	
	
	cout<<" 1- saisir les distanses ente les noeuds."<<endl;
	cout<<" 2- saisir 999 en cas d'absence de distance directe entre deux noeuds differents."<<endl;
	cout<<" 3- saisir la valeur 0 pour la distance entre le meme noeud par exemple le cas du chemin[0][0] ou bien chemin[1][1] .... "<<endl;
	
	
	for(i=0 ; i<sommet ; i++){
	     	for(j=0 ; j<sommet ; j++){
	     		cout<<"chemin["<<i<<"]["<<j<<"] =  ";
	     		cin>>chemin[i][j];
			}	 
	}
	cout<<"donnez la source : ";
	cin>>src;
	cout <<"\n\n";
	cout<<"*************************************************  Resultat  ********************************************************* \n\n "<<endl;
	init();
	dijkstra();
	Affichage();
return 0;	
}


