# Exigences fonctionnelles et Exigences non-fonctionnelles

## Exigences fonctionnelles


### Visualiser la qualité de l'air dans une zone précise 

#### Fonction: 
    Visualiser la qualité de l'air dans une zone précise.

#### Description:
    Pouvoir visualiser la qualité de l'air, c'est-à-dire l'indice de qualité de l'air, dans une zone géographique précise.

#### Inputs:
    Rentrer les coordonnées précises (Lattitude,Longitude).

#### Source:
    Les données des fichiers csv, plus précisément sensors.csv et measurements.csv.

#### Outputs:
    L'indice de qualité de l'air.

#### Destination:
    L'interface utilisateur.

#### Action:
    Il faut pouvoir se rapprocher le plus possible des coordonnées tapées par l'utilisateurs et celles où un capteur est disponible. Ensuite il faut faire une jointure entre sensors.csv et measurements.csv sur "SensorID". Enfin, il faut afficher "value" dans l'interface utilisateur.

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


