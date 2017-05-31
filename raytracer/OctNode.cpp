#include "OctNode.h"



OctNode::OctNode()
{
}


OctNode::~OctNode()
{
}

void OctNode::AddRenderables(std::vector<Renderable*> rendsToAdd)
{
	// If not at max depth and too many rends for one node
	if( currentDepth <= maxNodeDepth && rendsToAdd.size() > maxPerNode )
	{
		// Set up children
		{
			// Front Top Left
			children[0].position.x = position.x;
			children[0].position.y = position.y + ( bounds.y / 2 );
			children[0].position.z = position.z;
			children[0].bounds.x = bounds.x / 2;
			children[0].bounds.y = bounds.y / 2;
			children[0].bounds.z = bounds.z / 2;
			children[0].currentDepth = currentDepth + 1;

			// Front Top Right
			children[1].position.x = position.x + ( bounds.x / 2 );
			children[1].position.y = position.y + ( bounds.y / 2 );
			children[1].position.z = position.z;
			children[1].bounds.x = bounds.x / 2;
			children[1].bounds.y = bounds.y / 2;
			children[1].bounds.z = bounds.z / 2;
			children[1].currentDepth = currentDepth + 1;

			// Front Bot Left
			children[2].position.x = position.x;
			children[2].position.y = position.y;
			children[2].position.z = position.z;
			children[2].bounds.x = bounds.x / 2;
			children[2].bounds.y = bounds.y / 2;
			children[2].bounds.z = bounds.z / 2;
			children[2].currentDepth = currentDepth + 1;

			// Front Bot Right
			children[3].position.x = position.x + ( bounds.x / 2 );
			children[3].position.y = position.y;
			children[3].position.z = position.z;
			children[3].bounds.x = bounds.x / 2;
			children[3].bounds.y = bounds.y / 2;
			children[3].bounds.z = bounds.z / 2;
			children[3].currentDepth = currentDepth + 1;
			
		/*  ===  */

			// Back Top Left
			children[4].position.x = position.x;
			children[4].position.y = position.y + ( bounds.y / 2 );
			children[4].position.z = position.z + ( bounds.z / 2 );
			children[4].bounds.x = bounds.x / 2;
			children[4].bounds.y = bounds.y / 2;
			children[4].bounds.z = bounds.z / 2;
			children[4].currentDepth = currentDepth + 1;

			// Back Top Right
			children[5].position.x = position.x + ( bounds.x / 2 );
			children[5].position.y = position.y + ( bounds.y / 2 );
			children[5].position.z = position.z + ( bounds.z / 2 );
			children[5].bounds.x = bounds.x / 2;
			children[5].bounds.y = bounds.y / 2;
			children[5].bounds.z = bounds.z / 2;
			children[5].currentDepth = currentDepth + 1;

			// Back Bot Left
			children[6].position.x = position.x;
			children[6].position.y = position.y;
			children[6].position.z = position.z + ( bounds.z / 2 );
			children[6].bounds.x = bounds.x / 2;
			children[6].bounds.y = bounds.y / 2;
			children[6].bounds.z = bounds.z / 2;
			children[6].currentDepth = currentDepth + 1;

			// Back Bot Right
			children[7].position.x = position.x + ( bounds.x / 2 );
			children[7].position.y = position.y;
			children[7].position.z = position.z + ( bounds.z / 2 );
			children[7].bounds.x = bounds.x / 2;
			children[7].bounds.y = bounds.y / 2;
			children[7].bounds.z = bounds.z / 2;
			children[7].currentDepth = currentDepth + 1;
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
			// Back
			if( (*it)->m_position.z >= position.z + bounds.z * 0.5 )
			{
				// Top
				if( (*it)->m_position.y >= position.y + bounds.y * 0.5 )
				{
					// Right
					if( (*it)->m_position.x >= position.x + bounds.x * 0.5 )
					{
						backTopRightRends.push_back( *it );
					}
					// Left
					else
					{
						backTopLeftRends.push_back( *it );
					}
				}
				// Bot
				else
				{
					// Right
					if( (*it)->m_position.x >= position.x + bounds.x * 0.5 )
					{
						backBotRightRends.push_back( *it );
					}
					// Left
					else
					{
						backBotLeftRends.push_back( *it );
					}
				}
			}
			// Front
			else
			{
				// Top
				if( (*it)->m_position.y >= position.y + bounds.y * 0.5 )
				{
					// Right
					if( (*it)->m_position.x >= position.x + bounds.x * 0.5 )
					{
						frontTopRightRends.push_back( *it );
					}
					// Left
					else
					{
						frontTopLeftRends.push_back( *it );
					}
				}
				// Bot
				else
				{
					// Right
					if( (*it)->m_position.x >= position.x + bounds.x * 0.5 )
					{
						frontBotRightRends.push_back( *it );
					}
					// Left
					else
					{
						frontBotLeftRends.push_back( *it );
					}
				}
			}
		}

		children[ 0 ].AddRenderables( frontTopLeftRends );
		children[ 1 ].AddRenderables( frontTopRightRends );
		children[ 2 ].AddRenderables( frontBotLeftRends );
		children[ 3 ].AddRenderables( frontBotRightRends );

		children[ 4 ].AddRenderables( backTopLeftRends );
		children[ 5 ].AddRenderables( backTopRightRends );
		children[ 6 ].AddRenderables( backBotLeftRends );
		children[ 7 ].AddRenderables( backBotRightRends );
	}
	// If at max depth, add all renderables to node
	else
	{
		isLeafNode = true;
		for( std::vector<Renderable*>::iterator it = rendsToAdd.begin(); it != rendsToAdd.end(); ++it )
		{
			rends.push_back( *it );
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
		if( (*it)->m_position.x < x )
			x = (*it)->m_position.x;

		if( (*it)->m_position.y < y )
			y = (*it)->m_position.y;

		if( (*it)->m_position.z < z )
			z = (*it)->m_position.z;


		if( (*it)->m_position.x > width )
			width = (*it)->m_position.x;

		if( (*it)->m_position.y > height )
			height = (*it)->m_position.y;

		if( (*it)->m_position.z > depth )
			depth = (*it)->m_position.z;
	}

	position.x = x;
	position.y = y;
	position.z = z;
	
	bounds.x = width;
	bounds.y = height;
	bounds.z = depth;
}

bool OctNode::Intersection( OctNode node, kf::Ray ray ) 
{
	// x plane lower and upper points of ray
	double xLower = ( node.position.x - ray.start().x ) / ( ray.end().x - ray.start().x );
	double xUpper = ( node.bounds.x   - ray.start().x ) / ( ray.end().x - ray.start().x );

	// Cut ray between x points
	// if ray is in x plane, lower should be in min, upper should be in max
	double rayCutMin = std::min( xLower, xUpper );
	double rayCutMax = std::max( xLower, xUpper );

	// y plane lower and upper points of ray
	double yLower = ( node.position.y - ray.start().y ) / ( ray.end().y - ray.start().y );
	double yUpper = ( node.bounds.y   - ray.start().y ) / ( ray.end().y - ray.start().y );

	// cut ray between y points
	rayCutMin = std::max( rayCutMin, std::min( yLower, yUpper ) );
	rayCutMax = std::min( rayCutMax, std::max( yLower, yUpper ) );

	// z plane lower and upper points of ray
	double zLower = ( node.position.z - ray.start().z ) / ( ray.end().z - ray.start().z );
	double zUpper = ( node.bounds.z   - ray.start().z ) / ( ray.end().z - ray.start().z );

	// cut ray between z points
	rayCutMin = std::max( rayCutMin, std::min( zLower, zUpper ) );
	rayCutMax = std::min( rayCutMax, std::max( zLower, zUpper ) );

	// Return true if max ray point is bigger than the min ray point
	return rayCutMax >= rayCutMin;
}
