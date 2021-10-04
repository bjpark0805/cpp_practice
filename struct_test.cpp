#include <iostream>

typedef struct __Point{
	int xpos;
	int ypos;
} Point;

Point& pntAdder(const Point &p1, const Point &p2){
	Point *p = new Point;
	p->xpos = p1.xpos + p2.xpos;
	p->ypos = p1.ypos + p2.ypos;
	return *p; 
}
int main(){
	Point *p1 = new Point, *p2 = new Point;
	p1->xpos = 1, p1->ypos = 2;
	p2->xpos = 3, p2->ypos = 4;
	Point& p = pntAdder(*p1, *p2);
	std::cout << p.xpos << " " << p.ypos << std::endl;
	return 0;
}