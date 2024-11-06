# Jeu-de-carte
Projet d'un jeu de carte

Afin de lancer ce programme tout les fichier sont nécésaire dans un même dossier.
Vous devez également avoir installez MYSQL ainsi que les connecteur MYSQL sur votre ordinateur.
Vous allez ensuite devoir utiliser cette commande qui va utiliser le fichier.sql afin de transféré ma base de données:

mysql -u ton_utilisateur -p nom_de_la_base_de_donnees < /chemin/vers/votre/fichier.sql

Une fois cela fait vous pouvez compiler le programme avec la commande:

g++ -o game main.cpp Pdb.cpp SnowQueen.cpp Berserker.cpp -lmysqlclient -lmysqlcppconn

Une fois cela fait lancer le programme avec ./game
