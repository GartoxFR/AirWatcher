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

### Analyse
<table>
    <thead>
        <th>Atout</th>
        <th>Vulnérabilité</th>
        <th>Attaque</th>
        <th>Risque</th>
        <th>Contre-mesure</th>
    </thead>
    <tbody>
        <tr>
            <td>Les données des utilisateurs (mesures par leurs capteurs, points) sont stockées dans la base de données.
            </td>
            <td>
                <ul>
                    <li>Les mots de passe faibles sont permis.</li>
                    <li>La transmission et le stockage de données peuvent être faits sans chiffrement.</li>
                </ul>
            </td>
            <td>
                <ul>
                    <li>L'attaquant devine le mot de passe.
                    </li>
                    <li>L'attaquant intercepte la communication.
                    </li>
                </ul>
            </td>
            <td>
                <ul>
                    <li>L'attaquant a accès aux données de l'utilisateur. 
                    </li>
                    <li>L'attaquant intercepte la communication.
                    </li>
                </ul>
            </td>
            <td>
                <ul>
                    <li>Les mots de passe, et leur robustesse, sont vérifiés.
                    </li>
                    <li>La transmission et le stockage sont chiffrés.
                    </li>
                </ul>
            </td>
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

### Admnistrateur système
Le menu est le suivant :
- 1 = Vérifier la cohérence des données venant des capteurs privés
- 2 = Marquer un capteur comme défectueux
- 3 = Visualiser la qualité de l'air dans une zone précise
- 4 = Voir toutes les données
