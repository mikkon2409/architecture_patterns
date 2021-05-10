#pragma once
#include "ACurveDecorator.h"
#include "Point.h"

namespace Geometry
{
	class MoveTo : public ACurveDecorator {
		Point deltaXY;
	public:
		MoveTo(ICurve* wrapped, IPoint* p) {
			this->wrapped = wrapped;
			Point tmpP;
			this->wrapped->GetPoint(0, &tmpP);
			deltaXY.setX(p->getX() - tmpP.getX());
			deltaXY.setY(p->getY() - tmpP.getY());
		}

		void GetPoint(double t, IPoint* p) override {
			Point tmpP;
			wrapped->GetPoint(t, &tmpP);
			p->setX(tmpP.getX() + deltaXY.getX());
			p->setY(tmpP.getY() + deltaXY.getY());
		}
	};
}