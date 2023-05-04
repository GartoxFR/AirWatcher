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

# Décomposition modulaire

Nous avons choisi d'utiliser une architecture en couche.
L'application sera composée de :

- La couche d'interface utilisateur qui devra afficher les résultats à la console
- La couche d'authentification qui décidera quelles fonctionnalités montrer à l'utilisateur courant
- La couche de traitement de données qui sera chargé de faire les calculs demandés
- La couche de données qui permettra de stocker efficacement les données

![Diargramme de l'architecture en couche](img/modules.png){ width=20% }

# Tests unitaires

## CalculQualiteAir(MeasurementValue mesure): int

- Description : prend en paramètre les mesures de 4 gaz (O3, SO2, NO2-, PM10). Renvoie un indice ATMO (entre 1 et 10) correspondant au pire seuil (https://fr.wikipedia.org/wiki/Indice_de_qualit%C3%A9_de_l%27air).
- Pré-condition : fournir un jeu de 4 mesures (MeasurementValue) des 4 gaz cités.
- Post-condition : fournir un entier (Integer) correspondant à l'indice ATMO.
- Jeu de tests : un tableau de MeasurementValue, ainsi qu'un tableau d'Integer comprenant les indices ATMO correpondants.
- Code : pour chaque élément du tableau de MeasurementValue, faire appel à la méthode CalculQualiteAir(). Comparer l'indice ATMO calculé avec le bon indice.

## CalculQualiteAirZone(double latitude, double longitude, double rayon): int

- Description : prend en paramètre une zone circulaire, et renvoie l'indice ATMO correspondant à la moyenne des mesures des capteurs situés dans la zone.
- Pré-condition : fournir les Double correspondants coordonnées du centre (latitude, longitude) ainsi que la taille du rayon de la zone à évaluer.
- Post-condition : fournir un entier (Integer) correspondant à l'indice ATMO de la zone.
- Jeu de tests : un tableau de [latitude, longitude, rayon], ainsi qu'un tableau d'Integer comprenant les indices ATMO correpondants.
- Code : pour chaque élément du tableau de [latitude, longitude, rayon], faire appel à la méthode CalculQualiteAirZone(). Comparer l'indice ATMO calculé avec le bon indice.

## CalculSimilarite(string SensorID, date start, date end): vector<Sensor>

- Description : prend en paramètre le SensorID d'un capteur ainsi qu'une période de temps (dates de début et de fin), et retourne le classement des capteurs les plus similaires sous la forme d'un vector<Sensor>.
- Pré-condition : fournir un SensorID valide et les dates de début et de fin.
- Post-condition : fournir vector<Sensor> correspondant au classement des autres capteurs, ordonné du plus similaire au moins similaire.
- Jeu de tests : un tableau de [SensorID, start, end], ainsi qu'un tableau de vector<Sensor> comprenant les classements correpondants.
- Code : pour chaque élément du tableau de [SensorID, start, end], faire appel à la méthode CalculSimilarite(). Comparer les classements renvoyés avec les bons classements.

## CalculImpactNettoyeur(string CleanerID): double

- Description : prend en paramètre le CleanerID d'un nettoyeur et retourne un double quantifiant l'impact du nettoyeur : plus il est grand, plus le nettoyeur a eu un bon impact sur la qualité de l'air.
- Pré-condition : fournir un CleanerID valide.
- Post-condition : fournir Double quantifiant l'impact du nettoyeur.
- Jeu de tests : un tableau de CleanerID, ainsi qu'un tableau de Double comprenant les indices d'impact correspondants.
- Code : pour chaque élément du tableau de CleanerID, faire appel à la méthode CalculImpactNettoyeur(). Comparer les indices renvoyés avec les bons indices.

## CalculFiabilite(string SensorID, double rayon): double

- Description : prend en paramètre le SensorID d'un capteur et retourne un double quantifiant la fiabilité du capteur, en se basant sur les mesures des autres capteurs situés dans un certain rayon autour du capteur.
- Pré-condition : fournir un SensorID valide et un rayon.
- Post-condition : fournir Double quantifiant la fiabilité du capteur.
- Jeu de tests : un tableau de [SensorID, rayon], ainsi qu'un tableau de Double comprenant les indices de fiabilité correspondants.
- Code : pour chaque élément du tableau de [SensorID, rayon], faire appel à la méthode CalculFiabilite(). Comparer les indices renvoyés avec les bons indices.