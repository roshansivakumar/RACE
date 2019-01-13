from stockfish import Stockfish
import subprocess
import serial

move_list = [None]*0
s1 = serial.Serial('/dev/ttyACM0', 9600)
stockfish = Stockfish('/usr/games/stockfish')
while 1 :
    while s1.inWaiting():
        if str(s1.readline(),'UTF-8').strip('\n\r') == 'start' :
            move_played = str(s1.readline(),'UTF-8').strip('\n\r')
            if(stockfish.is_move_correct(move_played) == True):
                move_list.append(move_played)
                stockfish.set_position(move_list)
                best_move = stockfish.get_best_move()
                move_list.append(best_move)
                s1.write(bytes(best_move,'ascii'))
            else :
                s1.write(bytes('NV','ascii'))
