#include "OctNode.h"
#include "kf\kf_algorithms.h"
#include "omp.h"



OctNode::OctNode()
{
}


OctNode::~OctNode()
{
	for( int index = 0; index < children.size(); ++index )
	{
		delete children[ index ];
	}
}

bool OctNode::sortVec ( Renderable* i, Renderable* j ) 
{
	return ( i->m_position < j->m_position ); 
}

void OctNode::AddRenderables( std::vector<Renderable*> rendsToAdd, int &counter )
{
	// If not at max depth and too many rends for one node
	if( currentDepth < maxNodeDepth && rendsToAdd.size() > maxPerNode )
	{
		//printf( "    Parent %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", currentDepth, position.x, position.y, position.z,
			//bounds.x, bounds.y, bounds.z );

		// Set up children
		{
			for( int index = 0; index < 8; ++index )
			{
				children.push_back( new OctNode() );
			}

			// Front Top Left
			children[0]->position.x = position.x;
			children[0]->position.y = position.y + ( bounds.y / 2 );
			children[0]->position.z = position.z;
			children[0]->bounds.x = bounds.x / 2;
			children[0]->bounds.y = bounds.y / 2;
			children[0]->bounds.z = bounds.z / 2;
			children[0]->currentDepth = currentDepth + 1;

			//printf( "ftl Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 0, children[0]->position.x, children[0]->position.y, children[0]->position.z,
					//children[0]->bounds.x, children[0]->bounds.y, children[0]->bounds.z );

			// Front Top Right
			children[1]->position.x = position.x + ( bounds.x / 2 );
			children[1]->position.y = position.y + ( bounds.y / 2 );
			children[1]->position.z = position.z;
			children[1]->bounds.x = bounds.x / 2;
			children[1]->bounds.y = bounds.y / 2;
			children[1]->bounds.z = bounds.z / 2;
			children[1]->currentDepth = currentDepth + 1;

			//printf( "ftr Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 1, children[1]->position.x, children[1]->position.y, children[1]->position.z,
				//children[1]->bounds.x, children[1]->bounds.y, children[1]->bounds.z );

			// Front Bot Left
			children[2]->position.x = position.x;
			children[2]->position.y = position.y;
			children[2]->position.z = position.z;
			children[2]->bounds.x = bounds.x / 2;
			children[2]->bounds.y = bounds.y / 2;
			children[2]->bounds.z = bounds.z / 2;
			children[2]->currentDepth = currentDepth + 1;

			//printf( "fbl Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 2, children[2]->position.x, children[2]->position.y, children[2]->position.z,
				//children[2]->bounds.x, children[2]->bounds.y, children[2]->bounds.z );

			// Front Bot Right
			children[3]->position.x = position.x + ( bounds.x / 2 );
			children[3]->position.y = position.y;
			children[3]->position.z = position.z;
			children[3]->bounds.x = bounds.x / 2;
			children[3]->bounds.y = bounds.y / 2;
			children[3]->bounds.z = bounds.z / 2;
			children[3]->currentDepth = currentDepth + 1;

			//printf( "fbr Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 3, children[3]->position.x, children[3]->position.y, children[3]->position.z,
				//children[3]->bounds.x, children[3]->bounds.y, children[3]->bounds.z );
			
		/*  ===  */

			// Back Top Left
			children[4]->position.x = position.x;
			children[4]->position.y = position.y + ( bounds.y / 2 );
			children[4]->position.z = position.z + ( bounds.z / 2 );
			children[4]->bounds.x = bounds.x / 2;
			children[4]->bounds.y = bounds.y / 2;
			children[4]->bounds.z = bounds.z / 2;
			children[4]->currentDepth = currentDepth + 1;

			//printf( "btl Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 4, children[4]->position.x, children[4]->position.y, children[4]->position.z,
				//children[4]->bounds.x, children[4]->bounds.y, children[4]->bounds.z );

			// Back Top Right
			children[5]->position.x = position.x + ( bounds.x / 2 );
			children[5]->position.y = position.y + ( bounds.y / 2 );
			children[5]->position.z = position.z + ( bounds.z / 2 );
			children[5]->bounds.x = bounds.x / 2;
			children[5]->bounds.y = bounds.y / 2;
			children[5]->bounds.z = bounds.z / 2;
			children[5]->currentDepth = currentDepth + 1;

			//printf( "btr Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 5, children[5]->position.x, children[5]->position.y, children[5]->position.z,
				//children[5]->bounds.x, children[5]->bounds.y, children[5]->bounds.z );

			// Back Bot Left
			children[6]->position.x = position.x;
			children[6]->position.y = position.y;
			children[6]->position.z = position.z + ( bounds.z / 2 );
			children[6]->bounds.x = bounds.x / 2;
			children[6]->bounds.y = bounds.y / 2;
			children[6]->bounds.z = bounds.z / 2;
			children[6]->currentDepth = currentDepth + 1;

			//printf( "bbl Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 6, children[6]->position.x, children[6]->position.y, children[6]->position.z,
				//children[6]->bounds.x, children[6]->bounds.y, children[6]->bounds.z );

			// Back Bot Right
			children[7]->position.x = position.x + ( bounds.x / 2 );
			children[7]->position.y = position.y;
			children[7]->position.z = position.z + ( bounds.z / 2 );
			children[7]->bounds.x = bounds.x / 2;
			children[7]->bounds.y = bounds.y / 2;
			children[7]->bounds.z = bounds.z / 2;
			children[7]->currentDepth = currentDepth + 1;

			//printf( "bbr Child  %d. x: % 5.1f, y: % 5.1f, z: % 5.1f | w: % 5.1f, h: % 5.1f, d: % 5.1f \n", 7, children[7]->position.x, children[7]->position.y, children[7]->position.z,
				//children[7]->bounds.x, children[7]->bounds.y, children[7]->bounds.z );
		}


		std::vector<Renderable*> frontTopLeftRends;
		std::vector<Renderable*> frontTopRightRends;
		std::vector<Renderable*> frontBotLeftRends;
		std::vector<Renderable*> frontBotRightRends;

		std::vector<Renderable*> backTopLeftRends;
		std::vector<Renderable*> backTopRightRends;
		std::vector<Renderable*> backBotLeftRends;
		std::vector<Renderable*> backBotRightRends;

		// Loop through all rends to add
		for( std::vector<Renderable*>::iterator it = rendsToAdd.begin(); it != rendsToAdd.end(); ++it )
		{
			float sphTop, sphBottom, sphBack, sphFront, sphLeft, sphRight;
			sphTop    = (*it)->m_position.y + (*it)->m_radius;
			sphBottom = (*it)->m_position.y - (*it)->m_radius;
			sphLeft   = (*it)->m_position.x - (*it)->m_radius;
			sphRight  = (*it)->m_position.x + (*it)->m_radius;
			sphBack   = (*it)->m_position.z + (*it)->m_radius;
			sphFront  = (*it)->m_position.z - (*it)->m_radius;

			// Back
			if( sphBack > position.z + (bounds.z * 0.5) )
			{
				// Top
				if( sphTop > position.y + (bounds.y * 0.5) )
				{
					// Right
					if( sphRight > position.x + (bounds.x * 0.5) )
					{
						backTopRightRends.push_back( *it );
					}
					// Left
					if( sphLeft <  position.x + (bounds.x * 0.5) )
					{
						backTopLeftRends.push_back( *it );
					}
				}
				// Bot
				if( sphBottom < position.y + (bounds.y * 0.5) )
				{
					// Right
					if( sphRight > position.x + (bounds.x * 0.5) )
					{
						backBotRightRends.push_back( *it );
					}
					// Left
					if( sphLeft <  position.x + (bounds.x * 0.5) )
					{
						backBotLeftRends.push_back( *it );
					}
				}
			}
			// Front
			if( sphFront < position.z + (bounds.z * 0.5) )
			{
				// Top
				if( sphTop > position.y + (bounds.y * 0.5) )
				{
					// Right
					if( sphRight > position.x + (bounds.x * 0.5) )
					{
						frontTopRightRends.push_back( *it );
					}
					// Left
					if( sphLeft <  position.x + (bounds.x * 0.5) )
					{
						frontTopLeftRends.push_back( *it );
					}
				}
				// Bot
				if( sphBottom < position.y + (bounds.y * 0.5) )
				{
					// Right
					if( sphRight > position.x + (bounds.x * 0.5) )
					{
						frontBotRightRends.push_back( *it );
					}
					// Left
					if( sphLeft <  position.x + (bounds.x * 0.5) )
					{
						frontBotLeftRends.push_back( *it );
					}
				}
			}
		}
		if( frontTopLeftRends.size() > 0 )
		{
			std::sort( frontTopLeftRends.begin(), frontTopLeftRends.end() );
			children[ 0 ]->AddRenderables( frontTopLeftRends, counter );
		}
		if( frontTopRightRends.size() > 0 )
		{
			std::sort( frontTopRightRends.begin(), frontTopRightRends.end() );
			children[ 1 ]->AddRenderables( frontTopRightRends, counter );
		}
		if( frontBotLeftRends.size() > 0 )
		{
			std::sort( frontBotLeftRends.begin(), frontBotLeftRends.end() );
			children[ 2 ]->AddRenderables( frontBotLeftRends, counter );
		}
		if( frontBotRightRends.size() > 0 )
		{
			std::sort( frontBotRightRends.begin(), frontBotRightRends.end() );
			children[ 3 ]->AddRenderables( frontBotRightRends, counter );
		}

		if( backTopLeftRends.size() > 0 )
		{
			std::sort( backTopLeftRends.begin(), backTopLeftRends.end() );
			children[ 4 ]->AddRenderables( backTopLeftRends, counter );
		}
		if( backTopRightRends.size() > 0 )
		{
			std::sort( backTopRightRends.begin(), backTopRightRends.end() );
			children[ 5 ]->AddRenderables( backTopRightRends, counter );
		}
		if( backBotLeftRends.size() > 0 )
		{
			std::sort( backBotLeftRends.begin(), backBotLeftRends.end() );
			children[ 6 ]->AddRenderables( backBotLeftRends, counter );
		}
		if( backBotRightRends.size() > 0 )
		{
			std::sort( backBotRightRends.begin(), backBotRightRends.end() );
			children[ 7 ]->AddRenderables( backBotRightRends, counter );
		}
	}
	// If at max depth, add all renderables to node
	else
	{
		isLeafNode = true;
		for( std::vector<Renderable*>::iterator it = rendsToAdd.begin(); it != rendsToAdd.end(); ++it )
		{
			rends.push_back( *it );
			++counter;

			//printf( "Current Depth: %d\n", currentDepth );
			//printf( "Rends count: %d\n", rends.size() );
		}
	}
}

void OctNode::DefineSize(std::vector<Renderable*> rendsToAdd)
{
	float x = FLT_MAX;
	float y = FLT_MAX;
	float z = FLT_MAX;
	float width  = 0;
	float height = 0;
	float depth  = 0;

	// Loop through all rends to add
	for( std::vector<Renderable*>::iterator it = rendsToAdd.begin(); it != rendsToAdd.end(); ++it )
	{
		float sphTop, sphBottom, sphBack, sphFront, sphLeft, sphRight;
		sphTop    = (*it)->m_position.y + (*it)->m_radius;
		sphBottom = (*it)->m_position.y - (*it)->m_radius;
		sphLeft   = (*it)->m_position.x - (*it)->m_radius;
		sphRight  = (*it)->m_position.x + (*it)->m_radius;
		sphBack   = (*it)->m_position.z + (*it)->m_radius;
		sphFront  = (*it)->m_position.z - (*it)->m_radius;


		if( sphLeft < x )
			x = sphLeft;

		if( sphBottom < y )
			y = sphBottom;

		if( sphFront < z )
			z = sphFront;


		if( sphRight > width )
			width = sphRight;

		if( sphTop > height )
			height = sphTop;

		if( sphBack > depth )
			depth = sphBack;
	}

	position.x = x;
	position.y = y;
	position.z = z;
	
	bounds.x = width  - x;
	bounds.y = height - y;
	bounds.z = depth  - z;
}

bool OctNode::Intersect(const kf::Ray & r, float t0, float t1) const
{
	//return true;
	float tmin, tmax, tymin, tymax, tzmin, tzmax;

	kf::Vector3 parameters[2];
	int sign[3];

	parameters[0] = position;
	parameters[1] = position + bounds;
	kf::Vector3 deltaSign = 1-r.delta().sign().saturated();
	sign[0] = deltaSign.x;
	sign[1] = deltaSign.y;
	sign[2] = deltaSign.z;

	kf::Vector3 inv_direction = 1.0 / r.delta();

	tmin = (parameters[sign[0]].x - r.start().x) * inv_direction.x;
	tmax = (parameters[1-sign[0]].x - r.start().x) * inv_direction.x;
	tymin = (parameters[sign[1]].y - r.start().y) * inv_direction.y;
	tymax = (parameters[1-sign[1]].y - r.start().y) * inv_direction.y;
	if ( (tmin > tymax) || (tymin > tmax) ) 
		return false;
	if (tymin > tmin)
		tmin = tymin;
	if (tymax < tmax)
		tmax = tymax;
	tzmin = (parameters[sign[2]].z - r.start().z) * inv_direction.z;
	tzmax = (parameters[1-sign[2]].z - r.start().z) * inv_direction.z;
	if ( (tmin > tzmax) || (tzmin > tmax) ) 
		return false;
	if (tzmin > tmin)
		tmin = tzmin;
	if (tzmax < tmax)
		tmax = tzmax;
	return ( (tmin < t1) && (tmax > t0) );

	return false;
}

void OctNode::RayTrace( HitPoint &hp, kf::Ray ray )
{
	if( isLeafNode )
	{
		for (unsigned int i = 0; i < rends.size(); ++i)
		{
			// Find the nearest intersect point.
			hp.nearest(rends[i]->intersect(ray));
		}
		return;
	}

	for( int childIndex = 0; childIndex < children.size(); ++childIndex )
	{
		if( children[childIndex]->Intersect( ray, -1000, FLT_MAX ) )
		{
			children[childIndex]->RayTrace( hp, ray );
		}
	}
}