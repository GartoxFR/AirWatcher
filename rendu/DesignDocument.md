---
title: "Document des exigences de spécification"
titlepage: true
author: ["CHONE Théo", "CHORYNSKI Ewan", "DELHON Florian", "HADDAD Zyad"]
table-use-row-colors: true
caption-justification: centering
listings-disable-line-numbers: true
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

- La couche d'interface utilisateur qui devra afficher les résultats à la console et gérer les entrées
- La couche d'authentification qui décidera quelles fonctionnalités montrer à l'utilisateur courant
- La couche de traitement de données qui sera chargé de faire les calculs demandés
- La couche de données qui permettra de stocker efficacement les données

![Diargramme de l'architecture en couche](img/modules.png){ width=20% }

# Scenarios majeurs


## Calcul de la qualité de l'air dans une zone

### Diagramme de séquence

![Diagramme de séquence du premier scénario](img/seqScenar1.png){ width=70% }

### Pseudo code

```code

Entrée : double latitude, double longitude, double rayon, time_t dateDebut, time_t dateFin
Précondition : L'utilisateur a tapé les coordonnées de la zone dont il souhaite avoir la qualité de l'air
Sortie : int

Début : 
	
	vector <- Chercher les sensors dans la zone définie par la latitude, longitude et rayon
	Pour t <- 0 à vector.size()
		vectorMesure <- Chercher les mesures dans la période spéficiée (<dateFin et >dateDebut)
		mesureMoyenne = 0
		Pour u <- 0 à vectorMesure.size()
			mesureMoyenne <- mesureMoyenne.operator+=(mesure u)
		Fin pour
	Fin pour
	mesureMoyenne <- mesureMoyenne.operator/=(vectorMesure.size())
	indice <- Calcul de qualité de l'air à partir de mesureMoyenne
	Retourne indice

Fin
```

### Tests unitaires

## CalculQualiteAirZone(double latitude, double longitude, double rayon): int

- Description : prend en paramètre une zone circulaire, et renvoie l'indice ATMO correspondant à la moyenne des mesures des capteurs situés dans la zone.
- Pré-condition : fournir les Double correspondants coordonnées du centre (latitude, longitude) ainsi que la taille du rayon de la zone à évaluer.
- Post-condition : fournir un entier (Integer) correspondant à l'indice ATMO de la zone.
- Jeu de tests : un tableau de [latitude, longitude, rayon], ainsi qu'un tableau d'Integer comprenant les indices ATMO correpondants.
- Code : construire un Dataset avec le jeu de mesures souhaité. Construire un ProcessingLayer avec un pointeur vers le Dataset implanté. Pour chaque élément du tableau de [latitude, longitude, rayon], faire appel à la méthode CalculQualiteAirZone(). Comparer l'indice ATMO calculé avec le bon indice.
- Exemple de jeux de tests :
    -> une zone ponctuelle (rayon = 0), en la localisation d'un capteur,
    -> une zone circulaire, sans aucun capteur à l'intérieur,
    -> une zone circulaire, avec un seul capteur à l'intérieur,

## Récupérer les capteurs similaires

### Diagramme de séquence

![Diagramme de séquence du deuxième scénario](img/seqScenar2.png){ width=70% }

### Pseudo code

```code

Entrée : String sensorId, time_t start, time_t end
Précondition : L'utilisateur a tapé l'ID du capteur et la période souhaitée
Sortie : multimap <double, Sensor*>

Début :

	Sensor* <- Chercher le capteur avec sensorId
	vector1<Mesure*> <- Chercher les mesures du capteur dans la période
	Pour t <- 0 à vector<Mesure*>.size()
		mesureMoyenne <- mesureMoyenne.operator+=(mesure t)
	Fin pour
	mesureMoyenne <- mesureMoyenne.operator/=(vectorMesure.size())
	vector1<Sensor*> <- Chercher tous les capteurs
	multimap <double, Sensor*> = {}
	Pour u <- 0 à vector1<Sensor*>.size()
		vector2<Mesure*> <- Chercher les mesures du capteur u dans la période
		Pour v <- 0 à vector2<Mesure*>.size()
			mesuresMoyennes <- mesuresMoyennes.operator+=(mesure v)
		Fin pour
		mesuresMoyennes <- mesuresMoyennes.operator/=(vector2<Mesure*>.size())
		indiceSimilarite <- Calculer la similarité du capteur avec les autres (calcul de norme)
		Insérer indiceSimilarite et capteur u dans multimap
	Fin pour
	Retourner multimap
		
Fin

```

### Tests unitaires

## CalculSimilarite(string SensorID, date start, date end): vector<Sensor*>

- Description : prend en paramètre le SensorID d'un capteur ainsi qu'une période de temps (dates de début et de fin), et retourne le classement des capteurs les plus similaires sous la forme d'un vector<Sensor>.
- Pré-condition : fournir un SensorID valide et les dates de début et de fin.
- Post-condition : fournir vector<Sensor> correspondant au classement des autres capteurs, ordonné du plus similaire au moins similaire.
- Jeu de tests : un tableau de [SensorID, start, end], ainsi qu'un tableau de vector<Sensor> comprenant les classements correpondants.
- Code : construire un Dataset avec le jeu de mesures souhaité. Construire un ProcessingLayer avec un pointeur vers le Dataset implanté. Pour chaque élément du tableau de [SensorID, start, end], faire appel à la méthode CalculSimilarite(). Comparer les classements renvoyés avec les bons classements.
- Exemple de jeux de tests :
    -> un capteur n'existant pas dans la base de données,
    -> un capteur existant dans la base de données, avec une période de temps ne contenant aucune mesure,
    -> un capteur existant dans la base de données, avec une période de temps ne contenant qu'une seule mesure,
    -> un capteur existant dans la base de données, avec une période de temps contenant plusieurs mesures.

## Vérifier l'impact des nettoyeurs

### Diagramme de séquence

![Diagramme de séquence du premier scénario](img/seqScenar3.png){ width=70% }

### Pseudo code

```code

Entrée : String cleanerId
Précondition : L'utilisateur a tapé le cleanerId
Sortie : vector <MesurementValues>

Début :
	
	Cleaner* <- Chercher le cleaner avec cleanerId
	vector <difference> liste <- []
	Pour r <- 100m, 500m, 1km, 5km, 10km
		vector <Sensor*> <- Chercher les sensors dans la zone définie par la latitude, longitude et rayon r
		mesureMoyenne <- [0, 0]
		i <- 0
		Pour p <- 2j avant cleaner, 2j après cleaner
			Pour s <- 0 à vector.size()
				vectorMesure <- Chercher les mesures dans la période p
				
				Pour u <- 0 à vectorMesure.size()
					mesureMoyenne[i] <- mesureMoyenne += mesure u
				Fin pour
			Fin pour
			mesureMoyenne <- mesureMoyenne /= vectorMesure.size()
			i <- i + 1
		Fin pour
		difference <- mesureMoyenne[1] - mesureMoyenne[0] 
		Ajouter difference dans liste
	Fin pour
	Retourner liste
```

### Tests unitaires

## CalculImpactNettoyeur(string CleanerID): double

- Description : prend en paramètre le CleanerID d'un nettoyeur et retourne un double quantifiant l'impact du nettoyeur : plus il est grand, plus le nettoyeur a eu un bon impact sur la qualité de l'air.
- Pré-condition : fournir un CleanerID valide.
- Post-condition : fournir Double quantifiant l'impact du nettoyeur.
- Jeu de tests : un tableau de CleanerID, ainsi qu'un tableau de Double comprenant les indices d'impact correspondants.
- Code : construire un Dataset avec le jeu de mesures souhaité. Construire un ProcessingLayer avec un pointeur vers le Dataset implanté. Pour chaque élément du tableau de CleanerID, faire appel à la méthode CalculImpactNettoyeur(). Comparer les indices renvoyés avec les bons indices.
- Exemple de jeux de tests :
    -> un nettoyeur n'existant pas dans la base de données,
    -> un nettoyeur existant dans la base de données, dont on sait que l'impact a été nul (aucune amélioration de qualité de l'air),
    -> un nettoyeur existant dans la base de données, dont on sait que l'impact a été nul (aucune amélioration de qualité de l'air).