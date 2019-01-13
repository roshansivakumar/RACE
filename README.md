# RACE - Raspeberry Pi and Arduino Chess Educational game

                                                       1. Introduction 

The goal of this project was to create a physical chessboard that is able to interact with a human player, robotic arm and a computer. The game begins when the human player makes a move. The move played by both the robot and the human are fed into a chess engine after being detected by sensors embedded into the chessboard. The chess engine replies with a move, giving the piece’s current location and the location to be moved to. The robotic arm moves the piece to the desired position and returns back to its default position to await the human players’ next move. 

There are three main parts to this project: 
1.  Design of the chessboard in order to detect the move played 
2.  Interfacing the chess engine( Stockfish –  a UCI chess engine) 
3.  Design and fabrication of the robotic arm

                                                     2. Problem Statement
                                                     
The purpose of the project was to create a robot playing chess game where anyone can play against a robot. This is intended to be used by students/kids to learn the nuances of robotics, magnetic sensors, circuits, and chess moves. There have been many projects that have been done on chessboards. None of the ones I have referred (highlighted in References) have addressed the project looking at the following aspects: 
1.  Cost effectiveness of the solution 
2.  Robustness of the solution 
3.  Ease of implementation 
4.  Explanation of mechanics 
5.  Usability by young kids 
6.  Reusability of the solution for future projects 
The solution that will be designed has to address all of the 6 aspects.
