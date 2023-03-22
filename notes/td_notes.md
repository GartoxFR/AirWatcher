# Notes - 22/03/2023 - AirWatcher

## Context
Air quality sensors monitoring for a government agency. 

## Data
- `sensors.csv`: list of sensors.
- `measurements.csv`: list of measures.
- `attributes.csv`: list of measurements types.
- `providers.csv`: list of providers and air cleaners.
- `cleaners.csv`: detailed informations about these cleaners.
- `users.csv`: list individuals who participate to the data generation.

## Specs
- Allow analysis of the data -> be sure that the sensor functions correctly.
- Produce statistics with the collected information.
- Ranking sensors by similarity with a selected sensor (mean of the quality of air, etc).
- Calculate a value of air quality at any given position.
- Observe the impact of air cleaners on air quality (radius of the cleaned zone, improvement in air quality, etc).
- Reward individuals who participate to the data generation: give one point each time their data is used in a query.
- Classify data coming from private individuals, whether it seems reliable or not.
- Measure the duration of execution of an algorithm in milliseconds.
- Console-based user interface, with access to the CSV files stored locally.
- Allow user data access through the application interface.