#pragma once
#include "IPoint.h"

namespace Geometry
{

	class Point : public IPoint {
		double x;
		double y;
	public:
		double getX() { return x; }
		double getY() { return y; }
		void setX(double x) { this->x = x; }
		void setY(double y) { this->y = y; }
	};

}