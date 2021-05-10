#pragma once
#include "ACurveDecorator.h"
#include "Point.h"

namespace Geometry
{
	class Fragment : public ACurveDecorator {
		double t_start;
		double t_finish;
	public:
		Fragment(ICurve* wrapped, double t_start, double t_finish) : t_start(t_start), t_finish(t_finish) {
			this->wrapped = wrapped;
		}

		void GetPoint(double t, IPoint* p) override {
			double delta_t = t_finish - t_start;
			double tmp_t = t_start + delta_t * t;
			wrapped->GetPoint(tmp_t, p);
		}
	};
}