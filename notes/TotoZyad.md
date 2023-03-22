# Fichiers csv:
- sensors.csv = capteurs 
SensorID;Latitude;Longitude;
(Example: Sensor0;44;-1;)

- measurements.csv = mesures
Timestamp;SensorID;AttributeID;Value;
(Example: 2019-01-01 12:00:00;Sensor0;O3;50.25;)

- attributes.csv = description et unité de mesure
AttributeID,Unit;Description;
(Example: O3;µg/m3;concentration d'ozone;)

- providers.csv = fournisseurs de nettoyeurs
ProviderID;CleanerID;
(Example: Provider0;Cleaner0;)

- cleaners.csv = nettoyeurs 
CleanerID;Latitude;Longitude;Timestamp(start);Timestamp(stop);
(Example: Cleaner0;45.3;1.3;2019-02-01 12:00:00;2019-03-01 00:00:00;)

- users.csv = Utilisateurs particuliers
UserID;SensorID;
(Example: User0;Sensor70;)

# Airwatcher:
- Analyse des données du capteur pour vérifier que ça marche
- Production de stats par exemple moyenne de la qualité de l'air dans une zone, AQI, ATMO etc
- Selection d'un capteur pour générer rank et score
- Production de la valeur de qualité de l'air pour une zone précise
- Impact des nettoyeurs
- Recevoir des données de particuliers avec un système de points
- Posssibilité de vérifier les données des particuliers (fiabilité)
- Voir la performance des divers algorithmes en ms
- Pas de données ajoutées ou modifiées 
- Une console locale pour interagir avec les csv avec des privilèges
