#pragma once
#include <ostream>
#include "IVisualizer.h"

namespace Visual
{

	class OStreamVisualizer : public IVisualizer {
		std::ostream& context;
	public:
		OStreamVisualizer(std::ostream& context) : context(context) {}
		void DrawLine(Geometry::IPoint* p1, Geometry::IPoint* p2) override {
			context << "Line:\t" << p1->getX() << ", " << p1->getY() << "  <<>>  " << p2->getX() << ", " << p2->getY() << std::endl;
		}
		void DrawCircle(Geometry::IPoint* p, int rad) override {
			context << "Circle:\t" << p->getX() << ", " << p->getY() << ", " << rad << std::endl;
		}
	};

}