#pragma once
#include "bitmap_image.hpp"
#include "IVisualizer.h"


namespace Visual
{

	class BitMapVisualizer : public IVisualizer {
		bitmap_image& context;
		image_drawer* drawer;
	public:
		BitMapVisualizer(bitmap_image& context) : context(context) {
			drawer = new image_drawer(this->context);
		}

		void DrawLine(Geometry::IPoint* p1, Geometry::IPoint* p2) override {
			drawer->pen_width(1);
			drawer->pen_color(0, 255, 0);
			drawer->line_segment(
				static_cast<int>(p1->getX()), static_cast<int>(p1->getY()), 
				static_cast<int>(p2->getX()), static_cast<int>(p2->getY())
			);
		}

		void DrawCircle(Geometry::IPoint* p) override {
			drawer->pen_width(1);
			drawer->pen_color(0, 255, 0);
			drawer->circle(static_cast<int>(p->getX()), static_cast<int>(p->getY()), 4);
		}

		~BitMapVisualizer() {
			delete drawer;
		}
	};

}