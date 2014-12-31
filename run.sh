#!/bin/bash   
echo 'Start the Chess program. Enjoy !'

# On redirige la sortie de l'engine sur l'entrée du la GUI,et inversement

cd GUI/
# dirty remove named pipes
rm fifo* 2>/dev/null

# tosolve some bugs
pkill GUI


mkfifo fifo0 fifo1
# ./GUI.out < fifo0 | ./../engine/chessEngine.out > fifo0 

(./../engine/chessEngine.out< fifo1| tee fifo0 )&
(./GUI.out < fifo0 | tee fifo1)&
#( exec 30<fifo0 31<fifo1 )   

trap "echo 'Chess program closed.'" SIGINT SIGTERM SIGKILL
