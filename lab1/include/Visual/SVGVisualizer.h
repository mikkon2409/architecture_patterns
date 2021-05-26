#pragma once
#include <iostream>
#include "IVisualizer.h"

namespace Visual
{

	class SVGVisualizer : public IVisualizer {
		std::ofstream& context;
	public:
		SVGVisualizer(std::ofstream& context) : context(context) {
			this->context << "<svg version=\"1.1\" baseProfile = \"full\" width = \"500\" height = \"500\" xmlns = \"http://www.w3.org/2000/svg\">" << std::endl;
		}
		void DrawLine(Geometry::IPoint* p1, Geometry::IPoint* p2) override {
			context << "<line x1 = \"" << p1->getX() << "\" y1 = \"" << p1->getY() << "\" x2 = \"" << p2->getX() << "\" y2 = \"" << p2->getY() << "\" stroke=\"#000000\" stroke-width=\"1\"></line>" << std::endl;
		}
		void DrawCircle(Geometry::IPoint* p, int rad) override {
			context << "<circle cx = \"" << p->getX() << "\" cy = \"" << p->getY() << "\" r = \"" << rad << "\"></circle>" << std::endl;
		}
		void FinalizeFile() {
			context << "</svg>" << std::endl;
		}
	};

}