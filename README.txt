

* Structure du projet :

.
├── res
│   └── tests
│       └── test_auto_nombre.txt
├── include
│   └── auto_nombre.h
├── doc
│   └── livrable
├── Doxyfile
├── Makefile
├── README.txt
├── auto_nombre.c
└── test_auto_nombre.c

Vos fichiers *.c, le README.txt et le Makefile seront dans le repertoire racine, vos fichiers *.h seront 
dans le repertoire "include". 

Vous rangerez votre livrable dans le repertoire "doc/livrable". 
Le repertoire "res/" contiendra toutes les ressources utilisées par le programme, c'est-à-dire vos fichiers de tests et de configuration.


* Generation de l'executable 

Tapez "make clean && make"



* Documentation du code

Si vous voulez documenter votre code, regardez la syntaxe appropriee pour 
les tags Doxygen : 

http://www.stack.nl/~dimitri/doxygen/docblocks.html

Une fois votre code commente, tapez "make documentation" (nous vous fournissons
un Doxyfile qui ira bien pour ce que vous avez a faire). 

Note : il faut avoir installe le package doxygen. Sous Ubuntu / Debian, tapez : 
sudo apt-get install doxygen



* Generation de l'archive 

Tapez "make archive". Vous aurez produit un fichier se terminant par "tgz". C'est l'archive 
que vous nous enverrez par email. 


