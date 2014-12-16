#include "GraphicElement.h"

class ClickableELement : public GraphicElement{
	private:
		Point2I pointDebut, pointFin;
	
	public:
		//ClickableELement(): GraphicElement();
		ClickableELement();
		virtual void setStartPoint(Point2I p);
		void setEndPoint(Point2I p);
		void pressed();
		void clicked();
		void released();
		void wheeled();
};
