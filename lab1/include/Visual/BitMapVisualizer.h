#pragma once
#include "bitmap_image.hpp"
#include "IVisualizer.h"


namespace Visual
{

	class BitMapVisualizer : public IVisualizer {
		bitmap_image& context;
		image_drawer* drawer;
		unsigned int pen_width;
		unsigned char red;
		unsigned char green;
		unsigned char blue;
	public:
		BitMapVisualizer(bitmap_image& context) : context(context) {
			drawer = new image_drawer(this->context);
			pen_width = 1;
			red = 255;
			green = 255;
			blue = 255;
		}

		BitMapVisualizer(bitmap_image& context,
						unsigned int pen_width,
						unsigned char red,
						unsigned char green,
						unsigned char blue) : context(context), pen_width(pen_width), red(red), green(green), blue(blue) {
			drawer = new image_drawer(this->context);
		}

		void DrawLine(Geometry::IPoint* p1, Geometry::IPoint* p2) override {
			drawer->pen_width(pen_width);
			drawer->pen_color(red, green, blue);
			drawer->line_segment(
				static_cast<int>(p1->getX()), static_cast<int>(p1->getY()), 
				static_cast<int>(p2->getX()), static_cast<int>(p2->getY())
			);
		}

		void DrawCircle(Geometry::IPoint* p, int rad) override {
			drawer->pen_width(pen_width);
			drawer->pen_color(red, green, blue);
			drawer->circle(static_cast<int>(p->getX()), static_cast<int>(p->getY()), rad);
		}

		~BitMapVisualizer() {
			delete drawer;
		}
	};

}