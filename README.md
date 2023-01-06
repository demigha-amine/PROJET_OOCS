# Création de projet LinearAlgebraAPI avec C++

Ce projet sera compilé au moyen de CMake. 

Ce projet dépend d'Alien pour fonctionner. Il faudrait donc normalement compiler et installer Alien sur votre machine. Étant donné le temps imparti et la diversité de vos machines et OS, il est plus raisonnable de ne pas envisager cette étape dans un premier temps. Vous pourrez donc récupérer un simple fichier AlienMock.h qui feindra de vous donner accès aux fonctionnalités Alien nécessaires pour le projet. Ce fichier est dans le répertoire TD2/Headers. 

Ainsi ce projet sera compilable et testable avec les commandes (classiques) suivantes :

     $ cmake ..
      
     $ make
      
     $ ctest

Tous ces commandes sont dans le script Shell `script.sh`. Il faut juste le lancer avec la commande:

     $ bash TD2/script.sh



