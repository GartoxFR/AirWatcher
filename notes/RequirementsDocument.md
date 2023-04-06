##### TP Génie Logiciel

# Document des exigences de spécification
##### Théo CHONE - Ewan CHORYNSKI - Florian DELHON - Zyad HADDAD

## Introduction

### Contexte
L'objectif de ce TP est d'appliquer le cours de génie logiciel pour développer une application. Cette application, appelée AirWatcher, fournit à l'agence gouvernementale de protection de l'environnement un outil de monitoring pour leurs capteurs de qualité de l'air, dispersés sur le territoire. A travers les différentes séances de TP, notre équipe aura à spécifier les différentes exigences, concevoir l'architecture de l'application, et implémenter quelques fonctionnalités de l'application.

### Equipe
Notre équipe est composée de Théo CHONE, Ewan CHORYNSKI, Florian DELHON and Zyad HADDAD. Pour organiser notre travail, on utilisera un dossier GitHub. Nous nous sommes donnés différents rôles : Florian sera le chef de projet, Théo sera le responsable des tests et de la qualité, Zyad sera le responsable en analyse de données, et Ewan sera le développeur en chef.

### Diagramme de Gantt

## Exigences fonctionnelles et non-fonctionnelles du système

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
