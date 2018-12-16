##########################PROJET PET 2018 KOCEV/CASTILLO#################################


++++++++++++++
 COMPILATION :
++++++++++++++
Pour compiler utilisez la commande "make"

Le Makefile fourni permet de compiler different programmes :
	make partie1 
	make testDijkstra
	make pcc 

---
# partie1 : réalise le teste de la construction d'un graphe à partir de "monfichier.txt" qui est la copie de "graphe1", seul le nom change
---
# testDijkstra : petit programme de l'exécution de Dijkstra en test
---
# make pcc : programme final, pour modifier le fichier .csv/.txt courant il faut rentrer dans le code source et modifier 
			 le chemin d'acces (filename) dans la fonction GRAPH lectureFichier(FILE *filename, int *nbrs, int *nbra).
---

++++++++++++++++++++++++
 lancer les programmes
++++++++++++++++++++++++

Pour lancer les programmes executez les commandes shell  ./partie1   ./testDijkstra   ./pcc
