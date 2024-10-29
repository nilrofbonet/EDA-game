## EDA game
Data structure and Algorithms

# How to run this game
1) Open a console and cd to the directory where you extracted the source code.

2) If, for example, you are using Linux, run:
```
cp AIDummy.o.Linux AIDummy.o
cp Board.o.Linux Board.o
```

3) Run
```
make all
```
to build the game and all the players. Note that Makefile identifies as a player
any file matching AI*.cc.

4) This creates an executable file called Game. This executable allows you to run
a game using a command like:
```
./Game Demo Demo Demo Demo -s 30 -i default.cnf -o default.res
```
This starts a match, with random seed 30, of four instances of the player Demo,
in the board defined in default.cnf. The output of this match is redirected to
default.res.

5) To watch a game, open the viewer file viewer.html with your browser and
load the file default.res.

## Players
The winner of all the players I created was AIgema.cc. I finished on the top 90% of the players.