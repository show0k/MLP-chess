#ifndef _iostream
#define _iostream 1

#include <iostream>

#endif


class Point2I{
	private:
		int x;
		int y;
	
	public:
		Point2I(int, int);
		Point2I();
		int getX();
		int getY();
		void setX(int);
		void setY(int);
};

