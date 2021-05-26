#pragma once
#include "IVisualizationScheme.h"

namespace Visual
{

	class IDrawable {
	public:
		virtual void Draw(IVisualizationScheme* context) = 0;
	};

}