---
title: "Document de conception"
titlepage: true
author: ["CHONE Théo", "CHORYNSKI Ewan", "DELHON Florian", "HADDAD Zyad"]
table-use-row-colors: true
caption-justification: centering
listings-disable-line-numbers: true
listings-no-page-break: true
toc-own-page: true
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

![Diagramme de l'architecture en couche](img/modules.png){ width=20% }

# Diagrammes de classe

![Couche données](img/class.png)

![Couche de traitement](img/classProcessing.png)

![Couche authentification](img/classAuth.png)


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

<table>
    <tr>
        <td>Fonction de test</td>
        <td>testCalculQualiteAirZone()</td>
    </tr>
	<tr>
        <td>Rôle</td>
        <td>Tester le bon fonctionnement de la méthode <i>CalculQualiteAirZone(double latitude, double longitude, double rayon, time_t start, time_t end): int</i> de calcul de qualité de l'air dans une zone, renvoyant l'indice ATMO correspondant à la moyenne des mesures des capteurs situés dans la zone.<br></td>
    </tr>
	<tr>
        <td>Input</td>
        <td>La méthode de calcul prend en paramètre la zone circulaire à évaluer (latitude et longitude du centre, et rayon), ainsi que la période d'évaluation (dates de début et de fin).<br></td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Elle renvoie un entier correspondant à l'indice ATMO de la zone.</td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testZonePonctuelle()</td>
    </tr>
	<tr>
        <td>Dataset</td>
        <td>Dans le <i>sensor.csv</i> :
		<br>Sensor0;44;-1;
		<br>Dans le <i>measurements.csv</i> :
		<br>2019-01-01 12:00:00;Sensor0;O3;50.25;
		<br>2019-01-01 12:00:00;Sensor0;NO2;74.5;
		<br>2019-01-01 12:00:00;Sensor0;SO2;41.5;
		<br>2019-01-01 12:00:00;Sensor0;PM10;44.75;</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>Latitude = 44, Longitude = -1, Rayon = 0, Start = 2019-01-01 12:00:00, End = 2019-01-01 12:00:01</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Indice ATMO = 7</td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testAucunCapteur()</td>
    </tr>
	<tr>
        <td>Dataset</td>
        <td>Dans le <i>sensor.csv</i> :
		<br>Sensor0;44;-1;
		<br>Dans le <i>measurements.csv</i> :
		<br>2019-01-01 12:00:00;Sensor0;O3;50.25;
		<br>2019-01-01 12:00:00;Sensor0;NO2;74.5;
		<br>2019-01-01 12:00:00;Sensor0;SO2;41.5;
		<br>2019-01-01 12:00:00;Sensor0;PM10;44.75;</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>Latitude = 45, Longitude = 1, Rayon = 1, Start = 2019-01-01 12:00:00, End = 2019-01-01 12:00:01</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Indice ATMO = 0 (valeur retournée lorsqu'aucune mesure n'a été trouvée)</td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testAucuneMesure()</td>
    </tr>
	<tr>
        <td>Dataset</td>
        <td>Dans le <i>sensor.csv</i> :
		<br>Sensor0;44;-1;
		<br>Dans le <i>measurements.csv</i> :
		<br>2019-01-01 12:00:00;Sensor0;O3;50.25;
		<br>2019-01-01 12:00:00;Sensor0;NO2;74.5;
		<br>2019-01-01 12:00:00;Sensor0;SO2;41.5;
		<br>2019-01-01 12:00:00;Sensor0;PM10;44.75;</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>Latitude = 44, Longitude = -1, Rayon = 1, Start = 2019-01-02 12:00:00, End = 2019-01-02 12:00:01</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Indice ATMO = 0 (valeur retournée lorsqu'aucune mesure n'a été trouvée)</td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testPlusieursCapteurs()</td>
    </tr>
	<tr>
        <td>Dataset</td>
        <td>Dans le <i>sensor.csv</i> :
		<br>Sensor0;44;-1;
		<br>Sensor1;44;-0.3;
		<br>Dans le <i>measurements.csv</i> :
		<br>2019-01-01 12:00:00;Sensor0;O3;50.25;
		<br>2019-01-01 12:00:00;Sensor0;NO2;74.5;
		<br>2019-01-01 12:00:00;Sensor0;SO2;41.5;
		<br>2019-01-01 12:00:00;Sensor0;PM10;44.75;
		<br>2019-01-01 12:00:00;Sensor1;O3;63.04;
		<br>2019-01-01 12:00:00;Sensor1;NO2;61.92;
		<br>2019-01-01 12:00:00;Sensor1;SO2;34.42;
		<br>2019-01-01 12:00:00;Sensor1;PM10;51.12;</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>Latitude = 44, Longitude = -1, Rayon = 100, Start = 2019-01-02 12:00:00, End = 2019-01-02 12:00:01</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Indice ATMO = 7</td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testPlusieursMesures()</td>
    </tr>
	<tr>
        <td>Dataset</td>
        <td>Dans le <i>sensor.csv</i> :
		<br>Sensor0;44;-1;
		<br>Dans le <i>measurements.csv</i> :
		<br>2019-01-01 12:00:00;Sensor0;O3;50.25;
		<br>2019-01-01 12:00:00;Sensor0;NO2;74.5;
		<br>2019-01-01 12:00:00;Sensor0;SO2;41.5;
		<br>2019-01-01 12:00:00;Sensor0;PM10;44.75;
		<br>2019-01-02 12:00:00;Sensor0;O3;50.5;
		<br>2019-01-02 12:00:00;Sensor0;NO2;72;
		<br>2019-01-02 12:00:00;Sensor0;SO2;39.25;
		<br>2019-01-02 12:00:00;Sensor0;PM10;50.5;</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>Latitude = 44, Longitude = -1, Rayon = 0, Start = 2019-01-01 12:00:00, End = 2019-01-02 12:00:01</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Indice ATMO = 7</td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testPlusieursMesuresPlusieursCapteurs()</td>
    </tr>
	<tr>
        <td>Dataset</td>
        <td>Dans le <i>sensor.csv</i> :
		<br>Sensor0;44;-1;
		<br>Sensor1;44;-0.3;
		<br>Dans le <i>measurements.csv</i> :
		<br>2019-01-01 12:00:00;Sensor0;O3;50.25;
		<br>2019-01-01 12:00:00;Sensor0;NO2;74.5;
		<br>2019-01-01 12:00:00;Sensor0;SO2;41.5;
		<br>2019-01-01 12:00:00;Sensor0;PM10;44.75;
		<br>2019-01-02 12:00:00;Sensor0;O3;50.5;
		<br>2019-01-02 12:00:00;Sensor0;NO2;72;
		<br>2019-01-02 12:00:00;Sensor0;SO2;39.25;
		<br>2019-01-02 12:00:00;Sensor0;PM10;50.5;
		<br>2019-01-01 12:00:00;Sensor1;O3;63.04;
		<br>2019-01-01 12:00:00;Sensor1;NO2;61.92;
		<br>2019-01-01 12:00:00;Sensor1;SO2;34.42;
		<br>2019-01-01 12:00:00;Sensor1;PM10;51.12;
		<br>2019-01-02 12:00:00;Sensor1;O3;65.08;
		<br>2019-01-02 12:00:00;Sensor1;NO2;60.33;
		<br>2019-01-02 12:00:00;Sensor1;SO2;32.88;
		<br>2019-01-02 12:00:00;Sensor1;PM10;54.58;</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>Latitude = 44, Longitude = -1, Rayon = 100, Start = 2019-01-01 12:00:00, End = 2019-01-02 12:00:01</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Indice ATMO = 8</td>
    </tr>
</table>


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

<table style="width:100%">
    <tr>
        <td>Fonction de test</td>
        <td>testCalculSimilarite()</td>
    </tr>
	<tr>
        <td>Rôle</td>
        <td>Tester le bon fonctionnement de la méthode <i>CalculSimilarite(string SensorID, time_t start, time_t end): multimap &lt double, SensorID &gt</i> de calcul du classements des capteurs les plus similaires à un capteur donné.<br></td>
    </tr>
	<tr>
        <td>Input</td>
        <td>La méthode de calcul prend en paramètre l'ID du capteur ainsi que la période d'évaluation (dates de début et de fin).</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Elle renvoie un classement des capteurs, par ordre décroissant de similarité, sous forme d'une multimap &lt double, SensorID &gt, avec comme clé l'indice de similarité.<br></td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testCapteurSeul()</td>
    </tr>
	<tr>
        <td>Dataset</td>
        <td>Dans le <i>sensor.csv</i> :
		<br>Sensor0;44;-1;
		<br>Dans le <i>measurements.csv</i> :
		<br>2019-01-01 12:00:00;Sensor0;O3;50.25;
		<br>2019-01-01 12:00:00;Sensor0;NO2;74.5;
		<br>2019-01-01 12:00:00;Sensor0;SO2;41.5;
		<br>2019-01-01 12:00:00;Sensor0;PM10;44.75;</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>SensorID = Sensor0, Start = 2019-01-01 12:00:00, End = 2019-01-01 12:00:01</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Une multimap vide.</td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testCapteurInconnu()</td>
    </tr>
	<tr>
        <td>Dataset</td>
        <td>Dans le <i>sensor.csv</i> :
		<br>Sensor0;44;-1;
		<br>Dans le <i>measurements.csv</i> :
		<br>2019-01-01 12:00:00;Sensor0;O3;50.25;
		<br>2019-01-01 12:00:00;Sensor0;NO2;74.5;
		<br>2019-01-01 12:00:00;Sensor0;SO2;41.5;
		<br>2019-01-01 12:00:00;Sensor0;PM10;44.75;</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>SensorID = Sensor1, Start = 2019-01-01 12:00:00, End = 2019-01-01 12:00:01</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Une multimap vide.</td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testAucuneMesureSimilarite()</td>
    </tr>
	<tr>
        <td>Dataset</td>
        <td>Dans le <i>sensor.csv</i> :
		<br>Sensor0;44;-1;
		<br>Sensor1;44;-0.3;
		<br>Sensor2;44;0.4;
		<br>Dans le <i>measurements.csv</i> :
		<br>2019-01-01 12:00:00;Sensor0;O3;50.25;
		<br>2019-01-01 12:00:00;Sensor0;NO2;74.5;
		<br>2019-01-01 12:00:00;Sensor0;SO2;41.5;
		<br>2019-01-01 12:00:00;Sensor0;PM10;44.75;
		<br>2019-01-01 12:00:00;Sensor1;O3;63.04;
		<br>2019-01-01 12:00:00;Sensor1;NO2;61.92;
		<br>2019-01-01 12:00:00;Sensor1;SO2;34.42;
		<br>2019-01-01 12:00:00;Sensor1;PM10;51.12;
		<br>2019-01-01 12:00:00;Sensor2;O3;47.84;
		<br>2019-01-01 12:00:00;Sensor2;NO2;43.32;
		<br>2019-01-01 12:00:00;Sensor2;SO2;46.24;
		<br>2019-01-01 12:00:00;Sensor2;PM10;45.02;</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>SensorID = Sensor0, Start = 2019-01-02 12:00:00, End = 2019-01-02 12:00:01</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Une multimap vide.</td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testPlusieursCapteursSimilarite()</td>
    </tr>
	<tr>
        <td>Dataset</td>
        <td>Dans le <i>sensor.csv</i> :
		<br>Sensor0;44;-1;
		<br>Sensor1;44;-0.3;
		<br>Sensor2;44;0.4;
		<br>Dans le <i>measurements.csv</i> :
		<br>2019-01-01 12:00:00;Sensor0;O3;50.25;
		<br>2019-01-01 12:00:00;Sensor0;NO2;74.5;
		<br>2019-01-01 12:00:00;Sensor0;SO2;41.5;
		<br>2019-01-01 12:00:00;Sensor0;PM10;44.75;
		<br>2019-01-01 12:00:00;Sensor1;O3;63.04;
		<br>2019-01-01 12:00:00;Sensor1;NO2;61.92;
		<br>2019-01-01 12:00:00;Sensor1;SO2;34.42;
		<br>2019-01-01 12:00:00;Sensor1;PM10;51.12;
		<br>2019-01-01 12:00:00;Sensor2;O3;47.84;
		<br>2019-01-01 12:00:00;Sensor2;NO2;43.32;
		<br>2019-01-01 12:00:00;Sensor2;SO2;46.24;
		<br>2019-01-01 12:00:00;Sensor2;PM10;45.02;</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>SensorID = Sensor0, Start = 2019-01-01 12:00:00, End = 2019-01-01 12:00:01</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Une multimap contenant les paires &lt 412.54, Sensor1 &gt et &lt 1000.54, Sensor2 &gt.</td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testPlusieursCapteursPlusieursMesuresSimilarite()</td>
    </tr>
	<tr>
        <td>Dataset</td>
        <td>Dans le <i>sensor.csv</i> :
		<br>Sensor0;44;-1;
		<br>Sensor1;44;-0.3;
		<br>Sensor2;44;0.4;
		<br>Dans le <i>measurements.csv</i> :
		<br>2019-01-01 12:00:00;Sensor0;O3;50.25;
		<br>2019-01-01 12:00:00;Sensor0;NO2;74.5;
		<br>2019-01-01 12:00:00;Sensor0;SO2;41.5;
		<br>2019-01-01 12:00:00;Sensor0;PM10;44.75;
		<br>2019-01-02 12:00:00;Sensor0;O3;50.5;
		<br>2019-01-02 12:00:00;Sensor0;NO2;72;
		<br>2019-01-02 12:00:00;Sensor0;SO2;39.25;
		<br>2019-01-02 12:00:00;Sensor0;PM10;50.5;
		<br>2019-01-01 12:00:00;Sensor1;O3;63.04;
		<br>2019-01-01 12:00:00;Sensor1;NO2;61.92;
		<br>2019-01-01 12:00:00;Sensor1;SO2;34.42;
		<br>2019-01-01 12:00:00;Sensor1;PM10;51.12;
		<br>2019-01-02 12:00:00;Sensor1;O3;65.08;
		<br>2019-01-02 12:00:00;Sensor1;NO2;60.33;
		<br>2019-01-02 12:00:00;Sensor1;SO2;32.88;
		<br>2019-01-02 12:00:00;Sensor1;PM10;54.58;
		<br>2019-01-01 12:00:00;Sensor2;O3;47.84;
		<br>2019-01-01 12:00:00;Sensor2;NO2;43.32;
		<br>2019-01-01 12:00:00;Sensor2;SO2;46.24;
		<br>2019-01-01 12:00:00;Sensor2;PM10;45.02;
		<br>2019-01-02 12:00:00;Sensor2;O3;47.68;
		<br>2019-01-02 12:00:00;Sensor2;NO2;43.22;
		<br>2019-01-02 12:00:00;Sensor2;SO2;46.98;
		<br>2019-01-02 12:00:00;Sensor2;PM10;45.1;</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>SensorID = Sensor0, Start = 2019-01-01 12:00:00, End = 2019-01-02 12:00:01</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Une multimap contenant les paires &lt 406.82, Sensor1 &gt et &lt 951.09, Sensor2 &gt.</td>
    </tr>
</table>

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

<table style="width:100%">
    <tr>
        <td>Fonction de test</td>
        <td>testImpactNettoyeur()</td>
    </tr>
	<tr>
        <td>Rôle</td>
        <td>Tester le bon fonctionnement de la méthode <i>CalculImpactNettoyeur(string CleanerID): vector &lt MeasurementValues &gt</i> de calcul de la différence de qualité de l'air dans un rayon de 100m, 500m, 1km, 5km et 10km autour du nettoyeur. On compare les mesures deux jours avant l'arrivée du cleaner, et les deux derniers jours du cleaner.<br></td>
    </tr>
	<tr>
        <td>Input</td>
        <td>La méthode de calcul prend en paramètre l'ID du cleaner.</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Elle renvoie la différence de qualité de l'air dans un rayon de 100m, 500m, 1km, 5km et 10km autour du nettoyeur, sous forme de vector &lt MeasurementValues &gt.<br></td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testNettoyeurConnu()</td>
    </tr>
	<tr>
		<td>Dataset</td>
        <td>(voir Annexe)</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>SensorID = Cleaner0</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>[{1.625, 0, -1.375, 1.5},
		<br>{1.1575, 0, -0.9275, 1.5425},
		<br>{1.0033, 0.0267, -0.84, 1.2},
		<br>{0.8025, -0.2675, -0.6988, 1.0038},
		<br>{0.782, -0.535, -0.601, 0.567}]</td>
    </tr>
</table>

<table style="width:100%">
    <tr>
        <td>Test unitaire</td>
        <td>testNettoyeurInconnu()</td>
    </tr>
	<tr>
        <td>Dataset</td>
        <td>(voir Annexe)</td>
    </tr>
	<tr>
        <td>Input</td>
        <td>SensorID = Cleaner1</td>
    </tr>
	<tr>
        <td>Output</td>
        <td>Vector vide.<br></td>
    </tr>
</table>

# Annexe : Dataset de test des nettoyeurs

Dans le *cleaners.csv* :
Cleaner0;45.333333;1.333333;2019-02-01 12:00:00;2019-03-01 00:00:00;
Dans le *sensor.csv* :
Sensor0;45.3335;1.3335;
Sensor1;45.335;1.335;
Sensor2;45.34;1.34;
Sensor3;45.35;1.35;
Sensor4;45.4;1.4;
Dans le *measurements.csv* :
2019-01-30 12:00:00;Sensor0;O3;48.5;
2019-01-30 12:00:00;Sensor0;NO2;72.25;
2019-01-30 12:00:00;Sensor0;SO2;39;
2019-01-30 12:00:00;Sensor0;PM10;47.25;
2019-01-31 12:00:00;Sensor0;O3;49.75;
2019-01-31 12:00:00;Sensor0;NO2;76.25;
2019-01-31 12:00:00;Sensor0;SO2;38.25;
2019-01-31 12:00:00;Sensor0;PM10;48;
2019-02-27 12:00:00;Sensor0;O3;50;
2019-02-27 12:00:00;Sensor0;NO2;73.75;
2019-02-27 12:00:00;Sensor0;SO2;39.25;
2019-02-27 12:00:00;Sensor0;PM10;46.75;
2019-02-28 12:00:00;Sensor0;O3;45;
2019-02-28 12:00:00;Sensor0;NO2;74.75;
2019-02-28 12:00:00;Sensor0;SO2;40.75;
2019-02-28 12:00:00;Sensor0;PM10;45.5;
2019-01-30 12:00:00;Sensor1;O3;61.92;
2019-01-30 12:00:00;Sensor1;NO2;58.54;
2019-01-30 12:00:00;Sensor1;SO2;34.83;
2019-01-30 12:00:00;Sensor1;PM10;52.71;
2019-01-31 12:00:00;Sensor1;O3;63.62;
2019-01-31 12:00:00;Sensor1;NO2;63.38;
2019-01-31 12:00:00;Sensor1;SO2;34.21;
2019-01-31 12:00:00;Sensor1;PM10;53.5;
2019-02-27 12:00:00;Sensor1;O3;64.33;
2019-02-27 12:00:00;Sensor1;NO2;60.96;
2019-02-27 12:00:00;Sensor1;SO2;35.71;
2019-02-27 12:00:00;Sensor1;PM10;51.62;
2019-02-28 12:00:00;Sensor1;O3;59.83;
2019-02-28 12:00:00;Sensor1;NO2;60.96;
2019-02-28 12:00:00;Sensor1;SO2;34.29;
2019-02-28 12:00:00;Sensor1;PM10;51.42;
2019-01-30 12:00:00;Sensor2;O3;46.32;
2019-01-30 12:00:00;Sensor2;NO2;39.76;
2019-01-30 12:00:00;Sensor2;SO2;46.47;
2019-01-30 12:00:00;Sensor2;PM10;44.12;
2019-01-31 12:00:00;Sensor2;O3;48.27;
2019-01-31 12:00:00;Sensor2;NO2;43.06;
2019-01-31 12:00:00;Sensor2;SO2;49.2;
2019-01-31 12:00:00;Sensor2;PM10;44.75;
2019-02-27 12:00:00;Sensor2;O3;46.89;
2019-02-27 12:00:00;Sensor2;NO2;40.83;
2019-02-27 12:00:00;Sensor2;SO2;48.45;
2019-02-27 12:00:00;Sensor2;PM10;43.1;
2019-02-28 12:00:00;Sensor2;O3;46.31;
2019-02-28 12:00:00;Sensor2;NO2;41.83;
2019-02-28 12:00:00;Sensor2;SO2;48.55;
2019-02-28 12:00:00;Sensor2;PM10;44.74;
2019-01-30 12:00:00;Sensor3;O3;23.55;
2019-01-30 12:00:00;Sensor3;NO2;39.13;
2019-01-30 12:00:00;Sensor3;SO2;45.58;
2019-01-30 12:00:00;Sensor3;PM10;50.69;
2019-01-31 12:00:00;Sensor3;O3;24.71;
2019-01-31 12:00:00;Sensor3;NO2;40.68;
2019-01-31 12:00:00;Sensor3;SO2;47.87;
2019-01-31 12:00:00;Sensor3;PM10;49.62;
2019-02-27 12:00:00;Sensor3;O3;23.31;
2019-02-27 12:00:00;Sensor3;NO2;40.97;
2019-02-27 12:00:00;Sensor3;SO2;45.08;
2019-02-27 12:00:00;Sensor3;PM10;50.02;
2019-02-28 12:00:00;Sensor3;O3;24.55;
2019-02-28 12:00:00;Sensor3;NO2;41.14;
2019-02-28 12:00:00;Sensor3;SO2;48.92;
2019-02-28 12:00:00;Sensor3;PM10;49.46;
2019-01-30 12:00:00;Sensor4;O3;24.26;
2019-01-30 12:00:00;Sensor4;NO2;60.02;
2019-01-30 12:00:00;Sensor4;SO2;57.1;
2019-01-30 12:00:00;Sensor4;PM10;39.78;
2019-01-31 12:00:00;Sensor4;O3;26.12;
2019-01-31 12:00:00;Sensor4;NO2;58.45;
2019-01-31 12:00:00;Sensor4;SO2;57.48;
2019-01-31 12:00:00;Sensor4;PM10;39.77;
2019-02-27 12:00:00;Sensor4;O3;24.72;
2019-02-27 12:00:00;Sensor4;NO2;60.66;
2019-02-27 12:00:00;Sensor4;SO2;55.51;
2019-02-27 12:00:00;Sensor4;PM10;42.0;
2019-02-28 12:00:00;Sensor4;O3;24.26;
2019-02-28 12:00:00;Sensor4;NO2;61.02;
2019-02-28 12:00:00;Sensor4;SO2;59.49;
2019-02-28 12:00:00;Sensor4;PM10;39.91;