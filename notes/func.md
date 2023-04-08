# Exigences fonctionnelles et Exigences non-fonctionnelles

## Exigences fonctionnelles


### Visualiser la moyenne de qualité de l'air dans une zone données durant une période donnée

#### Fonction:

Visualiser la qualité de l'air dans une zone précise dans une zone données durant une période donnée.

#### Description:

Pouvoir visualiser la qualité de l'air, c'est-à-dire l'indice de qualité de l'air, dans une zone géographique précise et pendant une période donnée.

#### Inputs:

Rentrer les coordonnées précises de la zone (Lattitude,Longitude,Radius) et la période souhaitée (d'une date "aaaa-mm-dd" à une date "aaaa-mm-dd").

#### Source:

La La base de données centralisée contenant les données des capteurs et les mesures.

#### Outputs:

L'indice de qualité de l'air.

#### Destination:

L'interface utilisateur.

#### Action:

Il faut faire une sélection des capteurs qui sont à la fois dans la zone et la période souhaitée. Si aucun capteur n'est dans le rayon, on renvoie une erreur. Ensuite, il faut pouvoir faire le calcul à partir des différentes valeurs de l'indice de qualité de l'air. Enfin, il faut l'afficher dans l'interface utilisateur.

#### Requis:

Avoir assez de données et de capteurs pour assurer une réponse cohérente à la requête.

#### Pre-condition:

L'utilisateur a tapé les coordonnées de la zone dont il souhaite avoir la qualité de l'air et la période.

#### Post-condition:

L'indice de qualité de l'air est affiché sur l'interface utilisateur.

#### Effets Secondaires:

Incrémenter le nombre de points d'un utilisateur particulier si jamais son capteur a été appelé dnas la requête.

### Visualiser la qualité de l'air en un point précis

#### Fonction:

Visualiser la qualité de l'air dans un point précis.

#### Description:

Pouvoir visualiser la qualité de l'air, c'est-à-dire l'indice de qualité de l'air, dans un point précis.

#### Inputs:

Rentrer les coordonnées précises du point (Lattitude,Longitude).

#### Source:

La La base de données centralisée contenant les données des capteurs et les mesures.

#### Outputs:

L'indice de qualité de l'air.

#### Destination:

L'interface utilisateur.

#### Action:

Il faut faire une sélection des capteurs qui sont précisèment dans le point géographique. Ensuite, il faut pouvoir faire le calcul à partir des différentes valeurs de l'indice de qualité de l'air. Enfin, il faut l'afficher dans l'interface utilisateur.

#### Requis:

Avoir assez de données et de capteurs pour assurer une réponse cohérente à la requête.

#### Pre-condition:

L'utilisateur a tapé les coordonnées du point dont il souhaite avoir la qualité de l'air.

#### Post-condition:

L'indice de qualité de l'air est affiché sur l'interface utilisateur.

#### Effets Secondaires:

Incrémenter le nombre de points d'un utilisateur particulier si jamais son capteur a été appelé dnas la requête.

### Classer les capteurs par ordre de similarité durant une période donnée

#### Fonction:

Classer les capteurs par ordre de similarité durant une période donnée.

#### Description:

Pouvoir faire un classement des différents capteurs par ordre de similarité en termes de mesures par rapport à un capteur donnée. 

#### Inputs:

"SensorID" pour avoir le capteur donnée et la période souhaitée (d'une date "aaaa-mm-dd" à une date "aaaa-mm-dd").

#### Source:

La base de données centralisée contenant les données de mesures.

#### Outputs:

Classement des capteurs par ordre de similarité. 

#### Destination:

L'interface utilisateur.

#### Action:

On met en place l'algorithme qui nous donne à partir de measurements.csv la mesure moyenne que réalise chaque capteur dans la période souhaitée. Ensuite, on classe les capteurs par ordre de similarité avec le capteur que l'utilisateur a tapé. Si on en trouve aucun on renvoie une erreur.

#### Requis:

Avoir assez de données et de capteurs pour assurer une réponse cohérente à la requête. La requête est également bien formée.

#### Pre-condition:

L'utilisateur a tapé l'ID du capteur et la période souhaitée.

#### Post-condition:

Le classement est affiché sur l'interface utilisateur.

#### Effets Secondaires:

Incrémenter le nombre de points d'un utilisateur particulier si jamais son capteur a été appelé dnas la requête.

### Afficher le profil utilisateur

#### Fonction:

Afficher le profil utilisateur.

#### Description:

Pouvoir afficher le profil de l'utilisateur, c'est-à-dire, son "UserID", ses capteurs, et son nombre de points.

#### Inputs:

"UserID" pour avoir l'utilisateur souhaité.

#### Source:

La base de données centralisée contenant les données utilisateur (avec le nombre de points).

#### Outputs:

Affichage du profil utilisateur avec le "UserID" les capteurs et le nombre de points.

#### Destination:

L'interface utilisateur.

#### Action:

Sélectionner l'utilisateur souhaité dans la base de données et afficher ses caractéristiques. Si aucun utilisateur ne correspond au "UserID" tapé, une erreur est renvoyée.

#### Requis:

Le nombre de points a été préalablement bien calculé et stocké.

#### Pre-condition:

L'utilisateur a tapé son ID.

#### Post-condition:

Le profil utilisateur est affiché sur l'interface utilisateur.

#### Effets Secondaires:

Aucun.

### Générer des points

#### Fonction:

Génerer des points.

#### Description:

Pouvoir génerer des points pour l'utilisateur dont le capteur a été appelé lors d'une requête. 

#### Inputs:

Une requête qui fait appel directement ou indirectement à un ou plusieurs capteurs utilisateurs.

#### Source:

La base de données centralisée contenant les données utilisateur.

#### Outputs:

Aucun. 

#### Destination:

La base de données centralisée contenant les données utilisateur.

#### Action:

Il faut, à chaque requête faisant appel à un capteur, vérifier si celui-ci est à un utilisateur particulier, et si c'est-le cas, incrémenter son nombre de points. On ne fait rien si ce n'est pas un capteur particulier.

#### Requis:

Un profil utilisateur déja bien formé et une base de données robuste contenant les bonnes données utilisateurs.

#### Pre-condition:

Une requête faisant appel à un capteur particulier a été formulée.

#### Post-condition:

Les points sont ajoutées au profil utilisateur du bon utilisateur associé au capteur.

#### Effets Secondaires:

Aucun.

### Visualiser l'impact des nettoyeurs sur la qualité de l'air

#### Fonction:

Visualiser l'impact des nettoyeurs sur la qualité de l'air.

#### Description:

Pouvoir visualiser l'impact des nettoyeurs sur la qualité de l'air par rapport à une date antérieure.

#### Inputs:

Le "CleanerID" du nettoyeur voulu.

#### Source:

La base de données centralisée contenant les données des nettoyeurs.

#### Outputs:

Un indice caractérisant l'impact des nettoyeurs sur la qualité de l'air.

#### Destination:

La base de données centralisée contenant les données des nettoyeurs.

#### Action:

Sélectionner dans la base de données le bon nettoyeur, prendre la position et les dates de début et de fin. Ensuite, on fait la différence de la moyenne de qualité de l'air en ce point pour les deux date. On affiche ensuite ce nombre dans l'interface utilisateur. Si le "CleanerID" 

#### Requis:

Avoir assez de données et de capteurs pour assurer une réponse cohérente à la requête.

#### Pre-condition:

L'utilisateur a tapé le "CleanerID".

#### Post-condition:

Le nombre caractérisant l'impact des nettoyeurs est affiché sur l'interface utilisateur.

#### Effets Secondaires:

Aucun.

### Voir toutes les données

#### Fonction:

Voir toutes les données.

#### Description:

Pouvoir visualiser l'ensemble des données de la La base de données centralisée.

#### Inputs:

Aucun.

#### Source:

La base de données centralisée.

#### Outputs:

L'ensemble des données est affiché en brut à l'administrateur.

#### Destination:

L'administarteur regarde les données en brut.

#### Action:

Afficher de manière brut les données de la base centralisée à l'administrateur.

#### Requis:

être administrateur.

#### Pre-condition:

L'administrateur formule la requête.

#### Post-condition:

Les données lui sont affichées en brut.

#### Effets Secondaires:

Aucun.

### Vérifier la cohérence des données venant des capteurs privés

#### Fonction:

Vérifier la cohérence des données venant des capteurs privés.

#### Description:

Pouvoir vérifier la cohérence des données venant des capteurs privés en comparaison avec les autres capteurs.

#### Inputs:

le "SensorID" du capteur souhaité.

#### Source:

La base de données centralisée contenant les données capteur.

#### Outputs:

Un indice de cohérence.

#### Destination:

L'indice est affiché dans l'interface utilisateur.

#### Action:

On commence par prendre la moyenne du capteur en question, puis on la compare à la moyenne de qualité de l'iair dans le même point géographique. On génère ainsi l'indice caractérisant la cohérence.

#### Requis:

être administrateur.

#### Pre-condition:

L'administrateur formule la requête.

#### Post-condition:

L'indice caractérisant la cohérence est affiché.

#### Effets Secondaires:

Aucun.


## Exigences non-fonctionnelles

#### Interface intuitive et compréhensible
#### Efficacité dans le stockage et l'accés aux données

#### Algorithmes efficaces et rapides

#### Fiabilité des données
#### Sécurité des données contre les comportements malicieux (à implémenter)
#### Données non-modifiables par les utilisateurs


