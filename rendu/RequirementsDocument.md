---
title: "Document des exigences de spécification"
titlepage: true
author: ["CHONE Théo", "CHORYNSKI Ewan", "DELHON Florian", "HADDAD Zyad"]
table-use-row-colors: true
caption-justification: centering
fontsize: 8pt
header-includes:
- |
  ```{=latex}
  \usepackage{pdflscape}
  \newcommand{\blandscape}{\begin{landscape}}
  \newcommand{\elandscape}{\end{landscape}}
    ```
---

# Diagramme de cas d'usage

![Diagramme de cas d'usage](img/usecase.png)

# Exigences fonctionnelles et Exigences non-fonctionnelles

## Exigences fonctionnelles


### Visualiser la moyenne de qualité de l'air dans une zone donnée durant une période donnée

**Fonction :**
Visualiser la qualité de l'air dans une zone précise dans une zone donnée durant une période donnée.

**Description:**
Pouvoir visualiser la qualité de l'air, c'est-à-dire l'indice de qualité de l'air, dans une zone géographique précise et pendant une période donnée.

**Inputs :**
Rentrer les coordonnées précises de la zone (latitude, longitude, radius) et la période souhaitée (d'une date "aaaa-mm-dd hh:mm:ss" à une date "aaaa-mm-dd hh:mm:ss").

**Source :**
La base de données centralisée contenant les données des capteurs et les mesures.

**Outputs :**
L'indice de qualité de l'air.

**Destination :**
L'interface utilisateur.

**Action :**
Il faut faire une sélection des capteurs qui sont à la fois dans la zone et la période souhaitées. Si aucun capteur n'est dans le rayon, on renvoie une erreur. Ensuite, il faut pouvoir faire le calcul à partir des différentes valeurs de l'indice de qualité de l'air. Enfin, il faut l'afficher dans l'interface utilisateur.

**Requis :**
Avoir assez de données et de capteurs pour assurer une réponse cohérente à la requête.

**Pre-condition :**
L'utilisateur a tapé les coordonnées de la zone dont il souhaite avoir la qualité de l'air et la période.

**Post-condition :**
L'indice de qualité de l'air est affiché sur l'interface utilisateur.

**Effets Secondaires :**
Incrémenter le nombre de points d'un utilisateur particulier si jamais son capteur a été appelé dans la requête.

---

### Visualiser la qualité de l'air en un point précis

**Fonction :**
Visualiser la qualité de l'air en un point précis.

**Description :**
Pouvoir visualiser la qualité de l'air, c'est-à-dire l'indice de qualité de l'air, en un point précis.

**Inputs :**
Rentrer les coordonnées précises du point (latitude, longitude).

**Source :**
La base de données centralisée contenant les données des capteurs et les mesures.

**Outputs :**
L'indice de qualité de l'air.

**Destination :**
L'interface utilisateur.

**Action :**
Il faut faire une sélection des capteurs qui sont précisèment dans le point géographique. Ensuite, il faut pouvoir faire le calcul à partir des différentes valeurs de l'indice de qualité de l'air. Enfin, il faut l'afficher dans l'interface utilisateur.

**Requis :**
Avoir assez de données et de capteurs pour assurer une réponse cohérente à la requête.

**Pre-condition :**
L'utilisateur a tapé les coordonnées du point dont il souhaite avoir la qualité de l'air.

**Post-condition :**
L'indice de qualité de l'air est affiché sur l'interface utilisateur.

**Effets Secondaires :**
Incrémenter le nombre de points d'un utilisateur particulier si jamais son capteur a été appelé dans la requête.

---

### Classer les capteurs par ordre de similarité durant une période donnée

**Fonction :**
Classer les capteurs par ordre de similarité durant une période donnée.

**Description :**
Pouvoir faire un classement des différents capteurs par ordre de similarité en termes de mesures de qualité de l'air par rapport à un capteur donnée. 

**Inputs :**
Le "SensorID" pour avoir le capteur donnée et la période souhaitée (d'une date "aaaa-mm- hh:mm:ss" à une date "aaaa-mm-dd hh:mm:ss").

**Source :**
La base de données centralisée contenant les données de mesures.

**Outputs :**
Un classement des capteurs par ordre de similarité. 

**Destination :**
L'interface utilisateur.

**Action :**
On met en place l'algorithme qui nous donne à partir des données de mesure la mesure moyenne que réalise chaque capteur dans la période souhaitée. Ensuite, on classe les capteurs par ordre de similarité avec le capteur que l'utilisateur a tapé. Si on n'en trouve aucun on renvoie une erreur.

**Requis :**
Avoir assez de données et de capteurs pour assurer une réponse cohérente à la requête. La requête doit également être bien formée.

**Pre-condition :**
L'utilisateur a tapé l'ID du capteur et la période souhaitée.

**Post-condition :**
Le classement est affiché sur l'interface utilisateur.

**Effets Secondaires :**
Incrémenter le nombre de points d'un utilisateur particulier si jamais son capteur a été appelé dnas la requête.

---

### Afficher le profil utilisateur

**Fonction :**
Afficher le profil utilisateur.

**Description :**
Pouvoir afficher le profil de l'utilisateur, c'est-à-dire, son "UserID", ses capteurs, et son nombre de points.

**Inputs :**
Le "UserID" pour avoir l'utilisateur souhaité.

**Source :**
La base de données centralisée contenant les données des utilisateurs (avec le nombre de points notamment).

**Outputs :**
Un affichage du profil utilisateur avec le "UserID", les capteurs et le nombre de points.

**Destination :**
L'interface utilisateur.

**Action :**
Sélectionner l'utilisateur souhaité dans la base de données et afficher ses caractéristiques. Si aucun utilisateur ne correspond au "UserID" tapé, une erreur est renvoyée.

**Requis :**
Le nombre de points a été préalablement bien calculé et stocké.

**Pre-condition :**
L'utilisateur a tapé son ID.

**Post-condition :**
Le profil utilisateur est affiché sur l'interface utilisateur.

**Effets Secondaires :**
Aucun.

---

### Générer des points

**Fonction :**
Génerer des points.

**Description :**
Pouvoir génerer des points pour l'utilisateur dont le capteur a été appelé lors d'une requête. 

**Inputs :**
Une requête qui fait appel directement ou indirectement à un ou plusieurs capteurs de cet utilisateur particulier.

**Source :**
La base de données centralisée contenant les données des utilisateurs.

**Outputs :**
Aucun. 

**Destination :**
La base de données centralisée contenant les données utilisateur.

**Action :**
Il faut, à chaque requête faisant appel à un capteur, vérifier si celui-ci est à un utilisateur particulier, et si c'est-le cas, incrémenter son nombre de points. On ne fait rien si ce n'est pas un capteur particulier.

**Requis :**
Un profil utilisateur déja bien formé et une base de données robuste contenant les bonnes données utilisateurs.

**Pre-condition :**
Une requête faisant appel à un capteur particulier a été formulée.

**Post-condition :**
Les points sont ajoutés au profil utilisateur du bon utilisateur associé au capteur.

**Effets Secondaires :**
Aucun.

---

### Visualiser l'impact des nettoyeurs sur la qualité de l'air

**Fonction :**
Visualiser l'impact des nettoyeurs sur la qualité de l'air.

**Description :**
Pouvoir visualiser l'impact des nettoyeurs sur la qualité de l'air par rapport à une date antérieure.

**Inputs :**
Le "CleanerID" du nettoyeur voulu.

**Source :**
La base de données centralisée contenant les données des nettoyeurs.

**Outputs :**
Un indice caractérisant l'impact des nettoyeurs sur la qualité de l'air.

**Destination :**
La base de données centralisée contenant les données des nettoyeurs.

**Action :**
Sélectionner dans la base de données le bon nettoyeur, prendre la position et les dates de début et de fin. Ensuite, on fait la différence de la moyenne de qualité de l'air en ce point pour les deux dates. On affiche ensuite ce nombre dans l'interface utilisateur.

**Requis :**
Avoir assez de données et de capteurs pour assurer une réponse cohérente à la requête.

**Pre-condition :**
L'utilisateur a tapé le "CleanerID".

**Post-condition :**
Le nombre caractérisant l'impact des nettoyeurs est affiché sur l'interface utilisateur.

**Effets Secondaires :**
Aucun.

---

### Voir toutes les données

**Fonction :**
Voir toutes les données.

**Description :**
Pouvoir récupérer l'ensemble des données de la base de données centralisée.

**Inputs :**
Aucun.

**Source :**
La base de données centralisée.

**Outputs :**
L'ensemble des données est affiché en brut à l'administrateur.

**Destination :**
L'administrateur regarde les données en brut.

**Action :**
Afficher de manière brute les données de la base centralisée à l'utilisateur.

**Requis :**
Aucun

**Pre-condition :**
L'utilisateur formule la requête.

**Post-condition :**
Les données lui sont affichées en brut.

**Effets Secondaires :**
Aucun.

---

### Vérifier la cohérence des données venant des capteurs privés

**Fonction :**
Vérifier la cohérence des données venant des capteurs privés.

**Description :**
Pouvoir vérifier la cohérence des données venant des capteurs privés en comparaison avec les autres capteurs.

**Inputs :**
Aucun

**Source :**
La base de données centralisée contenant les données des capteurs.

**Outputs :**
Un indice de cohérence pour tous les capteurs privés qui ne sont pas déjà masqués.

**Destination :**
Les capteurs les moins cohérents sont affichés.

**Action :**
Pour chaque capteur, on commence par prendre la moyenne ce capteur, puis on la
compare à la moyenne de qualité de l'air dans le même point géographique. On
génère ainsi l'indice caractérisant la cohérence.

**Requis :**
Être administrateur.

**Pre-condition :**
L'administrateur formule la requête.

**Post-condition :**
L'indice caractérisant la cohérence est affiché.

**Effets Secondaires :**
Aucun.

---

### Marquer un capteur comme défectueux

**Fonction :**
Marquer un capteur comme défectueux.

**Description :**
Pouvoir marquer un capteur comme défectueux.

**Inputs :**
Le "SensorID" du capteur en question.

**Source :**
La base de données centralisée contenant la liste des capteurs.

**Outputs :**
Aucun.

**Destination :**
La base de données contenant la liste des capteurs (modifiée par le marquage défectueux d'un capteur).

**Action :**
Marquer un capteur comme étant défectueux, et ne plus prendre en compte les mesures qui lui sont associées.

**Requis :**
Être administrateur.

**Pre-condition :**
L'administrateur formule la requête de marquage comme défectueux.

**Post-condition :**
Aucune.

**Effets Secondaires :**
Aucun.

## Exigences non-fonctionnelles

- Interface intuitive et compréhensible
- Efficacité dans le stockage et l'accés aux données
- Algorithmes efficaces et rapides (autour de la seconde)
- Fiabilité des données
- Sécurité des données contre les comportements malicieux (à implémenter)
- Données non-modifiables par les utilisateurs

# Analyse des risques de sécurité

## Contexte

AirWatcher stocke des données sensibles à propos des éléments suivants : les capteurs, les nettoyeurs d'air, les mesures de qualité de l'air, les utilisateurs participant à la collecte de données. Ces différentes données peuvent donc intéresser des personnes malveillantes. En effet, le vol de capteurs ou de nettoyeurs d'air, ou encore l'accès à des mesures sensibles peuvent motiver des attaques.

\newpage

## Objectifs

<table>
    <caption>Objectifs</caption>
    <colgroup>
        <col width="25%">
        <col width="75%">
    </colgroup>
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
            <td>Protéger le stockage des données (capteurs, qualité de l'air,
            nettoyeurs d'air, utilisateurs particuliers) d'un accès tiers non
            autorisé.
            </td>
        </tr>
        <tr>
            <td>Intégrité
            </td>
            <td>Empêcher les mesures de qualité de l'air d'être modifiées, ce
            qui pourraient entraîner un faussement d'indicateurs comme la
            fiabilité des capteurs par exemple.
            </td>
        </tr>
        <tr>
            <td>Disponibilité
            </td>
            <td>S'assurer que l'acquisition des données ainsi que la
            consultation de celles-ci soient effectuées en continu, sans
            <i>Denial of Service</i> (DoS).
            </td>
        </tr>
        <tr>
            <td>Authentification
            </td>
            <td>S'assurer que l'utilisateur peut se connecter de manière sûre
            et sécurisée, pour accéder aux fonctionnalités de l'application
            correspondant à son rôle.
            </td>
        </tr>
        <tr>
            <td>Non-répudiation
            </td>
            <td>S'assurer que les données (et notamment les mesures) ont bien
            pu être transmises de bout en bout, que ce soit entre les capteurs
            et la base de données centralisée, ou entre la base de données
            et l'application.
            </td>
        </tr>
    </tbody>
</table>

\blandscape

## Analyse


<table>
    <caption>Analyse</caption>
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
            <td>    > Accès aux mesures de qualité de l’air<br/>
                    > Corruption des données (insertion de fausses données, …)<br/>
                    > Accès aux données des utilisateurs<br/>
                    > Corruption des points obtenus par l’utilisateur<br/>
                    > Accès à la localisation des capteurs, privés ou publics
            </td>
            <td>    > Elevé<br/>
                    > Elevé<br/>
                    > Elevé<br/>
                    > Moyen<br/>
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
            <td>    > Accès aux mesures de qualité de l’air<br/>
                    > Accès aux données des utilisateurs<br/>
                    > Accès à la localisation des capteurs, privés ou publics
            </td>
            <td>    > Elevé<br/>
                    > Elevé<br/>
                    > Elevé
            </td>
            <td>> Chiffrement de la transmission</td>
        </tr>
        <tr>
            <td>Consultation des données sur l'application <i>AirWatcher</i>
            </td>
            <td>> Authentification faible (nom d'utilisateur, mot de passe, ...)
            </td>
            <td>> Authentification devinée par l'attaquant
            </td>
            <td>    > Accès aux mesures de qualité de l’air<br/>
                    > Corruption des données (insertion de fausses données, …)<br/>
                    > Accès aux données des utilisateurs<br/>
                    > Corruption des points obtenus par l’utilisateur<br/>
                    > Accès à la localisation des capteurs, privés ou publics
            </td>
            <td>    > Elevé<br/>
                    > Elevé<br/>
                    > Elevé<br/>
                    > Moyen<br/>
                    > Elevé
            </td>
            <td>> Vérifications de la robustesse de l'authentification (mot de passe)</td>
        </tr>
    </tbody>
</table>

\elandscape

# Tests de validation

## Visualiser la moyenne de qualité de l'air dans une zone donnée durant une période donnée

### Cas de fonctionnement normal

- Choisir un jeu de données assez simple pour lequel on connait la qualité de l'air dans une certaine zone durant une certaine période
- Charger ce jeu de données et appeler la fonction pour la zone connue
- Comparer le résultat avec le résultat attendu
- Choisir un utilisateur dont on sait a priori que son capteur va être utilisé et vérifier qu'il a reçu des points

### Cas d'erreur

- Choisir un jeu de données assez simple dans lequel on connait une zone sans mesure
- Charger ce jeu de données et appeler la fonction pour la zone connue
- Vérifier que la fonction renvoie bien une erreur

## Visualiser la qualité de l'air en un point précis

### Cas de fonctionnement normal

- Choisir un jeu de données assez simple pour lequel on connait la qualité de l'air en un point précis
- Charger ce jeu de données et appeler la fonction pour le point connu
- Comparer le résultat avec le résultat attendu
- Choisir un utilisateur dont on sait a priori que son capteur va être utilisé et vérifier qu'il a reçu des points

## Classer les capteurs par ordre de similarité durant une période donnée

### Cas de fonctionnement normal

- Choisir un jeu de données assez simple pour lequel on connait la similarité de tous les capteurs par rapport à un capteur donné
- Charger ce jeu de données et appeler la fonction sur le capteur connu 
- Comparer le résultat avec le résultat attendu
- Choisir un utilisateur dont on sait a priori que son capteur va être utilisé et vérifier qu'il a reçu des points

## Afficher le profil utilisateur

### Cas de fonctionnement normal

- Choisir un utilisateur dans le jeu de données
- Appeler la fonction récupérant ses données
- Comparer le résultat avec le résultat attendu

### Cas d'erreur 

- Choisir un utilisateur n'existant pas
- Appeler la fonction récupérant ses données
- Vérifier qu'une erreur est bien retournée

## Visualiser l'impact des nettoyeurs sur la qualité de l'air

### Cas de nettoyeur ayant un impact

- Choisir un jeu de données simple où l'on connait un nettoyeur efficace sur une période donnée
- Appeler la fonction mesurant son impact
- Vérifier que le logiciel arrive au même résultat
- Choisir un utilisateur dont on sait a priori que son capteur va être utilisé et vérifier qu'il a reçu des points

### Cas de nettoyeur sans impact

- Choisir un jeu de données simple où l'on connait un nettoyeur inefficace sur une période donnée
- Appeler la fonction mesurant son impact
- Vérifier que le logiciel arrive au même résultat
- Choisir un utilisateur dont on sait a priori que son capteur va être utilisé et vérifier qu'il a reçu des points

## Vérifier la cohérence des données venant des capteurs privés

### Cas où il existe un capteur défectueux

- Choisir un jeu de données comportant un capteur que l'on a déjà identifié comme incohérent
- Appeler la fonction cherchant les capteurs défectueux
- Vérifier que le capteur incohérent est bien retourné

### Cas où il n'y a pas de capteur défectueux

- Choisir un jeu de données ne comportant pas de capteur incohérent
- Appeler la fonction cherchant les capteurs défectueux
- Vérifier qu'aucun capteur n'est retourné

## Marquer un capteur comme défectueux

### Cas normal

- Choisir un jeu ou il n'y a qu'un seul capteur dans une zone donnée
- Afficher la qualité de l'air dans cette zone
- Vérifier qu'une valeur est bien donnée
- Marquer le seul capteur de la zone comme défectueux
- Afficher de nouveau la qualité de l'air dans la zone
- Vérifier qu'une erreur est retournée car aucun capteur dans la zone

# Manuel utilisateur

## Démarrage

L'application AirWatcher possède une interface entièrement sur la console. Lorsque l'utilisateur démarre l'application, il arrive sur un premier menu où il choisit son rôle. Ce menu comporte 4 options :

- Utilisateur particulier,
- Fournisseur,
- Gouvernement,
- Administrateur système.

Une fois qu'il a choisi son rôle, l'utilisateur choisit qui il est, parmi les différentes personnes inscrites. On note que la phase d'authentification n'est pas demandée dans le cadre de ce projet. Si on devait prendre en compte cette phase d'authentification, on aurait un premier menu composé de deux options (1 = Connexion, 2 = Inscription), qui auraient amené sur une invite de saisie des données de l'utilisateur (login, mot de passe, etc). En fonction du rôle de la personne, l'utilisateur accède au menu correspondant.

## Utilisateur particulier

Le menu est le suivant :

- 1 = Afficher le profil utilisateur
- 2 = Voir toutes les données
- 3 = Visualiser la qualité de l'air dans une zone précise
- 4 = Visualiser les capteurs similaires à un capteur précis

## Fournisseur

Le menu est le suivant :

- 1 = Visualiser l'impact des nettoyeurs sur la qualité de l'air
- 2 = Visualiser la qualité de l'air dans une zone précise
- 3 = Voir toutes les données

## Gouvernement

Le menu est le suivant :

- 1 = Visualiser l'impact des nettoyeurs sur la qualité de l'air
- 2 = Visualiser la qualité de l'air dans une zone précise
- 3 = Voir toutes les données
- 4 = Visualiser les capteurs similaires à un capteur précis

## Administrateur système

Le menu est le suivant :

- 1 = Vérifier la cohérence des données venant des capteurs privés
- 2 = Marquer un capteur comme défectueux
- 3 = Visualiser la qualité de l'air dans une zone précise
- 4 = Voir toutes les données

## Fonctionnalités

En fonction de la fonctionnalité choisie, l'utilisateur pourra effectuer les actions suivantes :

- Afficher le profil utilisateur : les différents éléments du profil de l'utilisateur (points, capteurs, etc) sont affichés sur la console.
- Voir toutes les données : à travers un sous-menu, l'utilisateur peut choisir soit 1) de voir toutes les mesures brutes, 2) de voir les mesures associées à un capteur, 3) de voir les mesures associées à un gaz particulier, 4) de voir les mesures situées entre deux dates.
- Visualiser la qualité de l'air dans une zone précise : l'utilisateur peut alors saisir une localisation (latitude, longitude) et ensuite voir affiché sur la console l'indice de qualité de l'air calculé par l'application.
- Visualiser les capteurs similaires à un capteur précis : l'utilisateur peut alors saisir le "SensorID" du capteur en question ainsi que la période d'étude (dates de début et de fin) et ensuite voir affiché un classement des capteurs les plus similaires à ce dernier, sur la période renseignée.
- Visualiser l'impact des nettoyeurs sur la qualité de l'air : l'utilisateur peut alors saisir le "CleanerID" du nettoyeur en question et ensuite voir affiché sur la console l'évolution de la qualité de l'air depuis son installation (cf. exigences fonctionnelles).
- Vérifier la cohérence des données venant des capteurs privés : l'utilisateur peut alors voir affiché sur la console la liste des capteurs privés aux mesures jugées incohérentes par l'application (cf. exigences fonctionnelles).
- Marquer un capteur comme défectueux : l'utilisateur peut alors saisir le "SensorID" du capteur en question pour le marquer comme défectueux.
