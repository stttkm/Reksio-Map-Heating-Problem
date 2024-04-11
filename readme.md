# Background
![](https://przygody-reksia-remastered.odoo.com/web/image/243-30ecc234/Zrzut%20ekranu%202023-10-29%20111041.png)
*[A screenshot taken from "Reksio i Skarb Piratów Remastered Edition"](https://www.przygody-reksia.pl/galeria-zdjec)*

[Reksio](https://en.wikipedia.org/wiki/Reksio) is one of the most popular cartoon character in polish animation industry.   [*Przygody Reksia (Rex Adventures)*](https://reksio.fandom.com/wiki/Przygody_Reksia) is a series of video games based on the animated character. The series is notorious for its relative diffculty, considering its target audience suggested by the game cover (six-year-olds and older children).

One of the puzzles in the first game about Reksio ([Reksio i Skarb Piratów](https://reksio.fandom.com/wiki/Reksio_i_Skarb_Piratów)) struck me as a problem I'd encounter in an AI or algorithm course at a university.

Reksio intents to heat up a paper written with invisible ink in order to decipher it and a minigame for the player ensues. The paper is divided in regions and heating one region heats bordering regions a little bit. If one region is heated too much then it burns and the player is obliged to restart.

# The goal of this repository
I aim to apply my knowledge gained during my computer engeneering degree so far in order to figure out all the possible ways of beating the  Map Heating minigame.
# The Minigame mechanism
![](img/Start%20State.png)
*The starting point in the minigame*
![](img/Example%20State.png)
*An example intermediate state*
![](img/End%20State.png)
*The goal state*

Here I'll resume what I deduced about the game:
-  the paper is divided in regions
- for clarity let's establish a unit of heating abbreviated as *h* from *heat*
- there are 7 states a region can be in
    1.  0h (a region is not visible)
    2. 0.5h
    3. 1h
    4. 1.5h
    5. 2h (a region is perfectly visibile)
    6. 2.5h (a region is legible, but it's at brink of being burnt out; still acceptable)
    7. 3h (a region is burnt out)
- clicking a region heats up the region being clicked upon by **1h** and its bordering regions by **0.5h**


## Regions and bordering
![](img/Paper%20Regions.png)
*The map of paper regions and bordering*

In the map I introduce numbering of regions in a clockwise fashion and going from outer regions to the inner ones.

## The assymetric bordering phenomenon
There's an interesting phenomenon. Heating up the region #5 heats up the region #14, but heating up the region #14 doesn't heat up the region #5. This runs contrary to a sensible implementation of real life physics. 

I marked the assymetric bordering phenomenon on the map with arrows. An arrow with "Y" means "Yes, heating up this region heats up the neighbour" and an arrow with "N" means "No, heating up this region doesn't heat up the neighbour" 

# Coming to a model for this problem

This problem can be represented using the graph theory.

![](img/Regions.svg)
*Regions abstracted away from the minigame*

![](img/Regions%20with%20arrows.svg)
*An intermediate step in transformation from regions to a graph*

![](img/Graph.svg)
*A graph representation of regions*

An edge from node A to node B means "Heating up node A heats up node B a little, too"

# What's next
- [ ] nicen up the formatting of this readme
    - [ ] maybe show an example of heating (from 0h to 3h)
- [ ] represent the graph as an adjacency matrix
- [ ] implement the brute force method to find the results
- [ ] present the results in readme