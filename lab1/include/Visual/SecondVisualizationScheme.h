#pragma once
#include "AVisualizationScheme.h"

namespace Visual
{

	class SecondVisualizationScheme : public AVisualizationScheme
	{
	public:
		SecondVisualizationScheme(IVisualizer* visualizer) : AVisualizationScheme(visualizer) {};
		void DrawLineralizedSegment(Geometry::IPoint* p1, Geometry::IPoint* p2) {
			visualizer->DrawLine(p1, p2);
		}
		void DrawStartPoint(Geometry::IPoint* p) {
			visualizer->DrawCircle(p, 5);
		}
		void DrawEndPoint(Geometry::IPoint* p) {
			visualizer->DrawCircle(p, 2);
		}
	};

}