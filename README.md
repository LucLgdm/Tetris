This Tetris game is a real time game.  
It's a classical game : you earn points when you make a line with bricks which falls from the sky.  
The more you earn points, the faster the game is.  

The basis element of the game is brick (brique.h)  
With the bricks you can build a game board (plateau.h)  
and the pieces : piece.h as mother classe and piece1.h... as daugther classes.  
In order to simulate the time and the speed of the pieces, I used the KernelSynchronizer class.  
util.h is a usefull class to make som calculation.  

Here is the commande to lunch the game, you need the SDL library and the OpenGL library :  
  g++ -o tetris Brique.cpp Kernelsy.cpp main.cpp Piece.cpp Piece1.cpp Piece2.cpp Piece3.cpp Piece4.cpp Piece5.cpp Piece6.cpp Piece7.cpp Plateau.cpp Tetris.cpp util.cpp -lSDLmain -lSDL -lGLU -lGL -lSDL_ttf
./tetris
