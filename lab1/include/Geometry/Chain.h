#pragma once
#include "ICurve.h"
#include "MoveTo.h"

namespace Geometry
{

	class Chain : public ICurve {
		ICurve* first;
		ICurve* second;
	public:
		Chain(ICurve* first, ICurve* second) : first(first) {
			Point p;
			this->first->GetPoint(1, &p);
			this->second = new MoveTo(second, &p);
		}
		void GetPoint(double t, IPoint* p) override {
			if (t < 0.5) {
				first->GetPoint(t * 2, p);
			}
			else {
				second->GetPoint(2 * t - 1, p);
			}
		}
		~Chain() {
			delete second;
		}
	};

}