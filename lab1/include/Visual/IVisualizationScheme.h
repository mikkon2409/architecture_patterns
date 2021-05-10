#pragma once
#include "Geometry/IPoint.h"

namespace Visual {

	class IVisualizationScheme {
	public:
		virtual void DrawLineralizedSegment(Geometry::IPoint* p1, Geometry::IPoint* p2) = 0;
		virtual void DrawStartPoint(Geometry::IPoint* p) = 0;
		virtual void DrawEndPoint(Geometry::IPoint* p) = 0;
	};

}