#include "OctNode.h"



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

void OctNode::AddRenderables( std::vector<Renderable*> rendsToAdd, int &counter )
{
	// If not at max depth and too many rends for one node
	if( currentDepth < maxNodeDepth && rendsToAdd.size() > maxPerNode )
	{
		printf( " Parent %d. x: %f, y: %f, z: %f | w: %f, h: %f, d: %f \n", 0, position.x, position.y, position.z,
			bounds.x, bounds.y, bounds.z );

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

			printf( " Child %d. x: %f, y: %f, z: %f | w: %f, h: %f, d: %f \n", 0, children[0]->position.x, children[0]->position.y, children[0]->position.z,
					children[0]->bounds.x, children[0]->bounds.y, children[0]->bounds.z );

			// Front Top Right
			children[1]->position.x = position.x + ( bounds.x / 2 );
			children[1]->position.y = position.y + ( bounds.y / 2 );
			children[1]->position.z = position.z;
			children[1]->bounds.x = bounds.x / 2;
			children[1]->bounds.y = bounds.y / 2;
			children[1]->bounds.z = bounds.z / 2;
			children[1]->currentDepth = currentDepth + 1;

			printf( " Child %d. x: %f, y: %f, z: %f | w: %f, h: %f, d: %f \n", 1, children[1]->position.x, children[1]->position.y, children[1]->position.z,
				children[1]->bounds.x, children[1]->bounds.y, children[1]->bounds.z );

			// Front Bot Left
			children[2]->position.x = position.x;
			children[2]->position.y = position.y;
			children[2]->position.z = position.z;
			children[2]->bounds.x = bounds.x / 2;
			children[2]->bounds.y = bounds.y / 2;
			children[2]->bounds.z = bounds.z / 2;
			children[2]->currentDepth = currentDepth + 1;

			printf( " Child %d. x: %f, y: %f, z: %f | w: %f, h: %f, d: %f \n", 2, children[2]->position.x, children[2]->position.y, children[2]->position.z,
				children[2]->bounds.x, children[2]->bounds.y, children[2]->bounds.z );

			// Front Bot Right
			children[3]->position.x = position.x + ( bounds.x / 2 );
			children[3]->position.y = position.y;
			children[3]->position.z = position.z;
			children[3]->bounds.x = bounds.x / 2;
			children[3]->bounds.y = bounds.y / 2;
			children[3]->bounds.z = bounds.z / 2;
			children[3]->currentDepth = currentDepth + 1;

			printf( " Child %d. x: %f, y: %f, z: %f | w: %f, h: %f, d: %f \n", 3, children[3]->position.x, children[3]->position.y, children[3]->position.z,
				children[3]->bounds.x, children[3]->bounds.y, children[3]->bounds.z );
			
		/*  ===  */

			// Back Top Left
			children[4]->position.x = position.x;
			children[4]->position.y = position.y + ( bounds.y / 2 );
			children[4]->position.z = position.z + ( bounds.z / 2 );
			children[4]->bounds.x = bounds.x / 2;
			children[4]->bounds.y = bounds.y / 2;
			children[4]->bounds.z = bounds.z / 2;
			children[4]->currentDepth = currentDepth + 1;

			printf( " Child %d. x: %f, y: %f, z: %f | w: %f, h: %f, d: %f \n", 4, children[4]->position.x, children[4]->position.y, children[4]->position.z,
				children[4]->bounds.x, children[4]->bounds.y, children[4]->bounds.z );

			// Back Top Right
			children[5]->position.x = position.x + ( bounds.x / 2 );
			children[5]->position.y = position.y + ( bounds.y / 2 );
			children[5]->position.z = position.z + ( bounds.z / 2 );
			children[5]->bounds.x = bounds.x / 2;
			children[5]->bounds.y = bounds.y / 2;
			children[5]->bounds.z = bounds.z / 2;
			children[5]->currentDepth = currentDepth + 1;

			printf( " Child %d. x: %f, y: %f, z: %f | w: %f, h: %f, d: %f \n", 5, children[5]->position.x, children[5]->position.y, children[5]->position.z,
				children[5]->bounds.x, children[5]->bounds.y, children[5]->bounds.z );

			// Back Bot Left
			children[6]->position.x = position.x;
			children[6]->position.y = position.y;
			children[6]->position.z = position.z + ( bounds.z / 2 );
			children[6]->bounds.x = bounds.x / 2;
			children[6]->bounds.y = bounds.y / 2;
			children[6]->bounds.z = bounds.z / 2;
			children[6]->currentDepth = currentDepth + 1;

			printf( " Child %d. x: %f, y: %f, z: %f | w: %f, h: %f, d: %f \n", 6, children[6]->position.x, children[6]->position.y, children[6]->position.z,
				children[6]->bounds.x, children[6]->bounds.y, children[6]->bounds.z );

			// Back Bot Right
			children[7]->position.x = position.x + ( bounds.x / 2 );
			children[7]->position.y = position.y;
			children[7]->position.z = position.z + ( bounds.z / 2 );
			children[7]->bounds.x = bounds.x / 2;
			children[7]->bounds.y = bounds.y / 2;
			children[7]->bounds.z = bounds.z / 2;
			children[7]->currentDepth = currentDepth + 1;

			printf( " Child %d. x: %f, y: %f, z: %f | w: %f, h: %f, d: %f \n", 7, children[7]->position.x, children[7]->position.y, children[7]->position.z,
				children[7]->bounds.x, children[7]->bounds.y, children[7]->bounds.z );
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
			children[ 0 ]->AddRenderables( frontTopLeftRends, counter );
		if( frontTopRightRends.size() > 0 )
			children[ 1 ]->AddRenderables( frontTopRightRends, counter );
		if( frontBotLeftRends.size() > 0 )
			children[ 2 ]->AddRenderables( frontBotLeftRends, counter );
		if( frontBotRightRends.size() > 0 )
			children[ 3 ]->AddRenderables( frontBotRightRends, counter );

		if( backTopLeftRends.size() > 0 )
			children[ 4 ]->AddRenderables( backTopLeftRends, counter );
		if( backTopRightRends.size() > 0 )
			children[ 5 ]->AddRenderables( backTopRightRends, counter );
		if( backBotLeftRends.size() > 0 )
			children[ 6 ]->AddRenderables( backBotLeftRends, counter );
		if( backBotRightRends.size() > 0 )
			children[ 7 ]->AddRenderables( backBotRightRends, counter );
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

	position.x = x - 1;
	position.y = y - 1;
	position.z = z - 1;
	
	bounds.x = width  + 1 - x;
	bounds.y = height + 1 - y;
	bounds.z = depth  + 1 - z;
}

bool OctNode::Intersection( OctNode *node, kf::Ray ray ) 
{
	// x plane lower and upper points of ray
	double xLower = ( node->position.x - ray.start().x ) / ( ray.end().x - ray.start().x );
	double xUpper = ( node->bounds.x   - ray.start().x ) / ( ray.end().x - ray.start().x );

	// Cut ray between x points
	// if ray is in x plane, lower should be in min, upper should be in max
	double rayCutMin = std::min( xLower, xUpper );
	double rayCutMax = std::max( xLower, xUpper );

	// y plane lower and upper points of ray
	double yLower = ( node->position.y - ray.start().y ) / ( ray.end().y - ray.start().y );
	double yUpper = ( node->bounds.y   - ray.start().y ) / ( ray.end().y - ray.start().y );

	// cut ray between y points
	rayCutMin = std::max( rayCutMin, std::min( yLower, yUpper ) );
	rayCutMax = std::min( rayCutMax, std::max( yLower, yUpper ) );

	// z plane lower and upper points of ray
	double zLower = ( node->position.z - ray.start().z ) / ( ray.end().z - ray.start().z );
	double zUpper = ( node->bounds.z   - ray.start().z ) / ( ray.end().z - ray.start().z );

	// cut ray between z points
	rayCutMin = std::max( rayCutMin, std::min( zLower, zUpper ) );
	rayCutMax = std::min( rayCutMax, std::max( zLower, zUpper ) );

	// Return true if max ray point is bigger than the min ray point
	return rayCutMax >= rayCutMin;
}

std::vector<Renderable*> OctNode::ChildIntersection( OctNode *node, kf::Ray ray )
{
	// If child node is leaf node
	if( node->isLeafNode )
	{
		//// Add all child node's rends to search list
		//for( int numRend = 0; numRend < node->rends.size(); ++numRend )
		//{
		//	nodesToSearch.push_back( node->rends[numRend] );
		//}
		return node->rends;
	}

	std::vector<Renderable*> nodesToSearch;

	// For all children in node
	for( int childIndex = 0; childIndex < node->children.size(); ++childIndex )
	{
		// If ray intersects current child node
		if( Intersection( node->children[childIndex], ray ) )
		{
			// If child node is leaf node
			if( node->children[childIndex]->isLeafNode )
			{
				// Add all child node's rends to search list
				for( int numRend = 0; numRend < node->children[childIndex]->rends.size(); ++numRend )
				{
					nodesToSearch.push_back( node->children[childIndex]->rends[numRend] );
				}
			}
			// If not a leaf node
			else
			{
				std::vector<Renderable*> tempList;

				// Search all child nodes children
				tempList = ChildIntersection( node->children[childIndex], ray );

				// If temp list isnt empty
				if( tempList.size() > 0 )
				{
					// Add all temp list nodes to nodesToSearch
					for( int tempIndex = 0; tempIndex < tempList.size(); ++tempIndex )
					{
						nodesToSearch.push_back( tempList[tempIndex] );
					}
				}
			}
		}
	}
	return nodesToSearch;
}
