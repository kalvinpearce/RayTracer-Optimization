#ifndef OCTNODE_H
#define OCTNODE_H
#include <vector>
#include "kf/kf_vector.h"
#include "renderable.h"

class OctNode
{
public:
	OctNode();
	~OctNode();

	std::vector<Renderable*> rends;

	std::vector<OctNode> children;

	kf::Vector3 position;
	kf::Vector3 bounds;

	int maxPerNode = 10;
	int maxNodeDepth = 50;
	int currentDepth = 0;

	bool isLeafNode = false;

	void AddedRenderables( std::vector<Renderable*> rendsToAdd );
};

#endif