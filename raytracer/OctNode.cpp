#include "OctNode.h"



OctNode::OctNode()
{
}


OctNode::~OctNode()
{
}

void OctNode::AddedRenderables(std::vector<Renderable*> rendsToAdd)
{
	// If not at max depth and too many rends for one node
	if( currentDepth <= maxNodeDepth && rendsToAdd.size > maxPerNode )
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
		for( std::vector<Renderable*>::iterator it = rendsToAdd.begin; it != rendsToAdd.end(); ++it )
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

		children[ 0 ].AddedRenderables( frontTopLeftRends );
		children[ 1 ].AddedRenderables( frontTopRightRends );
		children[ 2 ].AddedRenderables( frontBotLeftRends );
		children[ 3 ].AddedRenderables( frontBotRightRends );

		children[ 4 ].AddedRenderables( backTopLeftRends );
		children[ 5 ].AddedRenderables( backTopRightRends );
		children[ 6 ].AddedRenderables( backBotLeftRends );
		children[ 7 ].AddedRenderables( backBotRightRends );
	}
	// If at max depth, add all renderables to node
	else
	{
		isLeafNode = true;
		for( std::vector<Renderable*>::iterator it = rendsToAdd.begin; it != rendsToAdd.end(); ++it )
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
	for( std::vector<Renderable*>::iterator it = rendsToAdd.begin; it != rendsToAdd.end(); ++it )
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
