class Point2I{
	private:
		int x;
		int y;
	
	public:
		Point2I(int a, int b);
		Point2I();
};

public Point2I::Point2I(int a, int b){
	x = a;
	y = b;
}

public Point2I::Point2I(){
	x = 0;
	y = 0;
}
