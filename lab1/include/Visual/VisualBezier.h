#pragma once
#include "VisualCurve.h"
#include "Geometry/Bezier.h"

namespace Visual
{

	class VisualBezier : public VisualCurve {
		Geometry::ICurve* bezier;
	public:
		VisualBezier(Geometry::ICurve* bezier) : bezier(bezier) {}
		void GetPoint(double t, Geometry::IPoint* p) override {
			bezier->GetPoint(t, p);
		}
	};

}