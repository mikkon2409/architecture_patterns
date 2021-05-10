#pragma once
#include "IPoint.h"

namespace Geometry
{

	class ICurve {
	public:
		virtual void GetPoint(double t, IPoint* p) = 0;
	};

}