##### TP Génie Logiciel

# Document des exigences de spécification
##### Théo CHONE - Ewan CHORYNSKI - Florian DELHON - Zyad HADDAD

## Introduction

### Contexte
L'objectif de ce TP est d'appliquer le cours de génie logiciel pour développer une application. Cette application, appelée AirWatcher, fournit à l'agence gouvernementale de protection de l'environnement un outil de monitoring pour leurs capteurs de qualité de l'air, dispersés sur le territoire. A travers les différentes séances de TP, notre équipe aura à spécifier les différentes exigences, concevoir l'architecture de l'application, et implémenter quelques fonctionnalités de l'application.

### Equipe
Notre équipe est composée de Théo CHONE, Ewan CHORYNSKI, Florian DELHON and Zyad HADDAD. Pour organiser notre travail, on utilisera un dossier GitHub. Nous nous sommes donnés différents rôles : Florian sera le chef de projet, Théo sera le responsable des tests et de la qualité, Zyad sera le responsable en analyse de données, et Ewan sera le développeur en chef.

### Diagramme de Gantt

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

Base de données centralisée contenant les données capteur et mesures.

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

Base de données centralisée contenant les données capteur et mesures.

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

### Classer les capteurs par ordre de similiarité durant une période donnée

#### Fonction:

Classer les capteurs par ordre de similarité durant une période donnée.

#### Description:

Pouvoir faire un classement des différents capteurs par ordre de similarité en termes de mesures par rapport à un capteur donnée. 

#### Inputs:

"SensorID" pour avoir le capteur donnée et la période souhaitée (from aaaa-mm-dd to aaaa-mm-dd).

#### Source:

Base de données centralisée contenant les données de mesures.

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

Base de données centralisée contenant les données utilisateur (avec le nombre de points).

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

Base de données centralisée contenant les données utilisateur.

#### Outputs:

Aucun. 

#### Destination:

Base de données centralisée contenant les données utilisateur.

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

Base de données centralisée contenant les données des nettoyeurs.

#### Outputs:

Un indice caractérisant l'impact des nettoyeurs sur la qualité de l'air.

#### Destination:

Base de données centralisée contenant les données des nettoyeurs.

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

Pouvoir visualiser l'ensemble des données de la base de données centralisée.

#### Inputs:

Aucun.

#### Source:

Base de données centralisée.

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

Base de données centralisée contenant les données capteur.

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

## Analyse des risques de sécurité

### Contexte
AirWatcher stocke des données sensibles à propos des éléments suivants : les capteurs, les nettoyeurs d'air, les mesures de qualité de l'air, les utilisateurs participant à la collecte de données. Ces différentes données peuvent donc intéresser des personnes malveillantes. En effet, le vol de capteurs ou de nettoyeurs d'air, ou encore l'accès à des mesures sensibles peuvent motiver des attaques.

### Objectifs
<table>
    <thead>
    <tr>
        <th>Objectif</th>
        <th>Description</th>
    </tr>
    </thead>
    <tbody>
        <tr>
            <td>Confidentialité
            </td>
            <td>Protéger le stockage des données (capteurs, qualité de l'air, nettoyeurs d'air, utilisateurs particuliers) d'un accès tiers non autorisé.
            </td>
        </tr>
        <tr>
            <td>Intégrité
            </td>
            <td>Empêcher les mesures de qualité de l'air d'être modifiées, ce qui pourraient entraîner un faussement d'indicateurs comme la fiabilité des capteurs par exemple.
            </td>
        </tr>
        <tr>
            <td>Disponibilité
            </td>
            <td>S'assurer que l'acquisition des données ainsi que la consultation de celles-ci soient effectuées en continu, sans <i>Denial of Service</i> (DoS).
            </td>
        </tr>
        <tr>
            <td>Authentification
            </td>
            <td>S'assurer que l'utilisateur peut se connecter de manière sûre et sécurisée, pour accéder aux fonctionnalités de l'application correspondant à son rôle.
            </td>
        </tr>
        <tr>
            <td>Non-répudiation
            </td>
            <td>S'assurer que les données (et notamment les mesures) ont bien pu être transmises de bout en bout, que ce soit entre les capteurs et la base de données centralisée, ou entre la base de données et l'application.
            </td>
        </tr>
    </tbody>
</table>

### Analyse
<table>
    <thead>
    <tr>
        <th>Atout</th>
        <th>Vulnérabilité</th>
        <th>Attaque</th>
        <th>Risque</th>
        <th>Impact</th>
        <th>Contre-mesure</th>
    </tr>
    </thead>
    <tbody>
        <tr>
            <td>Stockage des données (mesures des capteurs, données utilisateur, …)
            </td>
            <td>> Stockage sans chiffrement
            </td>
            <td>> Déchiffrement et obtention des données stockées
            </td>
            <td>    > Accès aux mesures de qualité de l’air</br>
                    > Corruption des données (insertion de fausses données, …)</br>
                    > Accès aux données des utilisateurs</br>
                    > Corruption des points obtenus par l’utilisateur</br>
                    > Accès à la localisation des capteurs, privés ou publics
            </td>
            <td>    > Elevé</br>
                    > Elevé</br>
                    > Elevé</br>
                    > Moyen</br>
                    > Elevé
            </td>
            <td>> Chiffrement du stockage</td>
        </tr>
        <tr>
            <td>Transmission des données (mesures des capteurs, données utilisateur)
            </td>
            <td>> Transmission sans chiffrement
            </td>
            <td>> Interception de la communication
            </td>
            <td>    > Accès aux mesures de qualité de l’air</br>
                    > Accès aux données des utilisateurs</br>
                    > Accès à la localisation des capteurs, privés ou publics
            </td>
            <td>    > Elevé</br>
                    > Elevé</br>
                    > Elevé
            </td>
            <td>> Chiffrement de la tranmission</td>
        </tr>
        <tr>
            <td>Consultation des données sur l'application <i>AirWatcher</i>
            </td>
            <td>> Authentification faible (nom d'utilisateur, mot de passe, ...)
            </td>
            <td>> Authentification devinée par l'attaquant
            </td>
            <td>    > Accès aux mesures de qualité de l’air</br>
                    > Corruption des données (insertion de fausses données, …)</br>
                    > Accès aux données des utilisateurs</br>
                    > Corruption des points obtenus par l’utilisateur</br>
                    > Accès à la localisation des capteurs, privés ou publics
            </td>
            <td>    > Elevé</br>
                    > Elevé</br>
                    > Elevé</br>
                    > Moyen</br>
                    > Elevé
            </td>
            <td>> Vérifications de la robustesse de l'authentification (mot de passe)</td>
        </tr>
    </tbody>
</table>

## Tests de validation

## Manuel utilisateur

### Démarrage
L'application AirWatcher possède une interface entièrement sur la console. Lorsque l'utilisateur démarre l'application, il arrive sur un premier menu où il choisit son rôle. Ce menu comporte 4 options :
- Utilisateur particulier,
- Fournisseur,
- Gouvernement,
- Administrateur système.

Une fois qu'il a choisi son rôle, l'utilisateur choisit qui il est, parmi les différentes personnes inscrites. On note que la phase d'authentification n'est pas demandée dans le cadre de ce projet. En fonction du rôle de la personne, l'utilisateur accède au menu correspondant.

### Utilisateur particulier
Le menu est le suivant :
- 1 = Afficher le profil utilisateur
- 2 = Voir toutes les données
- 3 = Visualiser la qualité de l'air dans une zone précise
- 4 = Visualiser les capteurs similaires à un capteur précis

### Fournisseur
Le menu est le suivant :
- 1 = Visualiser l'impact des nettoyeurs sur la qualité de l'air
- 2 = Visualiser la qualité de l'air dans une zone précise
- 3 = Voir toutes les données

### Gouvernement
Le menu est le suivant :
- 1 = Visualiser l'impact des nettoyeurs sur la qualité de l'air
- 2 = Visualiser la qualité de l'air dans une zone précise
- 3 = Voir toutes les données
- 4 = Visualiser les capteurs similaires à un capteur précis

### Administrateur système
Le menu est le suivant :
- 1 = Vérifier la cohérence des données venant des capteurs privés
- 2 = Marquer un capteur comme défectueux
- 3 = Visualiser la qualité de l'air dans une zone précise
- 4 = Voir toutes les données
