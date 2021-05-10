#include "thirdparty/bitmap_image.hpp"

#include "Visual/VisualLine.h"
#include "Visual/VisualBezier.h"
#include "Visual/OStreamVisualizer.h"
#include "Visual/BitMapVisualizer.h"
#include "Visual/FirstVisualizationScheme.h"
#include "Geometry/Fragment.h"

int main() {
	Geometry::IPoint* a = new Geometry::Point;
	Geometry::IPoint* b = new Geometry::Point;
	Geometry::IPoint* c = new Geometry::Point;
	Geometry::IPoint* d = new Geometry::Point;

	a->setX(360.0f);
	a->setY(20.0f);
	b->setX(400.0f);
	b->setY(400.0f);
	c->setX(270.0f);
	c->setY(350.0f);
	d->setX(300.0f);
	d->setY(120.0f);

	Geometry::Line line(a, b);
	Geometry::Bezier bezier(a, b, c, d);

	Geometry::Fragment lineFragment(&line, 0.0, 1.0);
	Visual::VisualLine visualLine(&lineFragment);
	Visual::VisualBezier visualBezier(&bezier);

	bitmap_image image(500, 500);
	Visual::OStreamVisualizer vis(std::cout);
	Visual::BitMapVisualizer bitMapVisualizer(image);
	Visual::FirstVisualizationScheme visualizationScheme(&bitMapVisualizer);
	Visual::FirstVisualizationScheme visualizationSchemeConsole(&vis);

	visualLine.Draw(&visualizationScheme, 10);
	//visualBezier.Draw(&visualizationScheme, 10);

	visualLine.Draw(&visualizationSchemeConsole, 10);
	//visualBezier.Draw(&visualizationSchemeConsole, 10);

	image.save_image("output1.bmp");

	return 0;
}
