#pragma once
#include "VisualCurve.h"
#include "Geometry/Line.h"

namespace Visual
{

	class VisualLine : public VisualCurve {
		Geometry::ICurve* line;
	public:
		VisualLine(Geometry::ICurve* line) : line(line) {}
		void GetPoint(double t, Geometry::IPoint* p) override {
			line->GetPoint(t, p);
		}
	};

}