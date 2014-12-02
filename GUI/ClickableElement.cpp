#include <SFML/Graphics.hpp>

class ClickableELement : public GraphicElement{
	private:
		Point2I pointDebut, pointFin;
	
	public:
		ClickableELement():GraphicElement();
		virtual void setStartPoint(Point2I p)
		void setEndPoint(Point2I p)
		void pressed();
		void clicked();
		void released();
		void wheeled();
}

public ClickableELement::ClickableELement(){

}

public void ClickableELement::setStartPoint(Point p){
	pointDebut.x = p.x;
	pointDebut.y = p.y;
}

public void ClickableELement::setEndPoint(Point p){
	pointFin.x = p.x;
	pointFin.y = p.y;
}


