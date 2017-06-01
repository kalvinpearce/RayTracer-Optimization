#ifndef OCTNODE_H
#define OCTNODE_H
#include <vector>
#include "kf/kf_vector.h"
#include "renderable.h"
#include <algorithm>

class OctNode
{
public:
	OctNode();
	~OctNode();

	std::vector<Renderable*> rends;

	std::vector<OctNode*> children;

	kf::Vector3 position;
	kf::Vector3 bounds;

	int maxPerNode = 50;
	int maxNodeDepth = 10;
	int currentDepth = 0;

	bool isLeafNode = false;

	bool sortVec ( Renderable* i, Renderable* j );

	void AddRenderables( std::vector<Renderable*> rendsToAdd, int &counter );

	void DefineSize( std::vector<Renderable*> rendsToAdd );

	bool Intersect(const kf::Ray &r, float t0, float t1) const;

	void RayTrace( HitPoint &hp, kf::Ray ray );
};

#endif