#!/bin/bash   
echo 'Start the Chess program'

# On redirige la sortie de l'engine sur l'entrée du la GUI,et inversement

mkfifo fifo0 fifo1
( ./engine/chessEngine.out > fifo0 < fifo1 ) &
( ./GUI/GUI.out > fifo1 < fifo0 ) &
( exec 30<fifo0 31<fifo1 )   


