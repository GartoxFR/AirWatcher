# Exigences fonctionnelles et Exigences non-fonctionnelles

## Exigences fonctionnelles


### Visualiser la moyenne de qualité de l'air dans une zone données durant une période donnée

#### Fonction:
 
Visualiser la qualité de l'air dans une zone précise dans une zone données durant une période donnée.

#### Description:

Pouvoir visualiser la qualité de l'air, c'est-à-dire l'indice de qualité de l'air, dans une zone géographique précise et pendant une période donnée.

#### Inputs:

Rentrer les coordonnées précises de la zone (Lattitude,Longitude,Radius) et la période souhaitée (from aaaa-mm-dd to aaaa-mm-dd).

#### Source:

Les données des fichiers csv, plus précisément sensors.csv et measurements.csv.

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

Aucun.

### Classer les capteurs par ordre de similiarité durant une période donnée

#### Fonction:
 
Classer les capteurs par ordre de similarité durant une période donnée.

#### Description:

Pouvoir faire un classement des différents capteurs par ordre de similarité en termes de mesures par rapport à un capteur donnée. 

#### Inputs:

"SensorID" pour avoir le capteur donnée et la période souhaitée (from aaaa-mm-dd to aaaa-mm-dd).

#### Source:

Les données des fichiers csv, plus précisément sensors.csv et measurements.csv.

#### Outputs:

Classement des capteurs par ordre de similarité. 

#### Destination:

L'interface utilisateur.

#### Action:

On met en place l'algorithme qui nous donne à partir de measurements.csv la mesure moyenne que réalise chaque capteur dans la période souhaitée. Ensuite, on classe les capteurs par 

#### Requis:

Avoir assez de données et de capteurs pour assurer une réponse cohérente à la requête.

#### Pre-condition:

L'utilisateur a tapé les coordonnées de la zone dont il souhaiteavoir la qualité de l'air.

#### Post-condition:

L'indice de qualité de l'air est affiché sur l'interface utilisateur

#### Effets Secondaires:

Aucun.



## Exigences non-fonctionnelles

#### Interface intuitive et compréhensible
#### Efficacité dans le stockage et l'accés aux données

#### Algorithmes efficaces et rapides

#### Fiabilité des données
#### Sécurité des données contre les comportements malicieux (à implémenter)
#### Données non-modifiables par les utilisateurs


