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

	int maxPerNode = 100;
	int maxNodeDepth = 50;
	int currentDepth = 0;

	bool isLeafNode = false;

	void AddRenderables( std::vector<Renderable*> rendsToAdd, int &counter );

	void DefineSize( std::vector<Renderable*> rendsToAdd );

	bool Intersection(OctNode *node, kf::Ray r);

	//std::vector<Renderable*> ChildIntersection( OctNode *node, kf::Ray ray );

	//std::vector<Renderable*> OctTreeRayCheck( kf::Ray ray );

	std::vector<Renderable*> RayCheck( OctNode *octTree, kf::Ray ray );
	void ProcSubtree( std::vector<Renderable*> &rends, OctNode *node, kf::Ray ray );


	//void ProcSubtree( std::vector<Renderable*> &rends, float tx0, float ty0, float tz0, float tx1, float ty1, float tz1, OctNode *node );
};

#endif