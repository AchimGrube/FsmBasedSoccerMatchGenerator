# FsmBasedSoccerMatchGenerator
### Eine C++ Projektarbeit über 10 Tage:
### Beispielhafte Simulation eines Fussballspiels mit eigenständig agierenden Spielern durch eine Finite-state machine
___
#### Klassenbeschreibung:

- **AiBasedSoccerMatchGenerator** [.cpp](./AiBasedSoccerMatchGenerator.cpp)  
*Beinhaltet die main() Funktion.*

- **Ball** [.h](./Ball.h) [.cpp](./Ball.cpp)  
*Platzhalter für weitere Logik (z.B. Beschleunigung, wetterabhängiges Verhalten etc.)*

- **Entity** [.h](./Entity.h) [.cpp](./Entity.cpp)  
*Basisklasse für alles auf dem Spielfeld. Steuert Bewegung und Position.*

- **FiniteStateMachine** [.h](./FiniteStateMachine.h) [.cpp](./FiniteStateMachine.cpp)  
*Schaltet zwischen den States der Spieler um (Idle, Move, Interact, Attack)*

- **Generator** [.h](./Generator.h) [.cpp](./Generator.cpp)  
*Generiert neue Spieler und deren Namen.*  
(Vorgabe für die Projektarbeit: Dateien lesen und Strings verarbeiten.)

- **Match** [.h](./Match.h) [.cpp](./Match.cpp)  
*Spielablauf und Möglichkeit, den Spielverlauf in einer Text-Datei zu speichern.*  
(Vorgabe für die Projektarbeit: Dateien schreiben.)

- **Pitch** [.h](./Pitch.h) [.cpp](./Pitch.cpp)  
*Repräsentiert das Spielfeld mit 17x11 Feldern.*

- **Player** [.h](./Player.h) [.cpp](./Player.cpp)  
*Definiert einen Spieler und ermöglicht das Ausführen von Aktionen.*

- **PlayerState** [.h](./PlayerState.h) [.cpp](./PlayerState.cpp)  
*Basisklasse aller States der Spieler. Legt die Position eines Spielers auf dem Feld fest.*

- **PlayerStateAttack** [.h](./PlayerStateAttack.h) [.cpp](./PlayerStateAttack.cpp)  
*Beispielhafte Logik für einen angreifenden Spieler.*

- **PlayerStateIdle** [.h](./PlayerStateIdle.h) [.cpp](./PlayerStateIdle.cpp)  
*Beispielhafte Logik für einen Spieler ohne Aufgabe.*

- **PlayerStateInteract** [.h](./PlayerStateInteract.h) [.cpp](./PlayerStateInteract.cpp)  
*Beispielhafte Logik zur Interaktion zwischen Spielern (Zweikampf, Pass).*

- **PlayerStateMove** [.h](./PlayerStateMove.h) [.cpp](./PlayerStateMove.cpp)  
*Beispielhafte Logik für Spieler ohne Ball, um sich auf dem Spielfeld zu bewegen.*

- **Position** [.h](./Position.h) [.cpp](./Position.cpp)  
*Definition der Position auf dem Spielfeld.*

- **Tile** [.h](./Tile.h) [.cpp](./Tile.cpp)  
*Definiert ein Feld auf dem Spielfeld.*

- **_functions** [.h](./_functions.h)  
*Diverse Hilfsfunktionen.*
