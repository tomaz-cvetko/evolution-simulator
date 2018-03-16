[![N|Solid](https://www.fmf.uni-lj.si/si/img/logo.gif)](https://en.wikipedia.org/wiki/Evolution)

# Grande collaboration for the evolution simulator
## Spare time project
**Casual** hacking for **casual** wasting of *time* we *don't have*!
## System design
### Resource & food generation
The trivial part really, once the full creature-side functionality is implemented,
various configurations may produce different (*unexpected*?) results. There are two
aspects to this: initial generation and regeneration of the resources. Food can be
generated deterministicly through a well-defined function or randomly. Regen too can
happen in a well defined way or stochastically (or not at all).
### Organisms, objects of the "evolution"
This is the core of this project. If organisms are not well thought through, results
will surely be trivial or even nonexistent. Main functionality should include living,
moving and breeding, which will be linked to parameters such as food consumption,
efficiency, speed, navigation/movement patterns. Through intergenerational optimisation
of these parameters the so called "evolution" is planned to occur.
Breeding should be implemented in a form of a generalised algorithm, as independent of
the type of organism as possible (if at all possible). Therefore the representation of
the being's parameters should become Orgainsm independent (custom matrix math vs c++ inheritance)?
### Implementation
The general idea is to have a quick way to visualise results at the end of each simulation,
which shall be achieved by the usage of SDL2 library. However, the project is designed in
a way to ensure that the visualisation part is in no way required for the simulation itself.
Therefore visualisation and simulation are two separate components linked (quite literally)
only in main.cpp file - so it can be untangled with a simle replacement of the main.cpp file.
