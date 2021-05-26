#pragma once
#include "Geometry/ICurve.h"
#include "IDrawable.h"
#include "Geometry/Point.h"

namespace Visual
{

	class VisualCurve final : public Geometry::ICurve, public IDrawable {
		Geometry::ICurve* curve;
		int n;

		void GetPoint(double t, Geometry::IPoint* p) override {
			curve->GetPoint(t, p);
		}
	public:
		VisualCurve() = delete;
		VisualCurve(Geometry::ICurve* curve, int n) : curve(curve), n(n) {}
		
		void Draw(IVisualizationScheme* context) override {
			for (int i = 0; i <= n - 1; i++) {
				Geometry::Point p1;
				Geometry::Point p2;
				double t1 = static_cast<double>(i) / static_cast<double>(n);
				double t2 = (static_cast<double>(i) + 1) / static_cast<double>(n);
				GetPoint(t1, &p1);
				GetPoint(t2, &p2);
				context->DrawLineralizedSegment(&p1, &p2);
			}
			{
				Geometry::Point p;
				GetPoint(.0f, &p);
				context->DrawStartPoint(&p);
			}
			{
				Geometry::Point p;
				GetPoint(1.f, &p);
				context->DrawEndPoint(&p);
			}
		}
	};

}