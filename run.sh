#!/bin/bash   
echo 'Start the Chess program. Enjoy !'

# On redirige la sortie de l'engine sur l'entrée du la GUI,et inversement

cd GUI/
rm fifo* 2>/dev/null
mkfifo fifo0 fifo1

./../engine/chessEngine.out < fifo0 | ./GUI.out  > fifo0
#( ./../engine/chessEngine.out > fifo0 > log_engine.log < fifo1 ) &
#( ./GUI.out > fifo1 > log_gui.log < fifo0 ) &
#( exec 30<fifo0 31<fifo1 )   

trap "echo 'Chess program closed.'" SIGINT SIGTERM SIGKILL
