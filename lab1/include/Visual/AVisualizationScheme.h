#pragma once
#include "IVisualizationScheme.h"
#include "IVisualizer.h"

namespace Visual {

	class AVisualizationScheme : public IVisualizationScheme {
	protected:
		IVisualizer* visualizer;
	public:
		AVisualizationScheme(IVisualizer* visualizer) : visualizer(visualizer) {};
	};

}