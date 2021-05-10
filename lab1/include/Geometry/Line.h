#pragma once
#include "ICurve.h"

namespace Geometry
{

	class Line : public ICurve {
		IPoint* a;
		IPoint* b;
	public:
		Line(IPoint* a, IPoint* b) :a(a), b(b) {};
		void GetPoint(double t, IPoint* p) override {
			double x = (1 - t) * a->getX() + t * b->getX();
			double y = (1 - t) * a->getY() + t * b->getY();
			p->setX(x);
			p->setY(y);
		}
	};

}