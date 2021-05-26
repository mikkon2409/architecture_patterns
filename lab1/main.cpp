#include "thirdparty/bitmap_image.hpp"

#include "Visual/VisualCurve.h"
#include "Visual/OStreamVisualizer.h"
#include "Visual/SVGVisualizer.h"
#include "Visual/BitMapVisualizer.h"
#include "Visual/FirstVisualizationScheme.h"
#include "Visual/SecondVisualizationScheme.h"
#include "Geometry/Line.h"
#include "Geometry/Bezier.h"
#include "Geometry/Fragment.h"
#include "Geometry/MoveTo.h"
#include "Geometry/Chain.h"

int main() {
	Geometry::IPoint* a = new Geometry::Point;
	Geometry::IPoint* b = new Geometry::Point;
	Geometry::IPoint* c = new Geometry::Point;
	Geometry::IPoint* d = new Geometry::Point;

	a->setX(100.0f);
	a->setY(20.0f);
	b->setX(250.0f);
	b->setY(250.0f);
	c->setX(270.0f);
	c->setY(350.0f);
	d->setX(300.0f);
	d->setY(120.0f);

	Geometry::Line line(a, b);
	Geometry::Bezier bezier(a, b, c, d);
	Geometry::Point moveToPoint;
	moveToPoint.setX(0.0);
	moveToPoint.setY(0.0);
	Geometry::Point moveToPointBezier;
	moveToPointBezier.setX(100.0);
	moveToPointBezier.setY(0.0);
	Geometry::Fragment lineFragment(&line, 0.0, 1.0);
	Geometry::MoveTo moveToLine(&lineFragment, &moveToPoint);
	Visual::VisualCurve visualLine(&moveToLine, 2);

	Geometry::Fragment backBezier(&bezier, 1.0, 0.0);
	Visual::VisualCurve visualBackBezier(&backBezier, 100);
	
	Geometry::MoveTo bezierMoveTo(&bezier, &moveToPointBezier);
	Visual::VisualCurve visualBezier(&bezierMoveTo, 100);

	Geometry::Fragment bezier1(&bezier, 0.0, 0.2);
	Geometry::Fragment backBezier1(&bezier1, 1.0, 0.0);
	Geometry::Fragment bezier2(&bezier, 0.8, 1.0);
	Geometry::Chain chain1(&moveToLine, &backBezier1);
	Geometry::Chain chain2(&chain1, &bezier2);
	Visual::VisualCurve visualChain(&chain2, 1000);

	bitmap_image image(500, 500);
	Visual::OStreamVisualizer vis(std::cout);
	std::ofstream svgFile("output.svg");
	Visual::SVGVisualizer svg(svgFile);
	Visual::BitMapVisualizer bitMapVisualizer(image);

	Visual::FirstVisualizationScheme visualizationScheme(&bitMapVisualizer);
	Visual::FirstVisualizationScheme visualizationSchemeConsole(&svg);

	Visual::SecondVisualizationScheme visualizationScheme2(&bitMapVisualizer);
	Visual::SecondVisualizationScheme visualizationScheme2SVG(&svg);
#if 0
	visualLine.Draw(&visualizationScheme2);
	visualBezier.Draw(&visualizationScheme2);
	visualBackBezier.Draw(&visualizationScheme2);

	visualLine.Draw(&visualizationScheme2SVG);
	visualBezier.Draw(&visualizationScheme2SVG);
	visualBackBezier.Draw(&visualizationScheme2SVG);
#else
	visualChain.Draw(&visualizationScheme2);
	visualChain.Draw(&visualizationScheme2SVG);
#endif

	svg.FinalizeFile();
	svgFile.close();
	image.save_image("output.bmp");

	return 0;
}
