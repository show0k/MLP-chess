# Description
My Little Poney Chess game is an humouristic c++ game made for a school project.

# Backend
Engine and GUI are two separated programms which are communicating throw a pipe with a protocol based on Unified Chess Interface (described in api_specification.txt).
You can play on terminal with ./engine/chessEngine.out -t

Graphic interface is made with SFML library.

# Run
* To run on linux (or Mac but untested), use ./run.sh.
* To run on windows you just have to adapt run.sh to make the pipe

# Build
You have to execute Makefiles in GUI and engine directories, or run build.sh

# Licence
You can do whatever you want with the sources files. For more information, see the below LICENCE file

Théo & Edouard