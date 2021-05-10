#pragma once
#include "ICurve.h"

namespace Geometry
{
	class ACurveDecorator : public ICurve {
	protected:
		ICurve* wrapped;
	};
}