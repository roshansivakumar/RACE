# RACE - Raspeberry Pi and Arduino Chess Educational game

                                                       About The Project

The goal of this project was to create a physical chessboard that is able to interact with a human player, robotic arm and a computer. The game begins when the human player makes a move. The move played by both the robot and the human are fed into a chess engine after being detected by sensors embedded into the chessboard. The chess engine replies with a move, giving the piece’s current location and the location to be moved to. The robotic arm moves the piece to the desired position and returns back to its default position to await the human players’ next move. 

There are three main parts to this project: 
1.  Design of the chessboard in order to detect the move played 
2.  Interfacing the chess engine( Stockfish –  a UCI chess engine) 
3.  Design and fabrication of the robotic arm


                                                         About The Code 
                                                          
**StockfishPy.py**

This is the python code that runs on the Raspberry Pi.
The code receives the move scanned by the sensory chessboard and first checks if the move is valid or not. If the move is valid it sends the move in SAN notation to the Stockfish chess engine and retreives the next move that the computer/robot should play. If the move is invalid then a character is sent back to the arduino which in turn turns on an LED notifying the player that a wrong move is played and allows them to play the move again.
Additional Functionality: A switch can be turned on which enables assistance mode. So, if the player plays a wrong move the computer will display a list of possible moves that the player can make with the piece they moved wrongly.

**ArduinoCode.ino**




**ArduniDisplay.ino**



**FENgeneration.py**
