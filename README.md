![alt text](https://github.com/MarcinanBarbarzynca/Pilot-do-komputera-Arduino-NANO/blob/main/Schematic_Pilot%20do%20wag_2021-02-23.png)

# Pilot-do-komputera-Arduino-NANO

Urządzenie to odpowiada za wysyłanie po serialu do komputera pojedynczych charów. Te czary są potem interpretowane przez skrypt, a następnie następuje reakcja. 

## Co to jest?

To płyta LanczPada zbudowanego na arduino nano. 

## Aktualne wykorzystanie:

Sterowanie wagami. Pilot posiada 3 przyciski. 
- Wyślij --> Odpowiada za uruchomienie skryptu wysyłającego dane na serwer pomiaru wagowego
- Taruj --> Wysyła do wagi rozkaz tarowania i przesyłania danych w trybie ciągłym
- Cofnij --> Odpowiada za uruchomienie skryptu wysyłającego ujemne dane na serwer. 

