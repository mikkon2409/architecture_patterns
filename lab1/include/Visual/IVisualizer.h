#pragma once
#include "Geometry/IPoint.h"

namespace Visual {

	class IVisualizer {
	public:
		virtual void DrawLine(Geometry::IPoint* p1, Geometry::IPoint* p2) = 0;
		virtual void DrawCircle(Geometry::IPoint* p, int rad) = 0;
	};

}