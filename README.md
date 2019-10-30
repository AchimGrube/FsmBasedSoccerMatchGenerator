## Eine C++ Projektarbeit über 10 Tage:
## Beispielhafte Simulation eines Fussballspiels mit eigenständig agierenden Spielern durch eine Finite-state machine
___
### Klassenbeschreibung:

- **AiBasedSoccerMatchGenerator** [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/AiBasedSoccerMatchGenerator.cpp)  
*Beinhaltet die main() Funktion.*

- **Ball** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Ball.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Ball.cpp)  
*Platzhalter für weitere Logik (z.B. Beschleunigung, wetterabhängiges Verhalten etc.)*

- **Entity** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Entity.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Entity.cpp)  
*Basisklasse für alles auf dem Spielfeld. Steuert Bewegung und Position.*

- **FiniteStateMachine** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/FiniteStateMachine.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/FiniteStateMachine.cpp)  
*Schaltet zwischen den States der Spieler um (Idle, Move, Interact, Attack)*

- **Generator** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Generator.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Generator.cpp)  
*Generiert neue Spieler und deren Namen.*  
(Vorgabe für die Projektarbeit: Dateien lesen und Strings verarbeiten.)

- **Match** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Match.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Match.cpp)  
*Spielablauf und Möglichkeit, den Spielverlauf in einer Text-Datei zu speichern.*  
(Vorgabe für die Projektarbeit: Dateien schreiben.)

- **Pitch** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Pitch.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Pitch.cpp)  
*Repräsentiert das Spielfeld mit 17x11 Feldern.*

- **Player** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Player.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Player.cpp)  
*Definiert einen Spieler und ermöglicht das Ausführen von Aktionen.*

- **PlayerState** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/PlayerState.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/PlayerState.cpp)  
*Basisklasse aller States der Spieler. Legt die Position eines Spielers auf dem Feld fest.*

- **PlayerStateAttack** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/PlayerStateAttack.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/PlayerStateAttack.cpp)  
*Beispielhafte Logik für einen angreifenden Spieler.*

- **PlayerStateIdle** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/PlayerStateIdle.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/PlayerStateIdle.cpp)  
*Beispielhafte Logik für einen Spieler ohne Aufgabe.*

- **PlayerStateInteract** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/PlayerStateInteract.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/PlayerStateInteract.cpp)  
*Beispielhafte Logik zur Interaktion zwischen Spielern (Zweikampf, Pass).*

- **PlayerStateMove** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/PlayerStateMove.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/PlayerStateMove.cpp)  
*Beispielhafte Logik für Spieler ohne Ball, um sich auf dem Spielfeld zu bewegen.*

- **Position** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Position.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Position.cpp)  
*Definition der Position auf dem Spielfeld.*

- **Tile** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Tile.h) [.cpp](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/Tile.cpp)  
*Definiert ein Feld auf dem Spielfeld.*

- **_functions** [.h](https://github.com/AchimGrube/FsmBasedSoccerMatchGenerator/blob/master/_functions.h)  
*Diverse Hilfsfunktionen.*
