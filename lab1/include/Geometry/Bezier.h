#pragma once
#include "ICurve.h"
#include <cmath>

namespace Geometry
{

	class Bezier : public ICurve {
		IPoint* a;
		IPoint* b;
		IPoint* c;
		IPoint* d;
	public:
		Bezier(IPoint* a, IPoint* b, IPoint* c, IPoint* d) : a(a), b(b), c(c), d(d) {};
		void GetPoint(double t, IPoint* p) override {
			double x = pow(1 - t, 3) * a->getX() + 3 * t * pow(1 - t, 2) * c->getX() + 3 * t * t * (1 - t) * d->getX() + pow(t, 3) * b->getX();
			double y = pow(1 - t, 3) * a->getY() + 3 * t * pow(1 - t, 2) * c->getY() + 3 * t * t * (1 - t) * d->getY() + pow(t, 3) * b->getY();
			p->setX(x);
			p->setY(y);
		}
	};

}